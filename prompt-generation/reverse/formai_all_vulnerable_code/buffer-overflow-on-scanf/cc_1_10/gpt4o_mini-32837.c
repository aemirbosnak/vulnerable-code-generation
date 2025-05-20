//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

char board[SIZE][SIZE];
int gameOver = 0;

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void* aiMove(void* arg) {
    while (!gameOver) {
        sleep(1); // Simulate thinking time
        int row, col;
        while (1) {
            row = rand() % SIZE;
            col = rand() % SIZE;
            if (board[row][col] == EMPTY) {
                board[row][col] = AI;
                printf("AI placed %c at (%d, %d)\n", AI, row, col);
                break;
            }
        }

        printBoard();
        
        if (checkWin(AI)) {
            printf("AI (O) wins!\n");
            gameOver = 1;
            return NULL;
        }
        
        if (checkDraw()) {
            printf("It's a draw!\n");
            gameOver = 1;
            return NULL;
        }
    }
    return NULL;
}

void playerMove() {
    int row, col;
    while (1) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    initializeBoard();
    printBoard();

    pthread_t aiThread;
    pthread_create(&aiThread, NULL, aiMove, NULL);
    
    while (!gameOver) {
        playerMove();
        printBoard();

        if (checkWin(PLAYER)) {
            printf("Player (X) wins!\n");
            gameOver = 1;
            break;
        }

        if (checkDraw()) {
            printf("It's a draw!\n");
            gameOver = 1;
            break;
        }
    }

    pthread_cancel(aiThread);
    pthread_join(aiThread, NULL);

    return 0;
}