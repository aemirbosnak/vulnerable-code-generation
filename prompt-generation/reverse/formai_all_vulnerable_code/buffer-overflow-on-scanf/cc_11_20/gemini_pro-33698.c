//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the map
#define MAP_SIZE 10
char map[MAP_SIZE][MAP_SIZE] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Define the player
struct player {
    int x;
    int y;
};

// Initialize the player
struct player player = {1, 1};

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    while (1) {
        // Display the map
        for (int i = 0; i < MAP_SIZE; i++) {
            for (int j = 0; j < MAP_SIZE; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }

        // Get the player's input
        char input;
        printf("Enter a direction (w, a, s, d): ");
        scanf(" %c", &input);

        // Move the player
        switch (input) {
            case 'w':
                if (map[player.x - 1][player.y] != '#') {
                    player.x--;
                }
                break;
            case 'a':
                if (map[player.x][player.y - 1] != '#') {
                    player.y--;
                }
                break;
            case 's':
                if (map[player.x + 1][player.y] != '#') {
                    player.x++;
                }
                break;
            case 'd':
                if (map[player.x][player.y + 1] != '#') {
                    player.y++;
                }
                break;
        }

        // Check if the player has reached the goal
        if (player.x == MAP_SIZE - 2 && player.y == MAP_SIZE - 2) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}