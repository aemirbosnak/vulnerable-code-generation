//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, speed, direction;

    // Initialize the car
    int x = 0, y = 0;
    char direction_char = 'N';

    // Main loop
    while (1)
    {
        // Display the menu
        printf("Enter 1 to move forward, 2 to move right, 3 to move back, 4 to move left, 5 to stop:\n");
        scanf("%d", &choice);

        // Check the choice
        switch (choice)
        {
            case 1:
                speed = 5;
                direction = 1;
                break;
            case 2:
                speed = 5;
                direction = 2;
                break;
            case 3:
                speed = 5;
                direction = 3;
                break;
            case 4:
                speed = 5;
                direction = 4;
                break;
            case 5:
                speed = 0;
                direction = 0;
                break;
            default:
                printf("Invalid input.\n");
                continue;
        }

        // Move the car
        switch (direction)
        {
            case 1:
                x++;
                direction_char = 'F';
                break;
            case 2:
                y++;
                direction_char = 'R';
                break;
            case 3:
                x--;
                direction_char = 'B';
                break;
            case 4:
                y--;
                direction_char = 'L';
                break;
            case 0:
                printf("Car stopped.\n");
                x = 0;
                y = 0;
                direction_char = 'N';
                break;
        }

        // Display the car's position
        printf("Car position: (%d, %d), direction: %c\n", x, y, direction_char);
    }

    return 0;
}