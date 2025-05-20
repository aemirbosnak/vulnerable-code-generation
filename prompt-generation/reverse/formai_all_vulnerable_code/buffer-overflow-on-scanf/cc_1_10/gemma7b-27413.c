//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char direction;
    int speed;

    // Initialize the remote control vehicle
    int x = 0;
    int y = 0;

    // Loop until the user chooses to quit
    while (1)
    {
        // Display the menu options
        printf("Enter 1 to move forward, 2 to move left, 3 to move right, 4 to move back, or 5 to quit:\n");
        scanf("%d", &choice);

        // Check if the user has chosen to quit
        if (choice == 5)
        {
            break;
        }

        // Get the direction and speed of the vehicle
        printf("Enter the direction (F/L/R/B) and speed (1-5):\n");
        scanf(" %c %d", &direction, &speed);

        // Move the vehicle
        switch (direction)
        {
            case 'F':
                y++;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'B':
                y--;
                break;
        }

        // Display the vehicle's position
        printf("The vehicle is at (%d, %d)\n", x, y);
    }

    // Quit the program
    return 0;
}