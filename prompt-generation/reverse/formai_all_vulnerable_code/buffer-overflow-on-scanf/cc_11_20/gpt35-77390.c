//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
// GPS Navigation Simulation Program using Decentralized Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

// Function to print the message and wait for user input
void printAndWait(char message[]) {
    printf("%s", message);
    getchar();
}

int main() {
    int i, j;
    int gpsX = 0, gpsY = 0; // Starting position of GPS
    int posX, posY; // Current position of GPS

    // Initializing the topography of the map
    int map[MAX_SIZE][MAX_SIZE] = {
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    };

    char directions[][10] = {"North", "East", "South", "West"}; // Array to store directions

    // Welcome message with instructions
    printf("GPS Navigation Simulation Program\n");
    printAndWait("Press Enter to start the simulation...");

    // Running the simulation loop
    while (1) {
        posX = gpsX;
        posY = gpsY;

        // Printing the current map state
        printf("Current Map:\n");
        for (i = 0; i < MAX_SIZE; i++) {
            for (j = 0; j < MAX_SIZE; j++) {
                if (i == gpsY && j == gpsX) {
                    printf("X ");
                } else if (map[i][j]) {
                    printf("O ");
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }

        // Printing the available directions
        printf("Available directions:\n");
        if (gpsY > 0 && map[gpsY - 1][gpsX]) {
            printf("1. North\n");
        }
        if (gpsX < MAX_SIZE - 1 && map[gpsY][gpsX + 1]) {
            printf("2. East\n");
        }
        if (gpsY < MAX_SIZE - 1 && map[gpsY + 1][gpsX]) {
            printf("3. South\n");
        }
        if (gpsX > 0 && map[gpsY][gpsX - 1]) {
            printf("4. West\n");
        }
        printf("5. Quit\n");

        // Reading the user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (gpsY > 0 && map[gpsY - 1][gpsX]) {
                    gpsY--;
                    printf("You moved North.\n");
                } else {
                    printf("Invalid move! Try again...\n");
                }
                break;

            case 2:
                if (gpsX < MAX_SIZE - 1 && map[gpsY][gpsX + 1]) {
                    gpsX++;
                    printf("You moved East.\n");
                } else {
                    printf("Invalid move! Try again...\n");
                }
                break;

            case 3:
                if (gpsY < MAX_SIZE - 1 && map[gpsY + 1][gpsX]) {
                    gpsY++;
                    printf("You moved South.\n");
                } else {
                    printf("Invalid move! Try again...\n");
                }
                break;

            case 4:
                if (gpsX > 0 && map[gpsY][gpsX - 1]) {
                    gpsX--;
                    printf("You moved West.\n");
                } else {
                    printf("Invalid move! Try again...\n");
                }
                break;

            case 5:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again...\n");
        }

        // Printing the current direction
        int directionIndex = 0;
        if (gpsY < posY) {
            directionIndex = 0;
        } else if (gpsX > posX) {
            directionIndex = 1;
        } else if (gpsY > posY) {
            directionIndex = 2;
        } else if (gpsX < posX) {
            directionIndex = 3;
        }
        char message[50];
        sprintf(message, "Current direction: %s\n", directions[directionIndex]);
        printAndWait(message);
    }

    return 0;
}