//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define game map
char map[5][5] = {
    {'#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', ' ', 'P', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#'}
};

// Define player position
int playerX = 2;
int playerY = 2;

// Define game states
enum GameState {
    PLAYING,
    WON,
    LOST
};

// Declare game state variable
enum GameState state = PLAYING;

// Function to print game map
void printMap() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Function to handle player movement
void movePlayer(char direction) {
    switch (direction) {
        case 'w':
            if (map[playerX - 1][playerY] != '#') {
                playerX--;
            }
            break;
        case 's':
            if (map[playerX + 1][playerY] != '#') {
                playerX++;
            }
            break;
        case 'a':
            if (map[playerX][playerY - 1] != '#') {
                playerY--;
            }
            break;
        case 'd':
            if (map[playerX][playerY + 1] != '#') {
                playerY++;
            }
            break;
    }
}

// Function to check if player has won
int checkWin() {
    if (map[playerX][playerY] == 'X') {
        return 1;
    }
    return 0;
}

// Function to check if player has lost
int checkLose() {
    if (map[playerX][playerY] == '#') {
        return 1;
    }
    return 0;
}

// Main game loop
int main() {
    // Print welcome message
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Your goal is to reach the exit (X) without hitting any walls (#).\n");

    // Print map
    printMap();

    // Get player input
    char input;
    while (state == PLAYING) {
        printf("Enter a direction (w, s, a, d): ");
        scanf(" %c", &input);

        // Move player
        movePlayer(input);

        // Print map
        printMap();

        // Check if player has won
        if (checkWin()) {
            state = WON;
            printf("You win!\n");
        }

        // Check if player has lost
        if (checkLose()) {
            state = LOST;
            printf("You lose!\n");
        }
    }

    return 0;
}