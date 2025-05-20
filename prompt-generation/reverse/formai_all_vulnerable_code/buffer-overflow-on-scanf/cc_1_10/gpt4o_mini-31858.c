//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURES 3
#define TRAPS 3

char board[SIZE][SIZE];
int playerX, playerY, score;

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
    
    // Placing treasures
    for (int i = 0; i < TREASURES; i++) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (board[x][y] != '.');
        board[x][y] = 'T';
    }
    
    // Placing traps
    for (int i = 0; i < TRAPS; i++) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (board[x][y] != '.');
        board[x][y] = 'X';
    }
    
    // Place player
    playerX = 0;
    playerY = 0;
    board[playerX][playerY] = 'P';
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void movePlayer(char direction) {
    int newX = playerX;
    int newY = playerY;

    switch (direction) {
        case 'w': newX--; break; // Move up
        case 's': newX++; break; // Move down
        case 'a': newY--; break; // Move left
        case 'd': newY++; break; // Move right
        default: printf("Invalid move!\n"); return;
    }

    // Validate move
    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
        printf("Move out of bounds!\n");
        return;
    }

    // Update game state
    board[playerX][playerY] = '.';
    playerX = newX;
    playerY = newY;

    if (board[playerX][playerY] == 'T') {
        score += 10;
        printf("You found a treasure! +10 Points!\n");
    } else if (board[playerX][playerY] == 'X') {
        score -= 5;
        printf("You landed on a trap! -5 Points!\n");
    }
    board[playerX][playerY] = 'P';
}

int main() {
    srand(time(NULL));
    score = 0;
    initializeBoard();

    char move;
    while (score >= -5) {
        printBoard();
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);
        movePlayer(move);
    }

    printf("Game Over! Final Score: %d\n", score);
    return 0;
}