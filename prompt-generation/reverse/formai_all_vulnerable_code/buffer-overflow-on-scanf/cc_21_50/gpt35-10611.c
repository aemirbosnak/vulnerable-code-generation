//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 30 // Maximum range of the vehicle

enum { NORTH, EAST, SOUTH, WEST }; // Enumerate directions

int main()
{
    srand(time(NULL)); // Seed the random number generator

    int x = 0, y = 0; // Starting position of the vehicle
    int direction = rand() % 4; // Randomly choose a direction to start with

    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    while (1) // Loop forever until user quits
    {
        // Display the current position and direction of the vehicle
        printf("\nCurrent position: (%d,%d)\n", x, y);
        switch (direction)
        {
        case NORTH:
            printf("Current direction: North\n");
            break;
        case EAST:
            printf("Current direction: East\n");
            break;
        case SOUTH:
            printf("Current direction: South\n");
            break;
        case WEST:
            printf("Current direction: West\n");
            break;
        }

        // Prompt the user for input and handle it accordingly
        printf("\nEnter a command (f=forward, b=backward, l=turn left, r=turn right, q=quit): ");
        char input;
        scanf(" %c", &input);
        switch (input)
        {
        case 'f': // Move forward in the current direction
            switch (direction)
            {
            case NORTH:
                y++;
                break;
            case EAST:
                x++;
                break;
            case SOUTH:
                y--;
                break;
            case WEST:
                x--;
                break;
            }
            break;
        case 'b': // Move backward in the current direction
            switch (direction)
            {
            case NORTH:
                y--;
                break;
            case EAST:
                x--;
                break;
            case SOUTH:
                y++;
                break;
            case WEST:
                x++;
                break;
            }
            break;
        case 'l': // Turn left (change direction)
            direction = (direction + 3) % 4;
            break;
        case 'r': // Turn right (change direction)
            direction = (direction + 1) % 4;
            break;
        case 'q': // Quit the program
            printf("\nThank you for using the Remote Control Vehicle Simulation!\n");
            return 0;
        default: // Invalid input
            printf("\nInvalid input. Please try again.\n");
            continue;
        }

        // Check if the vehicle is out of range
        if (abs(x) > RANGE || abs(y) > RANGE)
        {
            printf("\nOut of range. Game over!\n");
            return 0;
        }
    }

    return 0;
}