//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define N 3
#define M 3

char buf[N][M];
char const *x = "+-+";
static int n;

void
show(void)
{
	int i, j;

	for (i = n; i >= 1; i--) {
		printf(x);
		for (j = 0; j < M; j++)
			printf(buf[i - 1][j]);
		printf("\n");
	}
	printf(x);
	printf(x);
	printf(x);
	printf("\n");
}

int
move(int a, int b)
{
	if (a < 1 || a > 3 || b < 1 || b > 3)
		return -1;

	while (1) {
		if (buf[0][b - 1] == ' ') {
			buf[0][b - 1] = buf[0][a - 1];
			buf[0][a - 1] = ' ';
			show();
			return 0;
		}
		if (buf[1][a - 1] == ' ') {
			buf[1][a - 1] = buf[1][b - 1];
			buf[1][b - 1] = ' ';
			show();
			return 0;
		}
		if (buf[n - 1][a - 1] == ' ') {
			buf[n - 1][a - 1] = buf[n - 1][b - 1];
			buf[n - 1][b - 1] = ' ';
			show();
			return 0;
		}
		if (buf[2][b - 1] == ' ') {
			buf[2][b - 1] = buf[2][a - 1];
			buf[2][a - 1] = ' ';
			show();
			return 0;
		}
	}
}

int
main(void)
{
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			buf[i][j] = ' ';

	i = (n = 3) + 1;
	for (j = M - 1; j >= 0; j--) {
		buf[i - 1][j] = i - j;
		i--;
	}

	for (i = 0; i < 15; i++) {
		int to_move, to, from;

		to_move = buf[1][0] + buf[1][1] + buf[1][2] - 1;
		switch (to_move) {
		case 0:
		case 1:
			from = 1;
			break;
		case 2:
		case 3:
			from = 2;
			break;
		case 4:
		case 5:
			from = 3;
			break;
		default:
			printf("bad array?");
			return -1;
		}

		to = n - to_move;
		if (move(from, to) < 0)
			break;
	}

	return 0;
}