//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE_COUNT 3

void initializeGame(char board[SIZE][SIZE], int treasures[TREASURE_COUNT][2]);
void displayBoard(char board[SIZE][SIZE]);
int isTreasure(int x, int y, int treasures[TREASURE_COUNT][2]);
void playGame();

int main() {
    printf("🎉 Welcome to the Treasure Hunt Game! 🎉\n");
    printf("Try to find hidden treasures in the grid!\n");
    playGame();
    return 0;
}

void playGame() {
    char board[SIZE][SIZE];
    int treasures[TREASURE_COUNT][2];
    initializeGame(board, treasures);

    int guesses = 5;
    int score = 0;

    while (guesses > 0) {
        displayBoard(board);
        printf("You have %d guesses left!\n", guesses);
        int x, y;

        printf("Enter your guess coordinates (row [0-4] and column [0-4]): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("🚫 Invalid coordinates! Try again.\n");
            continue;
        }

        if (board[x][y] == 'T') {
            printf("🎉 Congratulations! You found a treasure!\n");
            score++;
            board[x][y] = 'F'; // Mark as found
        } else {
            printf("💔 No treasure here! Keep searching!\n");
            board[x][y] = 'X'; // Mark as guessed
        }
        guesses--;
    }

    printf("✨ Game over! You found %d treasures! ✨\n", score);
    printf("Thank you for playing!\n");
}

void initializeGame(char board[SIZE][SIZE], int treasures[TREASURE_COUNT][2]) {
    srand(time(NULL));
    
    // Initialize board with empty spaces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Randomly place treasures
    for (int i = 0; i < TREASURE_COUNT; ) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (isTreasure(x, y, treasures) == 0) {
            treasures[i][0] = x;
            treasures[i][1] = y;
            board[x][y] = 'T'; // Place a treasure
            i++;
        }
    }
}

int isTreasure(int x, int y, int treasures[TREASURE_COUNT][2]) {
    for (int i = 0; i < TREASURE_COUNT; i++) {
        if (treasures[i][0] == x && treasures[i][1] == y) {
            return 1; // Found a treasure at this location
        }
    }
    return 0; // No treasure found
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\n🗺️ Current Board:\n");
    printf("  0 1 2 3 4\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}