//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 5

// Define functions to control the robot
void printWelcomeMessage() {
    printf("🌟 Welcome to the Cheerful Robot Movement Control! 🌟\n");
    printf("You can move your robot in the grid:\n");
    printf("Use 'w' for Up, 's' for Down, 'a' for Left, 'd' for Right.\n");
    printf("Type 'exit' to stop the fun! Let’s get moving! 🚀\n");
}

void printGrid(int x, int y) {
    printf("\n🤖 The Robot is currently at position (%d, %d)! 🎉\n", x, y);
    printf("The grid looks like:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == x && j == y) {
                printf("[R] ");
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

int main() {
    int posX = 0, posY = 0;
    char command[10];
    
    printWelcomeMessage();
    printGrid(posX, posY);
    
    while (1) {
        printf("\nType your command: ");
        scanf("%s", command);

        // Check for exit command
        if (strcmp(command, "exit") == 0) {
            printf("🎈 Thank you for playing! Bye bye! 🎈\n");
            break;
        }

        // Move the robot based on user input
        if (strcmp(command, "w") == 0) {
            if (posX > 0) {
                posX--;
                printf("🚶‍♂️ Moving Up! 🎈\n");
            } else {
                printf("🚫 Can't move Up! You are at the top edge! 😂\n");
            }
        } else if (strcmp(command, "s") == 0) {
            if (posX < GRID_SIZE - 1) {
                posX++;
                printf("🚶‍♂️ Moving Down! 🎈\n");
            } else {
                printf("🚫 Can't move Down! You are at the bottom edge! 😂\n");
            }
        } else if (strcmp(command, "a") == 0) {
            if (posY > 0) {
                posY--;
                printf("🚶‍♂️ Moving Left! 🎈\n");
            } else {
                printf("🚫 Can't move Left! You are at the left edge! 😂\n");
            }
        } else if (strcmp(command, "d") == 0) {
            if (posY < GRID_SIZE - 1) {
                posY++;
                printf("🚶‍♂️ Moving Right! 🎈\n");
            } else {
                printf("🚫 Can't move Right! You are at the right edge! 😂\n");
            }
        } else {
            printf("❌ Invalid command! Please use 'w', 'a', 's', 'd', or 'exit'.\n");
        }

        printGrid(posX, posY);
    }

    return 0;
}