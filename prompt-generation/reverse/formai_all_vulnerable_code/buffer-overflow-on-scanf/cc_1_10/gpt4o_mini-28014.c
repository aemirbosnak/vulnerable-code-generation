//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

char board[SIZE][SIZE];

// Function prototypes
void initializeBoard();
void printBoard();
int checkWin(char player);
int isBoardFull();
void playerMove();
void aiMove();
int randomMove();

int main() {
    int gameOver = 0;

    initializeBoard();

    printf("Welcome to Tic Tac Toe!\n");
    printBoard();

    while (!gameOver) {
        playerMove();
        printBoard();
        if (checkWin(PLAYER)) {
            printf("Congratulations! You win!\n");
            break;
        }

        if (isBoardFull()) {
            printf("The game is a tie!\n");
            break;
        }

        aiMove();
        printBoard();
        if (checkWin(AI)) {
            printf("AI wins! Better luck next time.\n");
            break;
        }

        if (isBoardFull()) {
            printf("The game is a tie!\n");
            break;
        }
    }

    return 0;
}

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    system("clear");
    printf(" Tic Tac Toe \n");
    printf("  0 1 2\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("  -----\n");
        }
    }
}

int checkWin(char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void playerMove() {
    int row, col;
    while (1) {
        printf("Your move! Enter row and column (0, 1, or 2): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiMove() {
    printf("AI is making a move...\n");
    if (!randomMove()) {
        // Fall back on random move if no winning/blocking moves found
        while (1) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            if (board[row][col] == EMPTY) {
                board[row][col] = AI;
                break;
            }
        }
    }
}

int randomMove() {
    // Check for winning move
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI;
                if (checkWin(AI)) {
                    return 1; // Found a winning move
                }
                board[i][j] = EMPTY; // Undo move
            }
        }
    }
    
    // Check for blocking move
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER;
                if (checkWin(PLAYER)) {
                    board[i][j] = AI; // Block the player
                    return 1;
                }
                board[i][j] = EMPTY; // Undo move
            }
        }
    }
    
    return 0; // No immediate winning/blocking move found
}