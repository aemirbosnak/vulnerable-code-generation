//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock's trusty remote control vehicle simulation
int main() {
    // Declare our vehicle's coordinates and orientation
    int x = 0, y = 0, orientation = 0;

    // Set up the commands array
    char commands[1000];
    gets(commands);

    // Loop through the commands and execute them
    for (int i = 0; commands[i] != '\0'; i++) {
        switch (commands[i]) {
            case 'F':
                // Move forward
                if (orientation == 0) y++;
                else if (orientation == 90) x++;
                else if (orientation == 180) y--;
                else if (orientation == 270) x--;
                break;
            case 'B':
                // Move backward
                if (orientation == 0) y--;
                else if (orientation == 90) x--;
                else if (orientation == 180) y++;
                else if (orientation == 270) x++;
                break;
            case 'L':
                // Turn left
                orientation = (orientation + 90) % 360;
                break;
            case 'R':
                // Turn right
                orientation = (orientation - 90 + 360) % 360;
                break;
            default:
                // Invalid command
                printf("Invalid command: %c", commands[i]);
                return 1;
        }
    }

    // Print the vehicle's final coordinates and orientation
    printf("Coordinates: (%d, %d)\n", x, y);
    printf("Orientation: %d degrees\n", orientation);

    return 0;
}