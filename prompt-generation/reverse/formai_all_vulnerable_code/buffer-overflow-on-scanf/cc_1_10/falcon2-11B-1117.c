//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_1 1
#define PLAYER_2 2

// Function to print the board
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is empty or not
int isEmpty(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    return board[row][col] == 0;
}

// Function to check if a player has won the game
int checkWin(int board[BOARD_SIZE][BOARD_SIZE], int player) {
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == player) {
        return 1;
    }
    if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == player) {
        return 1;
    }
    if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == player) {
        return 1;
    }
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == player) {
        return 1;
    }
    if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == player) {
        return 1;
    }
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == player) {
        return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == player) {
        return 1;
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full
int isFull(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (isEmpty(board, i, j)) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to get a random number between 1 and 2
int getRandomPlayer(int board[BOARD_SIZE][BOARD_SIZE]) {
    srand(time(NULL));
    int randomPlayer = rand() % 2;
    if (randomPlayer == 0) {
        return PLAYER_1;
    } else {
        return PLAYER_2;
    }
}

// Function to make a move
void makeMove(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int player) {
    board[row][col] = player;
}

// Function to get the AI's move
int getAIMove(int board[BOARD_SIZE][BOARD_SIZE], int player) {
    int row, col;
    int bestMove = 0;

    // Check if the board is full
    if (isFull(board)) {
        return 0;
    }

    // Check if the player has won the game
    if (checkWin(board, player)) {
        return 0;
    }

    // Check if the AI can win in the next move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (isEmpty(board, i, j)) {
                makeMove(board, i, j, player);
                if (checkWin(board, 3 - player)) {
                    bestMove = i * BOARD_SIZE + j;
                    break;
                }
                makeMove(board, i, j, 0);
            }
        }
    }

    // Check if the AI can force a draw
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (isEmpty(board, i, j)) {
                makeMove(board, i, j, player);
                if (isFull(board)) {
                    bestMove = i * BOARD_SIZE + j;
                    break;
                }
                makeMove(board, i, j, 0);
            }
        }
    }

    return bestMove;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = getRandomPlayer(board);
    int aiMove = getAIMove(board, 3 - player);

    while (1) {
        printBoard(board);
        printf("Player %d, enter your move (row, col): ", player);
        scanf("%d %d", &board[0][0], &board[1][0]);
        player = 3 - player;
        if (checkWin(board, player)) {
            printf("%d wins!\n", player);
            break;
        }
        if (isFull(board)) {
            printf("Draw!\n");
            break;
        }
        aiMove = getAIMove(board, 3 - player);
        makeMove(board, aiMove / BOARD_SIZE, aiMove % BOARD_SIZE, 3 - player);
    }
    return 0;
}