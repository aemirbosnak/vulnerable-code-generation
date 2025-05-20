//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor_num;
    char direction;
    int current_floor = 1;

    // Create a list of floors
    int floors[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Display the current floor
    printf("Current floor: %d\n", current_floor);

    // Get the floor number and direction
    printf("Enter floor number: ");
    scanf("%d", &floor_num);

    // Get the direction
    printf("Enter direction (U/D): ");
    scanf(" %c", &direction);

    // Move the elevator
    switch (direction)
    {
        case 'U':
            if (current_floor < floor_num)
            {
                current_floor++;
                printf("Moving up to floor %d...\n", current_floor);
            }
            else
            {
                printf("Already on floor %d.\n", current_floor);
            }
            break;
        case 'D':
            if (current_floor > floor_num)
            {
                current_floor--;
                printf("Moving down to floor %d...\n", current_floor);
            }
            else
            {
                printf("Already on floor %d.\n", current_floor);
            }
            break;
        default:
            printf("Invalid direction.\n");
    }

    // Display the current floor
    printf("Current floor: %d\n", current_floor);

    return 0;
}