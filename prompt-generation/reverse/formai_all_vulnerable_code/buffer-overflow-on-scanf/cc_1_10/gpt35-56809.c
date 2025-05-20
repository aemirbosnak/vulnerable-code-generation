//FormAI DATASET v1.0 Category: Robot movement control ; Style: Linus Torvalds
/*
 * Robot Movement Control Program
 * By: [Your Name]
 */

#include <stdio.h>

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'

int main(void)
{
    char command;
    int distance;

    printf("Welcome to the Robot Movement Control Program!\n\n");

    while (1) {
        printf("Enter a command (F: Forward, B: Backward, L: Left, R: Right): ");
        scanf(" %c", &command);
        
        switch (command) {
            case FORWARD:
            case BACKWARD:
                printf("Enter distance (in cm): ");
                scanf("%d", &distance);
                if (command == FORWARD)
                    printf("Moving forward %d cm...\n", distance);
                else
                    printf("Moving backward %d cm...\n", distance);
                break;
            case LEFT:
            case RIGHT:
                printf("Enter angle (in degrees): ");
                scanf("%d", &distance);
                if (command == LEFT)
                    printf("Turning left %d degrees...\n", distance);
                else
                    printf("Turning right %d degrees...\n", distance);
                break;
            default:
                printf("Invalid command. Try again.\n");
                continue;
        }

        printf("\nCommand completed.\n");
    }

    return 0;
}