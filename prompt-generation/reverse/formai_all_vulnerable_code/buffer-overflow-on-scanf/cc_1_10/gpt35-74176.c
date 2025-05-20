//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

//Function declarations
void takeOff();
void land();
void flyUp(int height);
void flyDown(int height);
void flyForward(int distance);
void flyBackward(int distance);
void turnLeft(int angle);
void turnRight(int angle);

//Main function
int main()
{
    int choice, height, distance, angle;

    printf("Welcome to the drone remote control program!\n");

    while(1)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Take off\n");
        printf("2. Land\n");
        printf("3. Fly up\n");
        printf("4. Fly down\n");
        printf("5. Fly forward\n");
        printf("6. Fly backward\n");
        printf("7. Turn left\n");
        printf("8. Turn right\n");
        printf("9. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                takeOff();
                break;

            case 2:
                land();
                break;

            case 3:
                printf("\nEnter height to fly up: ");
                scanf("%d", &height);
                flyUp(height);
                break;

            case 4:
                printf("\nEnter height to fly down: ");
                scanf("%d", &height);
                flyDown(height);
                break;

            case 5:
                printf("\nEnter distance to fly forward: ");
                scanf("%d", &distance);
                flyForward(distance);
                break;

            case 6:
                printf("\nEnter distance to fly backward: ");
                scanf("%d", &distance);
                flyBackward(distance);
                break;

            case 7:
                printf("\nEnter angle to turn left: ");
                scanf("%d", &angle);
                turnLeft(angle);
                break;

            case 8:
                printf("\nEnter angle to turn right: ");
                scanf("%d", &angle);
                turnRight(angle);
                break;

            case 9:
                printf("\nProgram Terminated!");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.");
        }

        printf("\n");
    }

    return 0;
}

//Function definitions
void takeOff()
{
    printf("\nDrone is taking off...");
}

void land()
{
    printf("\nDrone is landing...");
}

void flyUp(int height)
{
    printf("\nFlying up to a height of %d meters...", height);
}

void flyDown(int height)
{
    printf("\nFlying down to a height of %d meters...", height);
}

void flyForward(int distance)
{
    printf("\nFlying forward by %d meters...", distance);
}

void flyBackward(int distance)
{
    printf("\nFlying backward by %d meters...", distance);
}

void turnLeft(int angle)
{
    printf("\nTurning left by %d degrees...", angle);
}

void turnRight(int angle)
{
    printf("\nTurning right by %d degrees...", angle);
}