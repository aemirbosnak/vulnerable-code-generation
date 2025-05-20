//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include<stdio.h>
#include<stdlib.h>

char board[3][3];
char player1 = 'X';
char player2 = 'O';

void initBoard();
void printBoard();
int validMove(int x, int y);
int checkWin(char ch);

int main() {
	initBoard();
	int currentPlayer = 1, row, col;
	
	do {
		printBoard();
		if(currentPlayer == 1) {
			printf("Player 1 (X), make your move: ");
			scanf("%d %d", &row, &col);
			
			if(validMove(row, col)) {
				board[row][col] = player1;
				currentPlayer = 2;
			} else {
				printf("Invalid move, try again.\n");
			}
		} else {
			printf("Player 2 (O), make your move: ");
			scanf("%d %d", &row, &col);
			
			if(validMove(row, col)) {
				board[row][col] = player2;
				currentPlayer = 1;
			} else {
				printf("Invalid move, try again.\n");
			}
		}
		
	} while(checkWin(player1) == 0 && checkWin(player2) == 0);
	
	printBoard();
	
	if(checkWin(player1) == 1) {
		printf("Player 1 (X) wins! Congratulations!\n");
	} else if(checkWin(player2) == 1) {
		printf("Player 2 (O) wins! Congratulations!\n");
	} else {
		printf("It's a tie! Try again.\n");
	}
	
	return 0;
}

void initBoard() {  // Initialize the board with empty spaces
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void printBoard() {  // Print the current state of the board
	int i, j;
	for(i = 0; i < 3; i++) {
		printf("|");
		for(j = 0; j < 3; j++) {
			printf(" %c |", board[i][j]);
		}
		printf("\n");
	}
}

int validMove(int x, int y) {  // Check if the move is valid or not
	if(x < 0 || x > 2 || y < 0 || y > 2) {
		return 0;
	} else if(board[x][y] != ' ') {
		return 0;
	} else {
		return 1;
	}
}

int checkWin(char ch) {  // Check if the game has been won by either player or not
	int i, j;
	
	// Check rows
	for(i = 0; i < 3; i++) {
		if(board[i][0] == ch && board[i][1] == ch && board[i][2] == ch) {
			return 1;
		}
	}
	
	// Check columns
	for(j = 0; j < 3; j++) {
		if(board[0][j] == ch && board[1][j] == ch && board[2][j] == ch) {
			return 1;
		}
	}
	
	// Check diagonals
	if(board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) {
		return 1;
	}
	
	if(board[2][0] == ch && board[1][1] == ch && board[0][2] == ch) {
		return 1;
	}
	
	return 0;
}