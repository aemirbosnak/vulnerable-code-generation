//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

int main() {
    int x = 0, y = 0; // Current position of the robot
    int direction = RIGHT; // Current direction of the robot
    char command; // Command to move the robot

    printf("Welcome to the Retro Robot Movement Control System!\n");
    printf("Available commands: l (left), r (right), u (up), d (down), q (quit)\n");

    while (1) {
        printf("Enter a command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'l':
                if (direction == LEFT) {
                    y--;
                } else if (direction == RIGHT) {
                    y++;
                } else if (direction == UP) {
                    x--;
                } else if (direction == DOWN) {
                    x++;
                }
                direction = LEFT;
                break;
            case 'r':
                if (direction == LEFT) {
                    y++;
                } else if (direction == RIGHT) {
                    y--;
                } else if (direction == UP) {
                    x++;
                } else if (direction == DOWN) {
                    x--;
                }
                direction = RIGHT;
                break;
            case 'u':
                if (direction == LEFT) {
                    x++;
                } else if (direction == RIGHT) {
                    x--;
                } else if (direction == UP) {
                    y--;
                } else if (direction == DOWN) {
                    y++;
                }
                direction = UP;
                break;
            case 'd':
                if (direction == LEFT) {
                    x--;
                } else if (direction == RIGHT) {
                    x++;
                } else if (direction == UP) {
                    y++;
                } else if (direction == DOWN) {
                    y--;
                }
                direction = DOWN;
                break;
            case 'q':
                printf("Quitting...\n");
                return 0;
            default:
                printf("Invalid command!\n");
                break;
        }

        printf("Current position: (%d, %d)\n", x, y);
    }

    return 0;
}