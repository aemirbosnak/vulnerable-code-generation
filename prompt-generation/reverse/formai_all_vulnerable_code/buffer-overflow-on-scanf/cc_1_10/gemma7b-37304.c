//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACK 3

void move(int direction)
{
    switch (direction)
    {
        case LEFT:
            printf("Turning left...\n");
            break;
        case RIGHT:
            printf("Turning right...\n");
            break;
        case FORWARD:
            printf("Moving forward...\n");
            break;
        case BACK:
            printf("Moving back...\n");
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
            move(LEFT);
            break;
        case 'R':
            move(RIGHT);
            break;
        case 'F':
            move(FORWARD);
            break;
        case 'B':
            move(BACK);
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}