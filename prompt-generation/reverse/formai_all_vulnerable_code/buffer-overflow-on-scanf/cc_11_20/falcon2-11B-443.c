//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

// global variables
char board[8][8] = {
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}
};

int currentPlayer = 1;
int turn = 0;
int winner = 0;
int moveMade = 0;
int moves = 0;

void printBoard() {
	printf("  a b c d e f g h \n");
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%c", board[i][j] + 'a');
		}
		printf("\n");
	}
}

void makeMove(int moveX, int moveY) {
	int currentMove[2] = {moveX, moveY};
	if (board[moveX][moveY]!= 0) {
		printf("Move not valid, try again!\n");
		return;
	}
	board[moveX][moveY] = currentPlayer;
	moves++;
	currentPlayer = 3 - currentPlayer;
	turn++;
	if (turn == 8) {
		turn = 0;
		winner = checkWinner();
	}
}

int checkWinner() {
	int winners = 0;
	for (int i = 0; i < 8; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][4] == board[i][5] && board[i][5] == board[i][6] && board[i][6] == board[i][7] && board[i][7] == board[i][0]) {
			winners++;
		}
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i] && board[4][i] == board[5][i] && board[5][i] == board[6][i] && board[6][i] == board[7][i] && board[7][i] == board[0][i]) {
			winners++;
		}
		else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[4][4] == board[5][5] && board[5][5] == board[6][6] && board[6][6] == board[7][7] && board[7][7] == board[0][0]) {
			winners++;
		}
		else if (board[0][7] == board[1][6] && board[1][6] == board[2][5] && board[2][5] == board[3][4] && board[3][4] == board[4][3] && board[4][3] == board[5][2] && board[5][2] == board[6][1] && board[6][1] == board[7][0] && board[7][0] == board[0][7]) {
			winners++;
		}
	}
	if (winners == 1) {
		return currentPlayer;
	}
	else {
		return 0;
	}
}

int main() {
	int move;
	int validMoves = 0;
	srand(time(NULL));
	while (winner == 0) {
		printBoard();
		if (currentPlayer == 1) {
			printf("Player 1's turn!\n");
			scanf("%d", &move);
			if (move >= 1 && move <= 8) {
				makeMove(move, 0);
				validMoves++;
			}
		}
		else if (currentPlayer == 2) {
			printf("Player 2's turn!\n");
			scanf("%d", &move);
			if (move >= 1 && move <= 8) {
				makeMove(move, 7);
				validMoves++;
			}
		}
	}
	printf("Game Over!\n");
	printf("Player %d wins!\n", winner);
	printf("Valid moves: %d\n", validMoves);
	return 0;
}