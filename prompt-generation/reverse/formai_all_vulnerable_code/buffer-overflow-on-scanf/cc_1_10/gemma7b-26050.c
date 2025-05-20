//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void elevator_simulator(int floor_num)
{
    int current_floor = 1;
    int target_floor;
    char direction;

    printf("Current floor: %d\n", current_floor);
    printf("Enter target floor: ");
    scanf("%d", &target_floor);

    // Calculate direction
    if (target_floor > current_floor)
    {
        direction = 'U';
    }
    else
    {
        direction = 'D';
    }

    // Move the elevator
    for (int i = 0; i < floor_num; i++)
    {
        if (current_floor == target_floor)
        {
            printf("Reached target floor: %d\n", current_floor);
            break;
        }

        current_floor++;
        if (direction == 'U')
        {
            printf("Moving up to floor: %d\n", current_floor);
        }
        else
        {
            printf("Moving down to floor: %d\n", current_floor);
        }
    }

    // If the elevator reaches the target floor, print a message
    if (current_floor == target_floor)
    {
        printf("Reached target floor: %d\n", current_floor);
    }
    else
    {
        printf("Error: target floor not reached.\n");
    }
}

int main()
{
    elevator_simulator(10);

    return 0;
}