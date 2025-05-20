//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");
    printf("Welcome to the Haunted House of Twisted Dreams\n");

    // Create a surrealist haunted house environment
    char **house = malloc(20 * sizeof(char *));
    for (int i = 0; i < 20; i++)
    {
        house[i] = malloc(10 * sizeof(char));
        house[i][0] = '\0';
    }

    // Randomly generate spooky sounds
    int sound_index = rand() % 5;
    switch (sound_index)
    {
        case 0:
            printf("Scratching on the wall...\n");
            break;
        case 1:
            printf("Footsteps in the hallway...\n");
            break;
        case 2:
            printf("Whispering voices...\n");
            break;
        case 3:
            printf("Screaming...\n");
            break;
        case 4:
            printf("The wind howling...\n");
            break;
    }

    // Create a ghostly presence
    int ghostly_presence = rand() % 2;
    switch (ghostly_presence)
    {
        case 0:
            printf("A cold wind blows through the house...\n");
            break;
        case 1:
            printf("The smell of burning incense fills the air...\n");
            break;
    }

    // Let the visitor explore the haunted house
    printf("Please enter a direction (N/S/E/W): ");
    char direction = getchar();

    // Simulate a haunted house experience
    switch (direction)
    {
        case 'N':
            printf("You move north and encounter a ghostly figure.\n");
            break;
        case 'S':
            printf("You move south and find a hidden room with a treasure.\n");
            break;
        case 'E':
            printf("You move east and hear a voice calling your name.\n");
            break;
        case 'W':
            printf("You move west and encounter a mirror that shows your future.\n");
            break;
    }

    // Free the memory used for the haunted house
    for (int i = 0; i < 20; i++)
    {
        free(house[i]);
    }
    free(house);

    // Thank the visitor for exploring the haunted house
    printf("Thank you for visiting the Haunted House of Twisted Dreams.\n");
    system("pause");
}