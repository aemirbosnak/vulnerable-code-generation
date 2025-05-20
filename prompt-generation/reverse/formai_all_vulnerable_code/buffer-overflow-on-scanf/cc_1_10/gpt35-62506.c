//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void printMenu();
int getSelection();
void takeOff();
void land();
void hover();
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void increaseAltitude();
void decreaseAltitude();

int main()
{
    int selection;

    // Print menu and get user selection
    printMenu();
    selection = getSelection();

    // Execute selected action
    while (selection != 9)
    {
        switch(selection)
        {
            case 1:
                takeOff();
                break;
            case 2:
                land();
                break;
            case 3:
                hover();
                break;
            case 4:
                moveForward();
                break;
            case 5:
                moveBackward();
                break;
            case 6:
                turnLeft();
                break;
            case 7:
                turnRight();
                break;
            case 8:
                increaseAltitude();
                break;
            case 9:
                decreaseAltitude();
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }

        // Print menu and get user selection
        printMenu();
        selection = getSelection();
    }

    printf("Exiting program.\n");

    return 0;
}

// Prints available actions
void printMenu()
{
    printf("\nAvailable Actions:\n");
    printf("1. Take off\n");
    printf("2. Land\n");
    printf("3. Hover\n");
    printf("4. Move Forward\n");
    printf("5. Move Backward\n");
    printf("6. Turn Left\n");
    printf("7. Turn Right\n");
    printf("8. Increase Altitude\n");
    printf("9. Decrease Altitude\n");
    printf("Please make a selection: ");
}

// Gets user selection
int getSelection()
{
    int selection;
    scanf("%d", &selection);
    return selection;
}

// Example actions
void takeOff()
{
    printf("Drone is taking off.\n");
}

void land()
{
    printf("Drone is landing.\n");
}

void hover()
{
    printf("Drone is hovering.\n");
}

void moveForward()
{
    printf("Drone is moving forward.\n");
}

void moveBackward()
{
    printf("Drone is moving backward.\n");
}

void turnLeft()
{
    printf("Drone is turning left.\n");
}

void turnRight()
{
    printf("Drone is turning right.\n");
}

void increaseAltitude()
{
    printf("Drone is increasing altitude.\n");
}

void decreaseAltitude()
{
    printf("Drone is decreasing altitude.\n");
}