//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

char board[SIZE][SIZE];

void initializeBoard() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    printf("\nCurrent Board State:\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if(j < SIZE - 1) printf("|");
        }
        printf("\n");
        if(i < SIZE - 1) {
            printf("-----\n");
        }
    }
    printf("\n");
}

int checkWin(char player) {
    for(int i = 0; i < SIZE; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1; // Row check
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1; // Column check
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1; // Diagonal check
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1; // Other diagonal check

    return 0;
}

int checkDraw() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == EMPTY) return 0; // If there's an empty cell, the game's not a draw yet
        }
    }
    return 1; // No empty cells left
}

void playerMove() {
    int row, col;
    while(1) {
        printf("Enter your move (row and column) [0-2]: ");
        scanf("%d %d", &row, &col);
        if(row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void aiMove() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == EMPTY) {
                board[i][j] = AI;
                if(checkWin(AI)) return;
                board[i][j] = EMPTY; // Reset after checking
            }
        }
    }

    // If no win is possible, choose a random empty spot
    int placed = 0;
    while(!placed) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if(board[row][col] == EMPTY) {
            board[row][col] = AI;
            placed = 1;
        }
    }
}

int main() {
    srand(time(NULL));
    initializeBoard();
    printBoard();

    while(1) {
        playerMove();
        printBoard();
        if(checkWin(PLAYER)) {
            printf("Congratulations! You win!\n");
            break;
        }
        if(checkDraw()) {
            printf("It's a draw!\n");
            break;
        }

        aiMove();
        printBoard();
        if(checkWin(AI)) {
            printf("AI wins! Better luck next time.\n");
            break;
        }
        if(checkDraw()) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}