//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

void drawBoard(char board[SIZE][SIZE]);
bool checkWin(char board[SIZE][SIZE], char player);
bool checkDraw(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], char player);
void aiMove(char board[SIZE][SIZE], char player);
int minimax(char board[SIZE][SIZE], int depth, bool isMaximizing);
int bestMove(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player = 'X';
    bool isAIEnabled = false;

    printf("Welcome to Tic Tac Toe!\nChoose game mode:\n1. Two Players\n2. Player vs AI\nEnter your choice (1 or 2): ");
    int choice;
    scanf("%d", &choice);
    if (choice == 2) {
        isAIEnabled = true;
    }

    while (true) {
        drawBoard(board);
        if (isAIEnabled && player == 'O') {
            aiMove(board, player);
        } else {
            playerMove(board, player);
        }

        if (checkWin(board, player)) {
            drawBoard(board);
            printf("Player '%c' wins!\n", player);
            break;
        }

        if (checkDraw(board)) {
            drawBoard(board);
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

void drawBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

bool checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playerMove(char board[SIZE][SIZE], char player) {
    int row, col;
    while (true) {
        printf("Player '%c', enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void aiMove(char board[SIZE][SIZE], char player) {
    int move = bestMove(board);
    board[move / SIZE][move % SIZE] = player;
    printf("AI plays at position: %d\n", move + 1);
}

int minimax(char board[SIZE][SIZE], int depth, bool isMaximizing) {
    if (checkWin(board, 'X')) return -10;
    if (checkWin(board, 'O')) return 10;
    if (checkDraw(board)) return 0;

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(board, depth + 1, false);
                    board[i][j] = ' ';
                    bestScore = (score > bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(board, depth + 1, true);
                    board[i][j] = ' ';
                    bestScore = (score < bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    }
}

int bestMove(char board[SIZE][SIZE]) {
    int bestValue = -1000;
    int move = -1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int moveValue = minimax(board, 0, false);
                board[i][j] = ' ';
                if (moveValue > bestValue) {
                    move = i * SIZE + j;
                    bestValue = moveValue;
                }
            }
        }
    }
    return move;
}