//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE_SYMBOL 'T'
#define EMPTY_SYMBOL '.'

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY_SYMBOL;
        }
    }
}

void placeTreasure(char board[SIZE][SIZE]) {
    int row = rand() % SIZE;
    int col = rand() % SIZE;
    board[row][col] = TREASURE_SYMBOL;
}

void printBoard(char board[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int getPlayerMove(int* row, int* col) {
    printf("Enter your move (row and column): ");
    if (scanf("%d%d", row, col) != 2) {
        printf("Invalid input! Please enter integers.\n");
        return 0;
    }
    return 1;
}

void treasureHuntGame() {
    char board[SIZE][SIZE];
    int moves = 0;
    int treasureFound = 0;

    initializeBoard(board);
    placeTreasure(board);

    printf("Welcome to the Treasure Hunt Game!\n");

    while (!treasureFound) {
        printBoard(board);

        int row = -1, col = -1;
        while (1) {
            if (getPlayerMove(&row, &col) && row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
                break;
            }
            printf("Please enter valid coordinates between 0 and %d.\n", SIZE - 1);
        }

        moves++;
        if (board[row][col] == TREASURE_SYMBOL) {
            treasureFound = 1;
            printf("Congratulations! You've found the treasure in %d moves!\n", moves);
        } else {
            printf("No treasure here... Try again!\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    treasureHuntGame();
    return 0;
}