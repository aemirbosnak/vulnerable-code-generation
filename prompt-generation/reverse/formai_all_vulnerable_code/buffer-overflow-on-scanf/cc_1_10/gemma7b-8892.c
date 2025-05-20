//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

void moveForward(int speed);
void moveRight(int speed);
void moveLeft(int speed);
void moveBack(int speed);

int main()
{
    int speed = 0;
    char command = ' ';

    printf("Press 'w' to move forward, 'a' to move left, 'd' to move right, 's' to move back:\n");

    while (command != 'q')
    {
        scanf(" %c", &command);

        switch (command)
        {
            case 'w':
                moveForward(speed);
                break;
            case 'a':
                moveLeft(speed);
                break;
            case 'd':
                moveRight(speed);
                break;
            case 's':
                moveBack(speed);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}

void moveForward(int speed)
{
    printf("Moving forward at speed %d...\n", speed);
}

void moveRight(int speed)
{
    printf("Moving right at speed %d...\n", speed);
}

void moveLeft(int speed)
{
    printf("Moving left at speed %d...\n", speed);
}

void moveBack(int speed)
{
    printf("Moving back at speed %d...\n", speed);
}