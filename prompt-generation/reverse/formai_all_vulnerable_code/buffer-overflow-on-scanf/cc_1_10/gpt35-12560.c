//FormAI DATASET v1.0 Category: Robot movement control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to initialize the robot's position with random coordinates
void initialize_position(int *x, int *y) {
    srand(time(NULL));
    *x = rand() % ROWS;
    *y = rand() % COLS;
}

int main() {
    int x, y, move;
    initialize_position(&x, &y);

    printf("Starting position: (%d, %d)\n", x, y);

    while (1) {
        // Ask the user for the direction of the movement
        printf("Enter the direction of the movement (0 for up, 1 for down, 2 for left, 3 for right, 4 to quit): ");
        scanf("%d", &move);

        switch (move) {
            case 0: // Move up
                if (x == 0)
                    printf("Robot cannot move up.\n");
                else {
                    x--;
                    printf("Moved up to (%d, %d).\n", x, y);
                }
                break;
            case 1: // Move down
                if (x == ROWS-1)
                    printf("Robot cannot move down.\n");
                else {
                    x++;
                    printf("Moved down to (%d, %d).\n", x, y);
                }
                break;
            case 2: // Move left
                if (y == 0)
                    printf("Robot cannot move left.\n");
                else {
                    y--;
                    printf("Moved left to (%d, %d).\n", x, y);
                }
                break;
            case 3: // Move right
                if (y == COLS-1)
                    printf("Robot cannot move right.\n");
                else {
                    y++;
                    printf("Moved right to (%d, %d).\n", x, y);
                }
                break;
            case 4: // Quit the program
                printf("Quitting...\n");
                exit(0);
            default: // Invalid input
                printf("Invalid input. Enter a number from 0 to 4.\n");
        }
    }

    return 0;
}