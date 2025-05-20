//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

void robot_move(int direction)
{
    switch (direction)
    {
        case LEFT:
            printf("Turning left...\n");
            sleep(1);
            printf("Left turn complete!\n");
            break;
        case RIGHT:
            printf("Turning right...\n");
            sleep(1);
            printf("Right turn complete!\n");
            break;
        case FORWARD:
            printf("Moving forward...\n");
            sleep(1);
            printf("Forward motion complete!\n");
            break;
        case BACKWARD:
            printf("Moving backward...\n");
            sleep(1);
            printf("Backward motion complete!\n");
            break;
    }
}

int main()
{
    int direction;

    printf("Enter direction (L/R/F/B): ");
    scanf("%c", &direction);

    switch (direction)
    {
        case 'L':
            robot_move(LEFT);
            break;
        case 'R':
            robot_move(RIGHT);
            break;
        case 'F':
            robot_move(FORWARD);
            break;
        case 'B':
            robot_move(BACKWARD);
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}