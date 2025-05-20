//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initializes the random seed

    int grid[10][10] = {0}; // the grid for the vehicle to navigate on, initialized with zeros

    int vehicle_x = rand() % 10; // random starting x coordinate for the vehicle
    int vehicle_y = rand() % 10; // random starting y coordinate for the vehicle

    printf("Remote Control Vehicle Simulation\n\n");

    while (1) // infinite loop for continuous navigation
    {
        printf("Current location: (%d, %d)\n", vehicle_x, vehicle_y);
        printf("Enter a command (u for up, d for down, l for left, r for right, q to quit): ");
        char command;
        scanf(" %c", &command); // takes input from the user for the direction of navigation
        printf("\n");

        switch (command)
        {
            case 'u':
                if (vehicle_x > 0) // checks if the vehicle is not at the topmost row
                {
                    vehicle_x--;
                }
                else
                {
                    printf("Cannot move up anymore!\n");
                }
                break;

            case 'd':
                if (vehicle_x < 9) // checks if the vehicle is not at the bottommost row
                {
                    vehicle_x++;
                }
                else
                {
                    printf("Cannot move down anymore!\n");
                }
                break;

            case 'l':
                if (vehicle_y > 0) // checks if the vehicle is not at the leftmost column
                {
                    vehicle_y--;
                }
                else
                {
                    printf("Cannot move left anymore!\n");
                }
                break;

            case 'r':
                if (vehicle_y < 9) // checks if the vehicle is not at the rightmost column
                {
                    vehicle_y++;
                }
                else
                {
                    printf("Cannot move right anymore!\n");
                }
                break;

            case 'q':
                printf("Exiting...\n");
                exit(0); // exits the program if the user inputs 'q'
                break;

            default:
                printf("Invalid command!\n");
                break;
        }

        grid[vehicle_x][vehicle_y]++; // increments the grid value of the current coordinate

        printf("Grid:\n");
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%d ", grid[i][j]); // prints the grid values
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}