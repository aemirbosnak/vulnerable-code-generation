//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for the vehicle's dimensions and control options
#define LENGTH 100
#define WIDTH 50
#define HEIGHT 30
#define TURN_ANGLE 10
#define MOVE_DISTANCE 10

// Define variables for the vehicle's position and heading
int x_position = 0; // x-coordinate of the vehicle's position
int y_position = 0; // y-coordinate of the vehicle's position
int z_position = 0; // z-coordinate of the vehicle's position
float heading = 0; // current heading of the vehicle in degrees

// Define function to move the vehicle forward
void move_forward()
{
    x_position += (int)(MOVE_DISTANCE*cos(heading));
    y_position += (int)(MOVE_DISTANCE*sin(heading));
    printf("Vehicle moved forward. Current position: (%d, %d, %d)\n", x_position, y_position, z_position);
}

// Define function to move the vehicle backward
void move_backward()
{
    x_position -= (int)(MOVE_DISTANCE*cos(heading));
    y_position -= (int)(MOVE_DISTANCE*sin(heading));
    printf("Vehicle moved backward. Current position: (%d, %d, %d)\n", x_position, y_position, z_position);
}

// Define function to turn the vehicle left
void turn_left()
{
    heading -= TURN_ANGLE;
    printf("Vehicle turned left. Current heading: %.2f degrees\n", heading);
}

// Define function to turn the vehicle right
void turn_right()
{
    heading += TURN_ANGLE;
    printf("Vehicle turned right. Current heading: %.2f degrees\n", heading);
}

// Define function to stop the vehicle
void stop()
{
    printf("Vehicle stopped.\n");
}

int main()
{
    char input; // variable to store user input
    bool running = true; // variable to control program execution

    // Print welcome message and initial vehicle position
    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Initial vehicle position: (%d, %d, %d)\n", x_position, y_position, z_position);

    // Main loop of program
    while (running)
    {
        // Print menu and prompt for user input
        printf("\n- Menu -\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Stop\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &input);

        // Process user input and execute corresponding function
        switch (input)
        {
            case '1':
                move_forward();
                break;
            case '2':
                move_backward();
                break;
            case '3':
                turn_left();
                break;
            case '4':
                turn_right();
                break;
            case '5':
                stop();
                break;
            case '6':
                running = false;
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }

    // Print goodbye message and exit program
    printf("\nThank you for using the Remote Control Vehicle Simulator!\n");
    return 0;
}