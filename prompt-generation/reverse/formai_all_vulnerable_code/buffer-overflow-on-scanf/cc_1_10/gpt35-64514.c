//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function to generate a random number between min and max (inclusive)
int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// A function to simulate the drone's movement
void moveDrone(int x, int y) {
    printf("Drone moved to (%d, %d)\n", x, y);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int x = getRandom(0, 100); // Set the initial drone position randomly
    int y = getRandom(0, 100);
    int battery = 100; // Initial battery level
    int commandCount = 0; // Keep track of the number of commands issued by the user

    printf("Welcome to the Retro Drone Remote Control!\n\n");
    printf("Commands:\n");
    printf("1 - Move up\n");
    printf("2 - Move down\n");
    printf("3 - Move left\n");
    printf("4 - Move right\n");
    printf("5 - Land\n");
    printf("6 - Exit program\n\n");

    while (1) { // Loop until the user enters command 6 to exit
        printf("Enter command: ");
        int command;
        scanf("%d", &command);

        if (command == 1) { // Move up
            if (y < 100) {
                y++;
                moveDrone(x, y);
            } else {
                printf("Cannot go up, reached maximum altitude.\n");
            }
        } else if (command == 2) { // Move down
            if (y > 0) {
                y--;
                moveDrone(x, y);
            } else {
                printf("Cannot go down, reached minimum altitude.\n");
            }
        } else if (command == 3) { // Move left
            if (x > 0) {
                x--;
                moveDrone(x, y);
            } else {
                printf("Cannot go left, reached left edge of map.\n");
            }
        } else if (command == 4) { // Move right
            if (x < 100) {
                x++;
                moveDrone(x, y);
            } else {
                printf("Cannot go right, reached right edge of map.\n");
            }
        } else if (command == 5) { // Land
            printf("Landing drone...\n");
            printf("Drone landed at (%d, %d)\n", x, y);
            // Decrease battery by the number of commands issued
            battery -= commandCount;
            printf("Battery level: %d%%\n", battery);
            break; // Exit the loop
        } else if (command == 6) { // Exit program
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Invalid command.\n");
        }

        commandCount++;
        // Decrease battery by 1 for each command issued
        battery--;
        printf("Battery level: %d%%\n", battery);

        if (battery <= 0) { // Drone is out of battery
            printf("Drone is out of battery. Landing...\n");
            printf("Drone landed at (%d, %d)\n", x, y);
            break; // Exit the loop
        }
    }

    return 0;
}