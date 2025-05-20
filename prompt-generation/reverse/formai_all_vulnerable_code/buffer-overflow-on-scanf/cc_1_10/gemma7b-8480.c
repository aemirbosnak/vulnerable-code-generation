//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int choice, speed, direction;
    char direction_char;

    // Initialize the car's position
    int x = 0;
    int y = 0;

    // Loop until the user chooses to quit
    while (1)
    {
        // Display the menu options
        printf("Enter 1 to move forward, 2 to move right, 3 to move back, 4 to move left, or 5 to quit: ");

        // Get the user's choice
        scanf("%d", &choice);

        // Check if the user has chosen to quit
        if (choice == 5)
        {
            break;
        }

        // Get the user's desired speed
        printf("Enter the speed (1-10): ");
        scanf("%d", &speed);

        // Get the user's desired direction
        printf("Enter the direction (N, E, S, W): ");
        scanf(" %c", &direction_char);

        // Convert the direction character to an integer
        direction = direction_char - 'A';

        // Move the car
        switch (direction)
        {
            case 0:
                x++;
                break;
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y--;
                break;
        }

        // Display the car's position
        printf("The car is at (%d, %d).", x, y);

        // Pause for a bit
        sleep(speed);
    }

    // Exit the program
    return 0;
}