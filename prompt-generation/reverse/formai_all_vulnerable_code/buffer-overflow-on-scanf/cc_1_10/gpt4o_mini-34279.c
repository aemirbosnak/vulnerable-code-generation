//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'
#define SIZE 3

char board[SIZE][SIZE];
int movesAvailable;

void initializeBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = EMPTY;

    movesAvailable = SIZE * SIZE;
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

int checkWin(char mark) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark))
            return 1;
    }
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
        return 1;

    return 0;
}

void playerMove() {
    int row, col;
    printf("In the realm of choices, place your mark (X) - row and column (0, 1, or 2): ");
    scanf("%d %d", &row, &col);

    while (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != EMPTY) {
        printf("The universe denies that position. Choose again: ");
        scanf("%d %d", &row, &col);
    }
    
    board[row][col] = PLAYER;
    movesAvailable--;
}

void aiMove() {
    int row, col;
    if (rand() % 2) {
        // Option for surreal randomness
        row = rand() % SIZE;
        col = rand() % SIZE;
    } else {
        // If can't win, find block
        for (row = 0; row < SIZE; row++) {
            for (col = 0; col < SIZE; col++) {
                if (board[row][col] == EMPTY) {
                    board[row][col] = AI;
                    if (checkWin(AI)) {
                        return; // win
                    } else {
                        board[row][col] = EMPTY; // revert
                    }
                }
            }
        }

        // Else find any empty position
        do {
            row = rand() % SIZE;
            col = rand() % SIZE;
        } while (board[row][col] != EMPTY);
    }
    
    board[row][col] = AI;
    printf("The void has placed its mark (O) at: %d, %d\n", row, col);
    movesAvailable--;
}

void printOutcome(int winner) {
    if (winner == 0) {
        printf("The stars align, but no one wins this time...\n");
    } else if (winner == 1) {
        printf("Alas! The Human Spirit (X) triumphs over the ashes of defeat!\n");
    } else {
        printf("A cosmic twist! The Mechanical Majesty (O) claims victory amidst the chaos!\n");
    }
}

int main() {
    srand(time(NULL));
    initializeBoard();
    
    displayBoard();
    
    int winner;
    while (movesAvailable > 0) {
        playerMove();
        displayBoard();
        if (checkWin(PLAYER)) {
            winner = 1;
            break;
        }

        if (movesAvailable == 0) {
            winner = 0; // Draw
            break;
        }
        
        aiMove();
        displayBoard();
        if (checkWin(AI)) {
            winner = -1;
            break;
        }
    }
    
    printOutcome(winner);
    return 0;
}