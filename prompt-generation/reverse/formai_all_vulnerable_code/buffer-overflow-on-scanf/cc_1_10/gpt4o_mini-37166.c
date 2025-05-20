//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'
#define SIZE 3

// Function to display the game board
void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check for a win
char checkWin(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return EMPTY;
}

// Function to check if the board is full
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY)
                return 0;
        }
    }
    return 1;
}

// AI's random move
void aiRandomMove(char board[SIZE][SIZE]) {
    int moveMade = 0;
    while (!moveMade) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (board[row][col] == EMPTY) {
            board[row][col] = AI;
            moveMade = 1;
        }
    }
}

// AI's simple heuristic move
void aiHeuristicMove(char board[SIZE][SIZE]) {
    // Check if AI can win in the next move
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI;
                if (checkWin(board) == AI) {
                    return;
                }
                board[i][j] = EMPTY;
            }
        }
    }

    // Check if player can win in the next move and block
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER;
                if (checkWin(board) == PLAYER) {
                    board[i][j] = AI;
                    return;
                }
                board[i][j] = EMPTY;
            }
        }
    }

    // Make a random move if no immediate threats or opportunities
    aiRandomMove(board);
}

// Main game loop
void playGame(int aiDifficulty) {
    char board[SIZE][SIZE] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    char winner = EMPTY;
    int turn = 0;

    while (winner == EMPTY && !isBoardFull(board)) {
        displayBoard(board);
        if (turn % 2 == 0) {
            int row, col;
            printf("Player X, enter your move (row and column): ");
            scanf("%d %d", &row, &col);
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
                board[row][col] = PLAYER;
            } else {
                printf("Invalid move! Try again.\n");
                continue;
            }
        } else {
            printf("AI is making a move...\n");
            if (aiDifficulty == 1) {
                aiRandomMove(board);
            } else {
                aiHeuristicMove(board);
            }
        }
        winner = checkWin(board);
        turn++;
    }

    displayBoard(board);
    if (winner == PLAYER) {
        printf("Player X wins!\n");
    } else if (winner == AI) {
        printf("AI O wins!\n");
    } else {
        printf("It's a draw!\n");
    }
}

int main() {
    srand(time(NULL));
    int aiDifficulty;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose AI difficulty (1 for Random, 2 for Heuristic): ");
    scanf("%d", &aiDifficulty);

    if (aiDifficulty < 1 || aiDifficulty > 2) {
        printf("Invalid difficulty level! Exiting...\n");
        return 1;
    }

    playGame(aiDifficulty);
    return 0;
}