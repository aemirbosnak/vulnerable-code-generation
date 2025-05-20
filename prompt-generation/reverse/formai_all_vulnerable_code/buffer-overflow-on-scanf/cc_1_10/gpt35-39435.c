//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to handle up button press
void upButton()
{
    printf("Driving forward\n");
}

// Function to handle down button press
void downButton()
{
    printf("Driving backward\n");
}

// Function to handle left button press
void leftButton()
{
    printf("Turning left\n");
}

// Function to handle right button press
void rightButton()
{
    printf("Turning right\n");
}

int main()
{
    char input[20];
    printf("Enter command (up, down, left, right): ");
    scanf("%s", input);

    // Check command and call appropriate function
    if (strcmp(input, "up") == 0)
    {
        upButton();
    }
    else if (strcmp(input, "down") == 0)
    {
        downButton();
    }
    else if (strcmp(input, "left") == 0)
    {
        leftButton();
    }
    else if (strcmp(input, "right") == 0)
    {
        rightButton();
    }
    else
    {
        printf("Invalid command\n");
    }

    return 0;
}