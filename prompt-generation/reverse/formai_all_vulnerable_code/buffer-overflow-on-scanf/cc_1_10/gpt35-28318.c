//FormAI DATASET v1.0 Category: Robot movement control ; Style: expert-level
#include <stdio.h>  // Standard IO Library
#include <stdlib.h> // Standard Library

// Constants for robot movement
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// Function declarations
void move_forward(int distance);
void move_backward(int distance);
void turn_left();
void turn_right();

// Global variables for robot position
int x = 0;
int y = 0;

int main()
{
    int input = 0;
    int distance = 0;

    // Main control loop
    while (input != 5)
    {
        // Display menu options
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Exit\n");
        printf("Enter option: ");

        // Get user input
        scanf("%d", &input);

        // Execute selected option
        switch (input)
        {
            case 1:
                printf("Enter distance to move: ");
                scanf("%d", &distance);
                move_forward(distance);
                break;
            case 2:
                printf("Enter distance to move: ");
                scanf("%d", &distance);
                move_backward(distance);
                break;
            case 3:
                turn_left();
                break;
            case 4:
                turn_right();
                break;
            case 5:
                break;
            default:
                printf("Invalid option!\n");
                break;
        }

        // Print current position
        printf("Current position: (%d,%d)\n", x, y);
        printf("\n");
    }

    return 0;
}

// Function to move the robot forward a specified distance
void move_forward(int distance)
{
    int i;
    for (i = 0; i < distance; i++)
    {
        x++;
        printf("Moving robot FORWARD to position (%d,%d)\n", x, y);
    }
}

// Function to move the robot backward a specified distance
void move_backward(int distance)
{
    int i;
    for (i = 0; i < distance; i++)
    {
        x--;
        printf("Moving robot BACKWARD to position (%d,%d)\n", x, y);
    }
}

// Function to turn the robot left
void turn_left()
{
    printf("Turning robot LEFT\n");
}

// Function to turn the robot right
void turn_right()
{
    printf("Turning robot RIGHT\n");
}