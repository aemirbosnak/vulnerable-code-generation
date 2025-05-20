//FormAI DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Robot {
    int x;
    int y;
} Robot;

void moveNorth(Robot *r) {
    r->y++;
}

void moveEast(Robot *r) {
    r->x++;
}

void moveSouth(Robot *r) {
    r->y--;
}

void moveWest(Robot *r) {
    r->x--;
}

int main() {
    // Initialize the robot at (0, 0)
    Robot robot = {0, 0};

    // Loop until the user quits the program
    while (true) {
        // Print the robot's current position
        printf("Current position: (%d, %d)\n", robot.x, robot.y);

        // Get the user's input
        char direction;
        printf("Enter a direction (n, e, s, w) or q to quit: ");
        scanf(" %c", &direction);

        // Move the robot based on the user's input
        switch (direction) {
            case 'n':
                moveNorth(&robot);
                break;
            case 'e':
                moveEast(&robot);
                break;
            case 's':
                moveSouth(&robot);
                break;
            case 'w':
                moveWest(&robot);
                break;
            case 'q':
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid input!\n");
                break;
        }
    }

    return 0;
}