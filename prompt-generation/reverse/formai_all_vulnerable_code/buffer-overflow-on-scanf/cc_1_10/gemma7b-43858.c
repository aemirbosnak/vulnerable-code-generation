//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACK 3

void dance(int direction);

int main()
{
    int choice;

    printf("Enter your choice:\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            dance(RIGHT);
            break;
        case 2:
            dance(FORWARD);
            break;
        case 3:
            dance(BACK);
            break;
        case 4:
            dance(LEFT);
            break;
    }

    return 0;
}

void dance(int direction)
{
    switch (direction)
    {
        case LEFT:
            // Code to move robot left
            printf("Moving left...\n");
            break;
        case RIGHT:
            // Code to move robot right
            printf("Moving right...\n");
            break;
        case FORWARD:
            // Code to move robot forward
            printf("Moving forward...\n");
            break;
        case BACK:
            // Code to move robot back
            printf("Moving back...\n");
            break;
    }
}