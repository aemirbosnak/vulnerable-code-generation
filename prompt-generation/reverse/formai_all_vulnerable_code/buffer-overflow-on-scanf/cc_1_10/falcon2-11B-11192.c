//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
int roll_dice(int sides);
void print_game_map(int width, int height, int map[][height]);

// Main function
int main() {
    int width, height, map[width][height];
    bool done = false;

    printf("Enter the width of the game map (minimum 5): ");
    scanf("%d", &width);
    printf("Enter the height of the game map (minimum 5): ");
    scanf("%d", &height);

    // Generate the game map
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            map[i][j] = rand() % 100 + 1;
        }
    }

    // Print the game map
    printf("Game Map:\n");
    print_game_map(width, height, map);

    // Game loop
    while (!done) {
        // Get user input
        printf("Enter your action: ");
        char action[20];
        scanf(" %s", action);

        // Process user input
        if (strcmp(action, "north") == 0) {
            printf("You move north.\n");
        } else if (strcmp(action, "south") == 0) {
            printf("You move south.\n");
        } else if (strcmp(action, "east") == 0) {
            printf("You move east.\n");
        } else if (strcmp(action, "west") == 0) {
            printf("You move west.\n");
        } else if (strcmp(action, "exit") == 0) {
            done = true;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}

// Function to print the game map
void print_game_map(int width, int height, int map[][height]) {
    printf("  ");
    for (int i = 0; i < width; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < height; i++) {
        printf("  ");
        for (int j = 0; j < width; j++) {
            printf("%d ", map[j][i]);
        }
        printf("\n");
    }
}

// Function to roll a dice
int roll_dice(int sides) {
    return rand() % sides + 1;
}