//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor, current_floor = 1, direction = 1, floors_num = 10;
    char direction_arrow;

    printf("Welcome to the shape-shifting elevator simulator!\n");
    printf("Current floor: %d\n", current_floor);

    // Loop until the user enters 'q' or reaches the desired floor
    while (direction != 0)
    {
        printf("Enter direction (u/d/q): ");
        scanf(" %c", &direction_arrow);

        switch (direction_arrow)
        {
            case 'u':
                current_floor++;
                if (current_floor > floors_num)
                {
                    current_floor = floors_num;
                    printf("Reached the top floor!\n");
                }
                break;
            case 'd':
                current_floor--;
                if (current_floor < 1)
                {
                    current_floor = 1;
                    printf("Reached the ground floor!\n");
                }
                break;
            case 'q':
                direction = 0;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        printf("Current floor: %d\n", current_floor);
    }

    printf("Thank you for using the shape-shifting elevator simulator!\n");

    return 0;
}