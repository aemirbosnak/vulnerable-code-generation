//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor, choice;

    printf("Welcome to the Capulet and Montague Elevator!\n");
    printf("Please select your floor: ");

    scanf("%d", &floor);

    switch (floor)
    {
        case 1:
            printf("You are on the first floor.\n");
            break;
        case 2:
            printf("You are on the second floor.\n");
            break;
        case 3:
            printf("You are on the third floor.\n");
            break;
        default:
            printf("Invalid floor number.\n");
            break;
    }

    printf("Would you like to go up or down? (1/2): ");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Going up...\n");
            floor++;
            printf("You are on the %d floor.\n", floor);
            break;
        case 2:
            printf("Going down...\n");
            floor--;
            printf("You are on the %d floor.\n", floor);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}