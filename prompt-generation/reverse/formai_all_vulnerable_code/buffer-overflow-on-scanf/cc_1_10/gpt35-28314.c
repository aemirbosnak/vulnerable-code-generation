//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declarations
void intro();
void instructions();
void forest();
void river();
void mountain();

// main function
int main()
{
    char choice[20];
    intro();
    instructions();
    printf("\n\n");

    // run the game loop until the player chooses to quit
    while (1)
    {
        printf("What would you like to do? ");
        scanf("%s", choice);

        if (strcmp(choice, "explore") == 0)
        {
            printf("\nYou have entered the forest.\n\n");
            forest();
        }
        else if (strcmp(choice, "swim") == 0)
        {
            printf("\nYou have entered the river.\n\n");
            river();
        }
        else if (strcmp(choice, "climb") == 0)
        {
            printf("\nYou have entered the mountain.\n\n");
            mountain();
        }
        else if (strcmp(choice, "quit") == 0)
        {
            printf("\nThanks for playing! Goodbye!\n");
            exit(0);
        }
        else
        {
            printf("\nSorry, I didn't understand that. Please try again.\n");
        }
    }

    return 0;
}

// function to display the game intro
void intro()
{
    printf("---------------------------------------------\n");
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("---------------------------------------------\n\n");
}

// function to display the game instructions
void instructions()
{
    printf("You are standing at the edge of a vast wilderness. You have three options:\n");
    printf("- explore the forest\n");
    printf("- swim across the river\n");
    printf("- climb the mountain\n");
    printf("What would you like to do?\n");
}

// function to handle the forest scenario
void forest()
{
    char choice[20];
    printf("You see a path leading deeper into the forest. Do you want to follow it? ");
    scanf("%s", choice);
    if (strcmp(choice, "yes") == 0)
    {
        printf("\nYou follow the path and find a small clearing with a chest.\n");
        printf("You open the chest and find a magic sword!\n");
    }
    else if (strcmp(choice, "no") == 0)
    {
        printf("\nYou decide not to follow the path.\n");
    }
    else
    {
        printf("\nSorry, I didn't understand that. Please try again.\n");
    }
}

// function to handle the river scenario
void river()
{
    char choice[20];
    printf("You have reached the river. Do you want to swim across it? ");
    scanf("%s", choice);
    if (strcmp(choice, "yes") == 0)
    {
        printf("\nYou start to swim, but the current is too strong and you are swept downstream.\n");
        printf("You wash up on the shore far from where you started.\n");
    }
    else if (strcmp(choice, "no") == 0)
    {
        printf("\nYou decide not to swim across the river.\n");
    }
    else
    {
        printf("\nSorry, I didn't understand that. Please try again.\n");
    }
}

// function to handle the mountain scenario
void mountain()
{
    char choice[20];
    printf("You have started climbing the mountain. Do you want to continue? ");
    scanf("%s", choice);
    if (strcmp(choice, "yes") == 0)
    {
        printf("\nYou keep climbing higher and higher. Finally, you reach the top and find a treasure chest!\n");
        printf("You open the chest and find a magical crystal!\n");
    }
    else if (strcmp(choice, "no") == 0)
    {
        printf("\nYou decide not to climb the mountain.\n");
    }
    else
    {
        printf("\nSorry, I didn't understand that. Please try again.\n");
    }
}