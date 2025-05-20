//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void takeOff(char direction);
void land();
void moveForward(int speed);
void moveBackward(int speed);
void turnLeft(int angle);
void turnRight(int angle);
void displayCommands();

int main()
{
    // Greeting message
    printf("\nWelcome to Awesome C Drone Remote Control!\n\n");
    
    // Display available commands
    displayCommands();
    
    bool isOn = true;
    char command;
    
    // Command loop
    while(isOn)
    {
        printf("Enter command: ");
        scanf(" %c", &command);
        
        switch(command)
        {
            case 't':
                printf("Taking off...\n");
                printf("Enter direction (f/b/l/r): ");
                char direction;
                scanf(" %c", &direction);
                takeOff(direction);
                break;
            case 'l':
                printf("Landing...\n");
                land();
                isOn = false;
                break;
            case 'f':
                printf("Moving forward...\n");
                int speed;
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveForward(speed);
                break;
            case 'b':
                printf("Moving backward...\n");
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveBackward(speed);
                break;
            case 'L':
                printf("Turning left...\n");
                int angle;
                printf("Enter angle (1-360): ");
                scanf("%d", &angle);
                turnLeft(angle);
                break;
            case 'R':
                printf("Turning right...\n");
                printf("Enter angle (1-360): ");
                scanf("%d", &angle);
                turnRight(angle);
                break;
            case 'h':
                printf("Displaying available commands...\n");
                displayCommands();
                break;
            default:
                printf("Invalid command. Please enter 'h' for help.\n");
                break;
        }
    }
    
    // Goodbye message
    printf("\nThank you for using Awesome C Drone Remote Control!\n\n");
    
    return 0;
}

// Function implementations
void takeOff(char direction)
{
    switch(direction)
    {
        case 'f':
            printf("Moving forward...\n");
            break;
        case 'b':
            printf("Moving backward...\n");
            break;
        case 'l':
            printf("Moving left...\n");
            break;
        case 'r':
            printf("Moving right...\n");
            break;
        default:
            printf("Invalid direction. Please try again.\n");
            break;
    }
}

void land()
{
    printf("Landing...\n");
}

void moveForward(int speed)
{
    if(speed <= 0 || speed > 10)
    {
        printf("Invalid speed. Please enter a number between 1 and 10.\n");
    }
    else
    {
        printf("Moving forward with speed %d.\n", speed);
    }
}

void moveBackward(int speed)
{
    if(speed <= 0 || speed > 10)
    {
        printf("Invalid speed. Please enter a number between 1 and 10.\n");
    }
    else
    {
        printf("Moving backward with speed %d.\n", speed);
    }
}

void turnLeft(int angle)
{
    if(angle <= 0 || angle > 360)
    {
        printf("Invalid angle. Please enter a number between 1 and 360.\n");
    }
    else
    {
        printf("Turning left by %d degrees.\n", angle);
    }
}

void turnRight(int angle)
{
    if(angle <= 0 || angle > 360)
    {
        printf("Invalid angle. Please enter a number between 1 and 360.\n");
    }
    else
    {
        printf("Turning right by %d degrees.\n", angle);
    }
}

void displayCommands()
{
    printf("Available commands:\n");
    printf("'t' - take off\n");
    printf("'l' - land\n");
    printf("'f' - move forward\n");
    printf("'b' - move backward\n");
    printf("'L' - turn left\n");
    printf("'R' - turn right\n");
    printf("'h' - display available commands\n");
}