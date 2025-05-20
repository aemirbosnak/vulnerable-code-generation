//FormAI DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 255
#define MIN_SPEED 0
#define MAX_ANGLE 180
#define MIN_ANGLE 0

int main() {
    int speed = 0, angle = 90;
    char command;

    printf("Welcome to C Robot Movement Control Program\n");
    printf("Commands:\n");
    printf("w: increase speed\n");
    printf("s: decrease speed\n");
    printf("a: turn left\n");
    printf("d: turn right\n");
    printf("q: exit program\n");

    while (1) {
        printf("Speed: %d  Angle: %d\n", speed, angle);
        printf("Enter command: ");
        scanf("%c", &command);

        switch (command) {
            case 'w':
                if (speed < MAX_SPEED) {
                    speed++;
                }
                break;
            case 's':
                if (speed > MIN_SPEED) {
                    speed--;
                }
                break;
            case 'a':
                if (angle < MAX_ANGLE) {
                    angle++;
                }
                break;
            case 'd':
                if (angle > MIN_ANGLE) {
                    angle--;
                }
                break;
            case 'q':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid command. Try again.\n");
        }
        // clear input buffer
        while ((getchar()) != '\n');
    }

    return 0;
}