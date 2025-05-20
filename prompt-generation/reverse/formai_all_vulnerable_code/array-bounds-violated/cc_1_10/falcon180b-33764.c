//Falcon-180B DATASET v1.0 Category: Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 10

// Define the game characters
#define PLAYER '@'
#define ENEMY 'X'
#define EMPTY '.'
#define WALL '#'

void generateBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    // Initialize the board with walls
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = WALL;
        }
    }

    // Place the player and enemy on the board
    board[0][0] = PLAYER;
    board[BOARD_SIZE - 1][BOARD_SIZE - 1] = ENEMY;
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE];

    generateBoard(board);
    printBoard(board);

    int playerRow = 0;
    int playerCol = 0;
    int enemyRow = BOARD_SIZE - 1;
    int enemyCol = BOARD_SIZE - 1;

    while (playerRow!= enemyRow || playerCol!= enemyCol) {
        printf("Enter your move (row col): ");
        scanf("%d %d", &playerRow, &playerCol);

        if (board[playerRow][playerCol] == WALL) {
            printf("You hit a wall!\n");
        } else {
            board[playerRow][playerCol] = PLAYER;
            playerRow = playerRow < enemyRow? playerRow + 1 : playerRow;
            playerCol = playerCol < enemyCol? playerCol + 1 : playerCol;
        }

        if (playerRow == enemyRow && playerCol == enemyCol) {
            printf("You won!\n");
            break;
        }

        int enemyRowDiff = abs(playerRow - enemyRow);
        int enemyColDiff = abs(playerCol - enemyCol);

        if (enemyRowDiff == enemyColDiff) {
            if ((enemyRowDiff & 1) == 0) {
                enemyRow--;
                enemyCol--;
            } else {
                enemyRow++;
                enemyCol++;
            }
        } else if (enemyRowDiff > enemyColDiff) {
            enemyRow--;
        } else {
            enemyCol--;
        }

        board[enemyRow][enemyCol] = ENEMY;
        printBoard(board);
    }

    return 0;
}