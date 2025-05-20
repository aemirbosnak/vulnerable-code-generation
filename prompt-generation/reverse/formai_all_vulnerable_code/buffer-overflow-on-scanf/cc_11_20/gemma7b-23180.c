//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Alan Turing
#include <stdio.h>

int main()
{
    int floor, current_floor = 1, direction = 0, passengers = 0;
    char command;

    printf("Enter command (U/D/S/P/E): ");
    scanf("%c", &command);

    switch (command)
    {
        case 'U':
            direction = 1;
            break;
        case 'D':
            direction = -1;
            break;
        case 'S':
            direction = 0;
            break;
        case 'P':
            passengers++;
            break;
        case 'E':
            current_floor = 1;
            passengers = 0;
            break;
    }

    switch (direction)
    {
        case 1:
            if (current_floor < 10)
            {
                current_floor++;
                printf("Current floor: %d\n", current_floor);
            }
            else
            {
                printf("Reached top floor!\n");
            }
            break;
        case -1:
            if (current_floor > 1)
            {
                current_floor--;
                printf("Current floor: %d\n", current_floor);
            }
            else
            {
                printf("Reached ground floor!\n");
            }
            break;
        case 0:
            printf("Current floor: %d\n", current_floor);
            break;
    }

    printf("Number of passengers: %d\n", passengers);

    return 0;
}