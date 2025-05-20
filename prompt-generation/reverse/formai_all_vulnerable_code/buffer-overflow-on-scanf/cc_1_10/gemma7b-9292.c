//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int floor);

int main()
{
    int floor = 1;

    // Initialize the random number generator
    srand(time(NULL));

    // Loop until the user chooses to exit
    while (floor)
    {
        // Display the current floor
        printf("You are on floor %d.\n", floor);

        // Create a random event
        int event = rand() % 3;

        // Handle the event
        switch (event)
        {
            case 0:
                printf("You hear a noise in the hallway.\n");
                break;
            case 1:
                printf("You see a ghostly figure hovering near you.\n");
                break;
            case 2:
                printf("You smell a strong scent of decay and blood.\n");
                break;
        }

        // Ask the user if they want to go to the next floor
        printf("Do you want to go to the next floor? (y/n) ");
        char answer;
        scanf("%c", &answer);

        // Check if the user wants to go to the next floor
        if (answer == 'y')
        {
            floor++;
        }
        else
        {
            printf("Thank you for visiting the haunted house.\n");
            floor = 0;
        }
    }

    return 0;
}

void haunted_house(int floor)
{
    // This function simulates the haunted house for a particular floor
    // The function does not return any value

    // Display the haunted house for the current floor
    switch (floor)
    {
        case 1:
            printf("The house is dark and silent. You hear the sound of your own breathing.\n");
            break;
        case 2:
            printf("The house is filled with the sound of voices and screams. You feel a cold hand brush against your skin.\n");
            break;
        case 3:
            printf("The house is a fiery inferno. You smell the smell of burning flesh and blood.\n");
            break;
    }
}