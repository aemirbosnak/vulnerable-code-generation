//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_STEPS 20

typedef struct {
    int x;
    int y;
} Position;

int main(void) {
    // Initialize the game map
    bool map[MAP_HEIGHT][MAP_WIDTH] = {{false}};
    map[5][10] = true;
    map[8][8] = true;
    map[2][18] = true;

    // Set the starting position and steps left
    Position current_position = {
        .x = 0,
        .y = 0
    };
    int steps_left = MAX_STEPS;

    // Start the game loop
    while (true) {
        // Print the current position and steps left
        printf("You are at (%d, %d). %d steps left.\n", 
               current_position.x, current_position.y, steps_left);

        // Check if the player has reached the end
        if (current_position.x == MAP_WIDTH - 1 && 
            current_position.y == MAP_HEIGHT - 1) {
            printf("Congratulations! You have reached the end of the space adventure!\n");
            break;
        }

        // Check if the player has run out of steps
        if (steps_left == 0) {
            printf("Oh no! You have run out of steps and will be lost in space forever!\n");
            break;
        }

        // Prompt the player to enter a direction
        printf("Enter a direction (up, down, left, or right): ");
        char direction;
        scanf(" %c", &direction);

        // Update the player's position based on the chosen direction
        switch(direction) {
            case 'u':
                if (current_position.y > 0 && 
                    !map[current_position.y - 1][current_position.x]) {
                    current_position.y--;
                } else {
                    printf("You cannot go in that direction.\n");
                    continue;
                }
                break;
            case 'd':
                if (current_position.y < MAP_HEIGHT - 1 && 
                    !map[current_position.y + 1][current_position.x]) {
                    current_position.y++;
                } else {
                    printf("You cannot go in that direction.\n");
                    continue;
                }
                break;
            case 'l':
                if (current_position.x > 0 && 
                    !map[current_position.y][current_position.x - 1]) {
                    current_position.x--;
                } else {
                    printf("You cannot go in that direction.\n");
                    continue;
                }
                break;
            case 'r':
                if (current_position.x < MAP_WIDTH - 1 && 
                    !map[current_position.y][current_position.x + 1]) {
                    current_position.x++;
                } else {
                    printf("You cannot go in that direction.\n");
                    continue;
                }
                break;
            default:
                printf("Invalid direction.\n");
                continue;
        }

        // Decrement the steps left counter
        steps_left--;
    }

    return 0;
}