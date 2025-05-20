//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define EMPTY ' '

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWinner(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE]);
void aiMove(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    int winner = 0;

    initializeBoard(board);

    printf("Welcome to Tic Tac Toe!\n");
    printf("You are 'X' and AI is 'O'.\n\n");

    while (winner == 0) {
        printBoard(board);
        playerMove(board);
        winner = checkWinner(board);
        if (winner != 0) break;

        aiMove(board);
        winner = checkWinner(board);
    }

    printBoard(board);

    if (winner == 1) {
        printf("Congratulations! You win!\n");
    } else if (winner == 2) {
        printf("AI wins! Better luck next time.\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int checkWinner(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        // Check rows and columns
        if (board[i][0] != EMPTY && 
            board[i][0] == board[i][1] && 
            board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : 2;
        }
        if (board[0][i] != EMPTY && 
            board[0][i] == board[1][i] && 
            board[1][i] == board[2][i]) {
            return (board[0][i] == 'X') ? 1 : 2;
        }
    }

    // Check diagonals
    if (board[0][0] != EMPTY && 
        board[0][0] == board[1][1] && 
        board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2] != EMPTY && 
        board[0][2] == board[1][1] && 
        board[1][1] == board[2][0]) {
        return (board[0][2] == 'X') ? 1 : 2;
    }

    // Check for draw
    int emptyCount = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                emptyCount++;
            }
        }
    }
    if (emptyCount == 0) {
        return -1;  // Draw
    }

    return 0;  // Game continues
}

void playerMove(char board[SIZE][SIZE]) {
    int row, col;

    while (1) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = 'X';
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void aiMove(char board[SIZE][SIZE]) {
    srand(time(NULL));
    int row, col;

    while (1) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (board[row][col] == EMPTY) {
            board[row][col] = 'O';
            break;
        }
    }
}