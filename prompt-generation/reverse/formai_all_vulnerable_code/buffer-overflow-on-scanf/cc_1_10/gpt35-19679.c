//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

//function declarations
void takeOff();
void land();
void moveForward();
void moveBackward();
void moveLeft();
void moveRight();

//global variable
int batteryRemaining = 100;

//main function
int main()
{
    int choice;
    printf("Welcome to C Drone Remote Control!\n");
    while(1)
    {
        printf("Current battery percentage: %d\n", batteryRemaining);
        printf("Please select one of the following options:\n");
        printf("1. Take off\n");
        printf("2. Land\n");
        printf("3. Move Forward\n");
        printf("4. Move Backward\n");
        printf("5. Move Left\n");
        printf("6. Move Right\n");
        printf("7. Exit remote control\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: takeOff(); break;
            case 2: land(); break;
            case 3: moveForward(); break;
            case 4: moveBackward(); break;
            case 5: moveLeft(); break;
            case 6: moveRight(); break;
            case 7: printf("Exiting remote control...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n"); break;
        }
    }

    return 0;
}

//function definitions
void takeOff()
{
    if(batteryRemaining <= 0)
    {
        printf("Battery is dead. Please recharge and try again.\n");
        return;
    }

    printf("Drone is taking off...\n");
    batteryRemaining -= 10;
    printf("Battery remaining: %d\n", batteryRemaining);
}

void land()
{
    if(batteryRemaining <= 0)
    {
        printf("Battery is dead. Please recharge and try again.\n");
        return;
    }

    printf("Drone is landing...\n");
    batteryRemaining -= 10;
    printf("Battery remaining: %d\n", batteryRemaining);
}

void moveForward()
{
    if(batteryRemaining <= 0)
    {
        printf("Battery is dead. Please recharge and try again.\n");
        return;
    }

    printf("Drone is moving forward...\n");
    batteryRemaining -= 5;
    printf("Battery remaining: %d\n", batteryRemaining);
}

void moveBackward()
{
    if(batteryRemaining <= 0)
    {
        printf("Battery is dead. Please recharge and try again.\n");
        return;
    }

    printf("Drone is moving backward...\n");
    batteryRemaining -= 5;
    printf("Battery remaining: %d\n", batteryRemaining);
}

void moveLeft()
{
    if(batteryRemaining <= 0)
    {
        printf("Battery is dead. Please recharge and try again.\n");
        return;
    }

    printf("Drone is moving left...\n");
    batteryRemaining -= 5;
    printf("Battery remaining: %d\n", batteryRemaining);
}

void moveRight()
{
    if(batteryRemaining <= 0)
    {
        printf("Battery is dead. Please recharge and try again.\n");
        return;
    }

    printf("Drone is moving right...\n");
    batteryRemaining -= 5;
    printf("Battery remaining: %d\n", batteryRemaining);
}