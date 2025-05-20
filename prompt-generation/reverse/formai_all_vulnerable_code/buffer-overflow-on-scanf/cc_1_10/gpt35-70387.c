//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateMap(int map[][10], int height, int width);
void printMap(int map[][10], int height, int width);
void movePlayer(int map[][10], int *playerX, int *playerY, int direction);

int main()
{
    srand(time(NULL)); // Initialize random number generator
    
    int map[10][10]; // Initialize map
    
    // Generate and print map
    generateMap(map, 10, 10);
    printMap(map, 10, 10);
    
    int playerX = 5; // Set initial player X position
    int playerY = 5; // Set initial player Y position
    
    char input; // Variable to store user input
    
    do {
        printf("Which direction would you like to move? (WASD) ");
        scanf(" %c", &input);
        
        // Move player based on user input
        switch (input) {
            case 'w':
                movePlayer(map, &playerX, &playerY, 0);
                break;
            case 'a':
                movePlayer(map, &playerX, &playerY, 1);
                break;
            case 's':
                movePlayer(map, &playerX, &playerY, 2);
                break;
            case 'd':
                movePlayer(map, &playerX, &playerY, 3);
                break;
            default:
                printf("Invalid input\n");
        }
        
        // Print updated map
        printMap(map, 10, 10);
    } while (input != 'q'); // Continue until user enters 'q'
    
    return 0;
}

// Function to generate random map
void generateMap(int map[][10], int height, int width) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (rand() % 10 == 0) { // 10% chance of obstacle
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

// Function to print map
void printMap(int map[][10], int height, int width) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 5 && j == 5) { // Player position
                printf("P ");
            } else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to move player
void movePlayer(int map[][10], int *playerX, int *playerY, int direction) {
    int newX, newY;
    switch (direction) {
        case 0: // Up
            newX = *playerX - 1;
            newY = *playerY;
            break;
        case 1: // Left
            newX = *playerX;
            newY = *playerY - 1;
            break;
        case 2: // Down
            newX = *playerX + 1;
            newY = *playerY;
            break;
        case 3: // Right
            newX = *playerX;
            newY = *playerY + 1;
            break;
        default:
            return;
    }
    
    // Check if new position is valid
    if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && map[newX][newY] != '#') {
        *playerX = newX;
        *playerY = newY;
    }
}