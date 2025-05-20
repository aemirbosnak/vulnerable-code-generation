//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the map
char map[10][10] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Define the player's position
int playerX = 1;
int playerY = 1;

// Define the game state
int gameOver = 0;

// Define the main function
int main() {
    // Print the welcome message
    printf("Welcome to the Text-Based Adventure Game!\n");

    // Print the map
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    // Get the player's input
    while (!gameOver) {
        char input;
        printf("What do you want to do? (n/s/e/w/q): ");
        scanf(" %c", &input);

        // Check the player's input
        switch (input) {
            case 'n':
                // Move the player north
                if (map[playerX - 1][playerY] != '#') {
                    playerX--;
                }
                break;
            case 's':
                // Move the player south
                if (map[playerX + 1][playerY] != '#') {
                    playerX++;
                }
                break;
            case 'e':
                // Move the player east
                if (map[playerX][playerY + 1] != '#') {
                    playerY++;
                }
                break;
            case 'w':
                // Move the player west
                if (map[playerX][playerY - 1] != '#') {
                    playerY--;
                }
                break;
            case 'q':
                // Quit the game
                gameOver = 1;
                break;
            default:
                // Invalid input
                printf("Invalid input.\n");
                break;
        }

        // Print the map
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == playerX && j == playerY) {
                    printf("@");
                } else {
                    printf("%c", map[i][j]);
                }
            }
            printf("\n");
        }
    }

    // Print the game over message
    printf("Game over!\n");

    return 0;
}