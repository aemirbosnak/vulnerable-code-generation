//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Haunted Mansion of Morrigan Manor!\n");

    // Create a haunted atmosphere
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("The wind howls through the crumbling walls...\n");
        sleep(1);
    }

    // Introduce the haunted resident
    printf("Suddenly, a cold hand brushes against your skin...\n");
    sleep(1);
    printf("A disembodied voice whispers in your ear, 'Do you dare enter...?'\n");

    // Offer a choice
    int choice = 0;
    printf("Do you want to (1) flee or (2) investigate?\n");
    scanf("%d", &choice);

    // Respond to the choice
    switch (choice)
    {
        case 1:
            printf("You flee in terror, but the sound of footsteps follows you...\n");
            sleep(1);
            printf("The haunted voice echoes, 'You can't escape...!'");
            break;
        case 2:
            printf("You gather your courage and investigate...\n");
            sleep(1);
            printf("You find a hidden room, filled with ghosts and treasures...\n");
            break;
        default:
            printf("Invalid input. Please try again.\n");
    }

    // End the game
    printf("Thank you for visiting Morrigan Manor. May your spirit be with you...\n");
    sleep(2);
    system("clear");

    return 0;
}