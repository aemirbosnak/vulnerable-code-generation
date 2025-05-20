//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int posX = 0;
int posY = 0;
char direction = 'N';

// Define move function
void move(char command) {
    // Check current direction
    switch (direction) {
        case 'N':
            // Move north
            if (command == 'F') {
                posY++;
            } else if (command == 'B') {
                posY--;
            }
            break;
        case 'S':
            // Move south
            if (command == 'F') {
                posY--;
            } else if (command == 'B') {
                posY++;
            }
            break;
        case 'E':
            // Move east
            if (command == 'F') {
                posX++;
            } else if (command == 'B') {
                posX--;
            }
            break;
        case 'W':
            // Move west
            if (command == 'F') {
                posX--;
            } else if (command == 'B') {
                posX++;
            }
            break;
    }
}

// Define turn function
void turn(char command) {
    // Check current direction
    switch (direction) {
        case 'N':
            // Turn left or right
            if (command == 'L') {
                direction = 'W';
            } else if (command == 'R') {
                direction = 'E';
            }
            break;
        case 'S':
            // Turn left or right
            if (command == 'L') {
                direction = 'E';
            } else if (command == 'R') {
                direction = 'W';
            }
            break;
        case 'E':
            // Turn left or right
            if (command == 'L') {
                direction = 'N';
            } else if (command == 'R') {
                direction = 'S';
            }
            break;
        case 'W':
            // Turn left or right
            if (command == 'L') {
                direction = 'S';
            } else if (command == 'R') {
                direction = 'N';
            }
            break;
    }
}

int main() {
    // Declare variables
    char input;
    char command;
    
    // Loop through user inputs
    while (1) {
        // Print current position and direction
        printf("Current position: (%d, %d), Direction: %c\n", posX, posY, direction);
        
        // Prompt user for input
        printf("Enter command (M, L, R): ");
        scanf(" %c", &input);
        
        // Check input and perform action
        if (input == 'M' || input == 'm') {
            printf("Enter movement command (F, B): ");
            scanf(" %c", &command);
            move(command);
        } else if (input == 'L' || input == 'l') {
            turn('L');
        } else if (input == 'R' || input == 'r') {
            turn('R');
        } else {
            printf("Invalid input\n");
        }
    }
    
    return 0;
}