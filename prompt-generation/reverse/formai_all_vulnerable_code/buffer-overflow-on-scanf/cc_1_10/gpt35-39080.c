//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 100 // Maximum Speed of RC Vehicle
#define MIN_SPEED 0 // Minimum Speed of RC Vehicle
#define MAX_ANGLE 90 // Maximum Steering Angle
#define MIN_ANGLE -90 // Minimum Steering Angle
#define MAX_DISTANCE 100 // Maximum Distance Travelled by RC Vehicle

void moveForward(int speed, int distance);
void moveBackward(int speed, int distance);
void turnRight(int angle);
void turnLeft(int angle);

int main()
{
    int speed = 0;
    int distance = 0;
    int angle = 0;
    char input = ' ';

    printf("Welcome to RC Vehicle Simulation!\n");

    while(true)
    {
        printf("\nCurrent Speed: %d\n", speed);
        printf("Current Distance Travelled: %d\n", distance);
        printf("Current Angle: %d\n\n", angle);

        printf("Enter command (F = Forward, B = Backward, R = Turn Right, L = Turn Left, Q = Quit): ");
        scanf(" %c", &input);

        switch(input)
        {
            case 'F':
            case 'f':
                printf("Enter speed (0-100): ");
                scanf("%d", &speed);

                if(speed < MIN_SPEED || speed > MAX_SPEED)
                {
                    printf("Invalid Speed! Speed should be between 0 and 100.\n");
                }
                else
                {
                    printf("Enter distance (0-100): ");
                    scanf("%d", &distance);

                    if(distance < 0 || distance > MAX_DISTANCE)
                    {
                        printf("Invalid Distance! Distance should be between 0 and 100.\n");
                    }
                    else
                    {
                        moveForward(speed, distance);
                    }
                }
                break;

            case 'B':
            case 'b':
                printf("Enter speed (0-100): ");
                scanf("%d", &speed);

                if(speed < MIN_SPEED || speed > MAX_SPEED)
                {
                    printf("Invalid Speed! Speed should be between 0 and 100.\n");
                }
                else
                {
                    printf("Enter distance (0-100): ");
                    scanf("%d", &distance);

                    if(distance < 0 || distance > MAX_DISTANCE)
                    {
                        printf("Invalid Distance! Distance should be between 0 and 100.\n");
                    }
                    else
                    {
                        moveBackward(speed, distance);
                    }
                }
                break;

            case 'R':
            case 'r':
                printf("Enter angle (-90 to 90): ");
                scanf("%d", &angle);

                if(angle < MIN_ANGLE || angle > MAX_ANGLE)
                {
                    printf("Invalid Angle! Angle should be between -90 and 90.\n");
                }
                else
                {
                    turnRight(angle);
                }
                break;

            case 'L':
            case 'l':
                printf("Enter angle (-90 to 90): ");
                scanf("%d", &angle);

                if(angle < MIN_ANGLE || angle > MAX_ANGLE)
                {
                    printf("Invalid Angle! Angle should be between -90 and 90.\n");
                }
                else
                {
                    turnLeft(angle);
                }
                break;

            case 'Q':
            case 'q':
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid Command! Please try again.\n");
                break;
        }
    }

    return 0;
}

void moveForward(int speed, int distance)
{
    printf("Moving Forward with speed %d and distance %d.\n", speed, distance);
}

void moveBackward(int speed, int distance)
{
    printf("Moving Backward with speed %d and distance %d.\n", speed, distance);
}

void turnRight(int angle)
{
    printf("Turning Right with angle %d.\n", angle);
}

void turnLeft(int angle)
{
    printf("Turning Left with angle %d.\n", angle);
}