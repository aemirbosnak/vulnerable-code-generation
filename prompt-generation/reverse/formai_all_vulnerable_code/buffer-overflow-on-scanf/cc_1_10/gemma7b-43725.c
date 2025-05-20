//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

void simulate_elevator(int floors, int current_floor, int direction, int passengers)
{
    int i, target_floor;

    // Display the current floor
    printf("Current floor: %d\n", current_floor);

    // Get the target floor
    printf("Enter target floor: ");
    scanf("%d", &target_floor);

    // Check if the direction is up or down
    if (direction == 1)
    {
        // Move up one floor at a time
        for (i = current_floor + 1; i <= target_floor; i++)
        {
            printf("Elevator moving up to floor %d\n", i);
            current_floor++;
        }
    }
    else if (direction == 2)
    {
        // Move down one floor at a time
        for (i = current_floor - 1; i >= target_floor; i--)
        {
            printf("Elevator moving down to floor %d\n", i);
            current_floor--;
        }
    }

    // Passengers leave the elevator
    passengers--;

    // Check if the elevator is still in use
    if (passengers > 0)
    {
        simulate_elevator(floors, current_floor, direction, passengers);
    }
}

int main()
{
    int floors = 10;
    int current_floor = 1;
    int direction = 1;
    int passengers = 5;

    simulate_elevator(floors, current_floor, direction, passengers);

    return 0;
}