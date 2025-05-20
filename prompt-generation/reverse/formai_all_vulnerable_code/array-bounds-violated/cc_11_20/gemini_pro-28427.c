//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Define the landmarks
#define CASTLE 0
#define FOREST 1
#define LAKE 2
#define MOUNTAIN 3
#define RIVER 4

// Define the commands
#define MOVE 0
#define TURN_LEFT 1
#define TURN_RIGHT 2
#define REPORT_POSITION 3
#define QUIT 4

// Define the map
char map[5][5] = {
    {'C', 'F', 'L', 'M', 'R'},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
};

// Define the player's position
int x = 0;
int y = 0;
int direction = NORTH;

// Main function
int main() {
    // Print the welcome message
    printf("Welcome to the Medieval GPS Navigation Simulator!\n");

    // Main game loop
    while (1) {
        // Print the map
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }

        // Print the player's position
        printf("Your position: (%d, %d)\n", x, y);

        // Prompt the player for a command
        printf("Enter a command (move, turn left, turn right, report position, quit): ");
        char command[20];
        scanf("%s", command);

        // Execute the command
        if (strcmp(command, "move") == 0) {
            // Move the player forward one square
            switch (direction) {
                case NORTH:
                    y--;
                    break;
                case EAST:
                    x++;
                    break;
                case SOUTH:
                    y++;
                    break;
                case WEST:
                    x--;
                    break;
            }

            // Check if the player has reached a landmark
            if (map[y][x] == 'C') {
                printf("You have reached the castle!\n");
            } else if (map[y][x] == 'F') {
                printf("You have entered the forest!\n");
            } else if (map[y][x] == 'L') {
                printf("You have reached the lake!\n");
            } else if (map[y][x] == 'M') {
                printf("You have reached the mountain!\n");
            } else if (map[y][x] == 'R') {
                printf("You have reached the river!\n");
            }
        } else if (strcmp(command, "turn left") == 0) {
            // Turn the player left
            direction = (direction + 3) % 4;
        } else if (strcmp(command, "turn right") == 0) {
            // Turn the player right
            direction = (direction + 1) % 4;
        } else if (strcmp(command, "report position") == 0) {
            // Report the player's position
            printf("Your position: (%d, %d)\n", x, y);
        } else if (strcmp(command, "quit") == 0) {
            // Quit the game
            break;
        } else {
            // Invalid command
            printf("Invalid command. Please enter a valid command.\n");
        }
    }

    // Print the goodbye message
    printf("Thank you for playing the Medieval GPS Navigation Simulator!\n");

    return 0;
}