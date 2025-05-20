//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWinner(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE]);
void aiMove(char board[SIZE][SIZE]);
int isBoardFull(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    int winner = 0; // 0 means no winner yet

    printf("Welcome to Tic Tac Toe!\n");
    printf("You are 'X' and the AI is 'O'.\n");

    initializeBoard(board);

    while (winner == 0 && !isBoardFull(board)) {
        printBoard(board);
        playerMove(board);
        winner = checkWinner(board);

        if (winner != 0 || isBoardFull(board)) {
            break; 
        }

        aiMove(board);
        winner = checkWinner(board);
    }

    printBoard(board);
    
    if (winner == 1) {
        printf("Congratulations! You won!\n");
    } else if (winner == -1) {
        printf("AI wins! Better luck next time!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---|---|---\n");
    }

    printf("\n");
}

int checkWinner(char board[SIZE][SIZE]) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : -1;
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return (board[0][j] == 'X') ? 1 : -1;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? 1 : -1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == 'X') ? 1 : -1;
    }

    return 0; // No winner yet
}

void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    while (1) {
        printf("Enter your move (row and column as 'row col'): ");
        scanf("%d %d", &row, &col);
        
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = 'X';
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiMove(char board[SIZE][SIZE]) {
    int row, col;
    srand(time(0));
    
    while (1) {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if (board[row][col] == ' ') {
            board[row][col] = 'O';
            printf("AI plays at position (%d, %d).\n", row, col);
            break;
        }
    }
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board not full
            }
        }
    }
    return 1; // Board is full
}