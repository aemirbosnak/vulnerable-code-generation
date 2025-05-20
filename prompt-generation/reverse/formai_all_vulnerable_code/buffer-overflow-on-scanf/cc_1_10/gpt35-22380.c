//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 10 // Define the map size as 10x10
#define STREET 'S' // Street character
#define OBSTACLE 'X' // Obstacle character
#define TARGET '$' // Destination character

// Function to print the map
void print_map(char map[][MAP_SIZE], int x, int y) {
    printf("\n"); // Print a new line for visual purposes
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == x && j == y) { // If player location
                printf("P ");
            } else { // Otherwise print the map character
                printf("%c ", map[i][j]);
            }
        }
        printf("\n"); // Print a new line for each row
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE] = { // Define the map
        { STREET, STREET, OBSTACLE, STREET, STREET, STREET, STREET, STREET, TARGET, STREET },
        { STREET, OBSTACLE, STREET, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, STREET, STREET, STREET },
        { STREET, STREET, OBSTACLE, STREET, STREET, STREET, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE },
        { OBSTACLE, STREET, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, STREET, STREET, STREET },
        { STREET, OBSTACLE, STREET, STREET, STREET, OBSTACLE, STREET, STREET, TARGET, STREET },
        { STREET, OBSTACLE, OBSTACLE, OBSTACLE, STREET, OBSTACLE, OBSTACLE, OBSTACLE, STREET, STREET },
        { STREET, STREET, STREET, STREET, STREET, STREET, OBSTACLE, STREET, OBSTACLE, STREET },
        { OBSTACLE, OBSTACLE, OBSTACLE, STREET, OBSTACLE, OBSTACLE, OBSTACLE, STREET, OBSTACLE, STREET },
        { STREET, TARGET, STREET, OBSTACLE, STREET, STREET, STREET, STREET, TARGET, STREET },
        { OBSTACLE, STREET, STREET, STREET, STREET, OBSTACLE, STREET, STREET, OBSTACLE, OBSTACLE }
    };
    int player_x = 0; // Player x location
    int player_y = 0; // Player y location
    
    printf("*** GPS Navigation Simulation ***");
    print_map(map, player_x, player_y); // Print the initial map
    
    // Game loop
    while (map[player_x][player_y] != TARGET) { // While player hasn't reached the destination
        // Get user input
        char input;
        printf("\nWhere would you like to move (WASD)? ");
        scanf(" %c", &input);
        
        // Move the player
        switch (input) {
            case 'W':
                if (player_x > 0 && map[player_x - 1][player_y] != OBSTACLE) {
                    player_x--;
                }
                break;
            case 'A':
                if (player_y > 0 && map[player_x][player_y - 1] != OBSTACLE) {
                    player_y--;
                }
                break;
            case 'S':
                if (player_x < MAP_SIZE - 1 && map[player_x + 1][player_y] != OBSTACLE) {
                    player_x++;
                }
                break;
            case 'D':
                if (player_y < MAP_SIZE - 1 && map[player_x][player_y + 1] != OBSTACLE) {
                    player_y++;
                }
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
        
        print_map(map, player_x, player_y); // Print the updated map
    }
    
    printf("\nCongratulations, you have reached the destination!");
    
    return 0;
}