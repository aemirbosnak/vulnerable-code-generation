//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: creative
// C Checkers Game by @CodingHours

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define RED 1
#define BLACK 2

char board[BOARD_SIZE][BOARD_SIZE];
bool gameOver;
int turn;

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = ' ';
            } else if (i < 3) {
                board[i][j] = RED;
            } else if (i > 4) {
                board[i][j] = BLACK;
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void printBoard() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool validMove(int fromRow, int fromCol, int toRow, int toCol) {
    if (board[fromRow][fromCol] == ' ') {
        return false;
    }
    if (turn == RED) {
        if (board[fromRow][fromCol] == RED) {
            if (toRow == fromRow - 1 && (toCol == fromCol - 1 || toCol == fromCol + 1)) {
                return true;
            } else if (toRow == fromRow - 2 && toCol == fromCol - 2 && board[toRow - 1][toCol + 1] == BLACK) {
                return true;
            } else if (toRow == fromRow - 2 && toCol == fromCol + 2 && board[toRow - 1][toCol - 1] == BLACK) {
                return true;
            }
        } else if (board[fromRow][fromCol] == RED + 1) {
            if (toRow == fromRow - 1 && (toCol == fromCol - 1 || toCol == fromCol + 1)) {
                return true;
            } else if (toRow == fromRow - 2 && toCol == fromCol - 2 && board[toRow - 1][toCol + 1] == BLACK) {
                return true;
            } else if (toRow == fromRow - 2 && toCol == fromCol + 2 && board[toRow - 1][toCol - 1] == BLACK) {
                return true;
            } else if (toRow == fromRow + 1 && (toCol == fromCol - 1 || toCol == fromCol + 1)) {
                return true;
            } else if (toRow == fromRow + 2 && toCol == fromCol - 2 && board[toRow - 1][toCol + 1] == BLACK) {
                return true;
            } else if (toRow == fromRow + 2 && toCol == fromCol + 2 && board[toRow - 1][toCol - 1] == BLACK) {
                return true;
            }
        }
    } else if (turn == BLACK) {
        if (board[fromRow][fromCol] == BLACK) {
            if (toRow == fromRow + 1 && (toCol == fromCol - 1 || toCol == fromCol + 1)) {
                return true;
            } else if (toRow == fromRow + 2 && toCol == fromCol - 2 && board[toRow - 1][toCol + 1] == RED) {
                return true;
            } else if (toRow == fromRow + 2 && toCol == fromCol + 2 && board[toRow - 1][toCol - 1] == RED) {
                return true;
            }
        } else if (board[fromRow][fromCol] == BLACK + 1) {
            if (toRow == fromRow + 1 && (toCol == fromCol - 1 || toCol == fromCol + 1)) {
                return true;
            } else if (toRow == fromRow + 2 && toCol == fromCol - 2 && board[toRow - 1][toCol + 1] == RED) {
                return true;
            } else if (toRow == fromRow + 2 && toCol == fromCol + 2 && board[toRow - 1][toCol - 1] == RED) {
                return true;
            } else if (toRow == fromRow - 1 && (toCol == fromCol - 1 || toCol == fromCol + 1)) {
                return true;
            } else if (toRow == fromRow - 2 && toCol == fromCol - 2 && board[toRow + 1][toCol + 1] == RED) {
                return true;
            } else if (toRow == fromRow - 2 && toCol == fromCol + 2 && board[toRow + 1][toCol - 1] == RED) {
                return true;
            }
        }
    }
    return false;
}

bool makeMove(int fromRow, int fromCol, int toRow, int toCol) {
    if (!validMove(fromRow, fromCol, toRow, toCol)) {
        return false;
    }
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';
    if (abs(toRow - fromRow) == 2) {
        board[(toRow + fromRow) / 2][(toCol + fromCol) / 2] = ' ';
    }
    if (toRow == 0 || toRow == BOARD_SIZE - 1) {
        board[toRow][toCol] += 1;
    }
    turn = 3 - turn;
    return true;
}

bool isGameOver() {
    bool redCanMove = false;
    bool blackCanMove = false;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == RED || board[i][j] == RED + 1) {
                if (validMove(i, j, i - 1, j - 1) || validMove(i, j, i - 1, j + 1)) {
                    redCanMove = true;
                }
            } else if (board[i][j] == BLACK || board[i][j] == BLACK + 1) {
                if (validMove(i, j, i + 1, j - 1) || validMove(i, j, i + 1, j + 1)) {
                    blackCanMove = true;
                }
            }
        }
    }
    return !redCanMove && !blackCanMove;
}

int main() {
    initBoard();
    printBoard();
    while (!gameOver) {
        int fromRow, fromCol, toRow, toCol;
        printf("Enter your move (fromRow fromCol toRow toCol): ");
        scanf("%d %d %d %d", &fromRow, &fromCol, &toRow, &toCol);
        fromRow--;
        fromCol--;
        toRow--;
        toCol--;
        if (makeMove(fromRow, fromCol, toRow, toCol)) {
            printBoard();
        } else {
            printf("Invalid move!\n");
        }
        gameOver = isGameOver();
    }
    if (turn == RED) {
        printf("Black wins!\n");
    } else {
        printf("Red wins!\n");
    }
    return 0;
}