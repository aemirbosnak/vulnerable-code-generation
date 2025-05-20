//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void simulate_elevator(int floor_num);

int main()
{
    int floor_num;

    printf("Enter the number of floors: ");
    scanf("%d", &floor_num);

    simulate_elevator(floor_num);

    return 0;
}

void simulate_elevator(int floor_num)
{
    int current_floor = 1;
    int destination_floor;
    char direction;

    printf("Current floor: %d\n", current_floor);

    // Get the destination floor
    printf("Enter the destination floor: ");
    scanf("%d", &destination_floor);

    // Calculate the direction
    if (destination_floor > current_floor)
    {
        direction = 'U';
    }
    else
    {
        direction = 'D';
    }

    // Simulate the elevator moving
    for (int i = 0; i < floor_num - current_floor + 1; i++)
    {
        printf("Elevator moving %c...\n", direction);
        current_floor++;
        if (current_floor == destination_floor)
        {
            break;
        }
    }

    // Destination floor reached
    printf("Destination floor reached: %d\n", destination_floor);
}