//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the game board initial state
void initBoard() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

// Define the game board printing function
void printBoard() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Define the game board checking function
int checkBoard() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

// Define the game board updating function
void updateBoard(int x, int y) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(i == x && j == y) {
                board[i][j] = 'X';
            }
        }
    }
}

// Define the game loop
void gameLoop() {
    int playerX, playerY, enemyX, enemyY;
    int gameOver = 0;
    initBoard();
    while(!gameOver) {
        printBoard();
        printf("Enter your move (row and column): ");
        scanf("%d%d", &playerX, &playerY);
        updateBoard(playerX, playerY);
        if(checkBoard()) {
            printf("You win!\n");
            gameOver = 1;
        }
        else {
            srand(time(NULL));
            enemyX = rand() % BOARD_SIZE;
            enemyY = rand() % BOARD_SIZE;
            while(board[enemyX][enemyY]!= '.') {
                enemyX = rand() % BOARD_SIZE;
                enemyY = rand() % BOARD_SIZE;
            }
            updateBoard(enemyX, enemyY);
            if(checkBoard()) {
                printf("You lose!\n");
                gameOver = 1;
            }
        }
    }
}

// Define the main function
int main() {
    gameLoop();
    return 0;
}