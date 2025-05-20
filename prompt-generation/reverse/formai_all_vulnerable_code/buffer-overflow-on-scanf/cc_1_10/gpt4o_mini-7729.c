//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define NUM_TREASURES 3
#define NUM_OBSTACLES 5

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = '.';
}

void placeTreasures(char board[SIZE][SIZE]) {
    int placed = 0;
    while (placed < NUM_TREASURES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] == '.') {
            board[x][y] = 'T';  // T stands for Treasure
            placed++;
        }
    }
}

void placeObstacles(char board[SIZE][SIZE]) {
    int placed = 0;
    while (placed < NUM_OBSTACLES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] == '.') {
            board[x][y] = 'X';  // X stands for Obstacle
            placed++;
        }
    }
}

void printBoard(char board[SIZE][SIZE], int playerX, int playerY) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerX && j == playerY) 
                printf("P ");  // P stands for Player
            else 
                printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char board[SIZE][SIZE];
    int playerX = 0, playerY = 0; // Player starts at the top-left corner
    int treasuresFound = 0;

    srand(time(NULL));  // Seed for randomness
    initializeBoard(board);
    placeTreasures(board);
    placeObstacles(board);

    printf("Welcome to Treasure Quest!\n");
    printf("Navigate the grid using W (up), A (left), S (down), D (right).\n");
    printf("Collect all treasures (T) while avoiding obstacles (X).\n");

    char move;
    while (treasuresFound < NUM_TREASURES) {
        printBoard(board, playerX, playerY);
        printf("Treasures Found: %d/%d\n", treasuresFound, NUM_TREASURES);
        printf("Your move (W/A/S/D): ");
        scanf(" %c", &move);

        int newX = playerX, newY = playerY;

        switch(move) {
            case 'w': case 'W':
                newX--;
                break;
            case 's': case 'S':
                newX++;
                break;
            case 'a': case 'A':
                newY--;
                break;
            case 'd': case 'D':
                newY++;
                break;
            default:
                printf("Invalid move! Please use W, A, S, or D.\n");
                continue;
        }

        if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
            printf("Move out of bounds! Try again.\n");
            continue;
        }

        if (board[newX][newY] == 'X') {
            printf("You hit an obstacle! Game over.\n");
            return 0;
        } else if (board[newX][newY] == 'T') {
            treasuresFound++;
            board[newX][newY] = '.';  // Clear the treasure after found
            printf("Congratulations! You found a treasure!\n");
        }

        playerX = newX;
        playerY = newY;
    }

    printf("Congratulations! You've found all the treasures!\n");
    return 0;
}