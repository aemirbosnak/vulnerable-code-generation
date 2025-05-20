//FormAI DATASET v1.0 Category: Robot movement control ; Style: retro
// This program controls the movements of a retro style robot.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x = 0, y = 0, dir = 0;
    srand(time(NULL)); // seed the random number generator
    printf("Welcome to Retro Robot Movement Control!\n\n");
    while (1) { // infinite loop
        printf("Current Position: (%d, %d)\n", x, y);
        printf("Choose a direction to move:\n"); // prompt user for input
        printf("1. Move North\n2. Move East\n3. Move South\n4. Move West\n");
        printf("5. Random Move\n6. Exit\n");
        scanf("%d", &dir);
        switch (dir) { // act based on user input
            case 1:
                printf("Moving North...\n");
                y++;
                break;
            case 2:
                printf("Moving East...\n");
                x++;
                break;
            case 3:
                printf("Moving South...\n");
                y--;
                break;
            case 4:
                printf("Moving West...\n");
                x--;
                break;
            case 5:
                printf("Moving Randomly...\n");
                int rng = rand() % 4 + 1; // generate random number between 1 and 4
                switch (rng) { // act based on random number generated
                    case 1:
                        printf("Moving North...\n");
                        y++;
                        break;
                    case 2:
                        printf("Moving East...\n");
                        x++;
                        break;
                    case 3:
                        printf("Moving South...\n");
                        y--;
                        break;
                    case 4:
                        printf("Moving West...\n");
                        x--;
                        break;
                }
                break;
            case 6:
                printf("Exiting Retro Robot Movement Control...\n");
                exit(0);
            default:
                printf("Invalid direction. Please choose again.\n");
        }
        printf("New Position: (%d, %d)\n\n", x, y);
    }
    return 0;
}