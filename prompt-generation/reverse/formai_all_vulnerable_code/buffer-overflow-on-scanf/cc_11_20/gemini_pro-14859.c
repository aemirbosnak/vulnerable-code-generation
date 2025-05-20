//GEMINI-pro DATASET v1.0 Category: Chess AI ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

char board[8][8];
int player;

void initBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = ' ';
		}
	}
	board[0][0] = board[0][7] = 'r';
	board[0][1] = board[0][6] = 'n';
	board[0][2] = board[0][5] = 'b';
	board[0][3] = 'q';
	board[0][4] = 'k';
	board[7][0] = board[7][7] = 'R';
	board[7][1] = board[7][6] = 'N';
	board[7][2] = board[7][5] = 'B';
	board[7][3] = 'Q';
	board[7][4] = 'K';
	for (int i = 0; i < 8; i++) {
		board[1][i] = board[6][i] = 'p';
	}
}

void printBoard() {
	printf("   a b c d e f g h\n");
	for (int i = 0; i < 8; i++) {
		printf("%d ", 8 - i);
		for (int j = 0; j < 8; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

int isLegalMove(int fromX, int fromY, int toX, int toY) {
	if (fromX < 0 || fromX > 7 || fromY < 0 || fromY > 7 || toX < 0 || toX > 7 || toY < 0 || toY > 7) {
		return 0;
	}
	if (board[fromX][fromY] == ' ' || board[fromX][fromY] == board[toX][toY]) {
		return 0;
	}
	switch (board[fromX][fromY]) {
		case 'p':
			if (player == 1 && toX == fromX - 1 && toY == fromY) {
				return 1;
			}
			if (player == 2 && toX == fromX + 1 && toY == fromY) {
				return 1;
			}
			if (player == 1 && toX == fromX - 2 && toY == fromY && fromX == 6) {
				return 1;
			}
			if (player == 2 && toX == fromX + 2 && toY == fromY && fromX == 1) {
				return 1;
			}
			if (player == 1 && toX == fromX - 1 && (toY == fromY - 1 || toY == fromY + 1) && board[toX][toY] != ' ') {
				return 1;
			}
			if (player == 2 && toX == fromX + 1 && (toY == fromY - 1 || toY == fromY + 1) && board[toX][toY] != ' ') {
				return 1;
			}
			break;
		case 'r':
			if (toX == fromX || toY == fromY) {
				return 1;
			}
			break;
		case 'n':
			if ((abs(toX - fromX) == 2 && abs(toY - fromY) == 1) || (abs(toX - fromX) == 1 && abs(toY - fromY) == 2)) {
				return 1;
			}
			break;
		case 'b':
			if (abs(toX - fromX) == abs(toY - fromY)) {
				return 1;
			}
			break;
		case 'q':
			if (toX == fromX || toY == fromY || abs(toX - fromX) == abs(toY - fromY)) {
				return 1;
			}
			break;
		case 'k':
			if (abs(toX - fromX) <= 1 && abs(toY - fromY) <= 1) {
				return 1;
			}
			break;
	}
	return 0;
}

void makeMove(int fromX, int fromY, int toX, int toY) {
	board[toX][toY] = board[fromX][fromY];
	board[fromX][fromY] = ' ';
}

int main() {
	initBoard();
	printBoard();
	while (1) {
		int fromX, fromY, toX, toY;
		if (player == 1) {
			printf("White's move: ");
		}
		else {
			printf("Black's move: ");
		}
		scanf("%d %d %d %d", &fromX, &fromY, &toX, &toY);
		if (isLegalMove(fromX, fromY, toX, toY)) {
			makeMove(fromX, fromY, toX, toY);
			printBoard();
			player = 3 - player;
		}
		else {
			printf("Illegal move!\n");
		}
	}
	return 0;
}