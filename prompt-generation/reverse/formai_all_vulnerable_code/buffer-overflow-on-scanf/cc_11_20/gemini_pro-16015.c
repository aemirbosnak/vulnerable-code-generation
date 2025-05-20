//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game map
char map[5][5] = {
    {'#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#'},
    {'#', '.', 'P', '.', '#'},
    {'#', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#'}
};

// Define the player's position
int playerX = 2;
int playerY = 2;

// Define the game state
enum GameState {
    PLAYING,
    WON,
    LOST
};
enum GameState gameState = PLAYING;

// Main game loop
int main() {
    // Print the welcome message
    printf("Welcome to the Happy Adventure Game!\n");

    // Game loop
    while (gameState == PLAYING) {
        // Print the map
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }

        // Get the player's input
        char input;
        printf("Enter your move (w, a, s, d): ");
        scanf(" %c", &input);

        // Update the player's position
        switch (input) {
            case 'w':
                if (map[playerX - 1][playerY] != '#') {
                    playerX--;
                }
                break;
            case 'a':
                if (map[playerX][playerY - 1] != '#') {
                    playerY--;
                }
                break;
            case 's':
                if (map[playerX + 1][playerY] != '#') {
                    playerX++;
                }
                break;
            case 'd':
                if (map[playerX][playerY + 1] != '#') {
                    playerY++;
                }
                break;
        }

        // Check if the player has won
        if (map[playerX][playerY] == 'E') {
            gameState = WON;
        }

        // Check if the player has lost
        if (map[playerX][playerY] == '#') {
            gameState = LOST;
        }
    }

    // Print the end message
    if (gameState == WON) {
        printf("You win!\n");
    } else if (gameState == LOST) {
        printf("You lose!\n");
    }

    return 0;
}