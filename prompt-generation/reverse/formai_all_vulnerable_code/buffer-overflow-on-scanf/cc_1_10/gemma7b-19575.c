//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    system("cls");
    srand(time(NULL));

    // Create a haunted house
    char house[100] = "----------------------------------------------------------------------------------------------------\n"
                           "                                 /|\n"
                           "                                | \n"
                           "                                 \|\n"
                           "----------------------------------------------------------------------------------------------------\n"
                           "The front door creaks open, and a cold wind blows through the halls.\n"
                           "A ghostly figure, shrouded in mystery, appears before you.\n"
                           "The smell of decaying flesh and burning incense fills the air.\n"
                           "Your heart jumps out of your chest.\n"
                           "What do you do?\n";

    // Display the haunted house
    printf("%s", house);

    // Get the user's input
    char input[20];
    printf("Enter your input: ");
    scanf("%s", input);

    // Check if the user's input is valid
    if (strcmp(input, " flee") == 0)
    {
        // The user flees the haunted house
        system("cls");
        printf("You flee the haunted house, but the ghostly figure is still there.\n");
    }
    else if (strcmp(input, " confront") == 0)
    {
        // The user confronts the ghostly figure
        system("cls");
        printf("You confront the ghostly figure, but it disappears into thin air.\n");
    }
    else
    {
        // The user's input is invalid
        system("cls");
        printf("Your input is invalid. Please try again.\n");
    }

    // Pause the program
    pause();
}