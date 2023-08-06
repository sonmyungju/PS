#include <iostream>
#include <cstring>
using namespace std;

int N, M;
char MAP[100][100];

void gravity(int col) {
	int bottom = N - 1;
	for (int i = N - 1; i >= 0; i--) {
		char now = MAP[i][col];

		if (now == '#') bottom = i - 1;
		else if (now == 'o') {
			MAP[i][col] = '.';
			MAP[bottom][col] = 'o';
			bottom--;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		gravity(i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << MAP[i][j];
		}
		cout << '\n';
	}
	return 0;
}