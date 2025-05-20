//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50
#define NEIGHBOURS 8

int board[SIZE][SIZE];
int neighbours[NEIGHBOURS][NEIGHBOURS];

// Function to initialize the board with random values
void initBoard() {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the board
void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to count the number of living neighbours
int countNeighbours(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0)
                continue;
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
                count += board[nx][ny];
            }
        }
    }
    return count;
}

// Function to update the board
void updateBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int count = countNeighbours(i, j);
            if (board[i][j] == 1 && count < 2) {
                board[i][j] = 0;
            } else if (board[i][j] == 0 && count == 3) {
                board[i][j] = 1;
            }
        }
    }
}

// Function to run the game for a certain number of generations
void runGame(int generations) {
    initBoard();
    for (int i = 0; i < generations; i++) {
        printBoard();
        updateBoard();
    }
}

int main() {
    int generations;
    printf("Enter the number of generations to run the game: ");
    scanf("%d", &generations);
    runGame(generations);
    return 0;
}