//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_MSG_LENGTH 100

// Function declarations
void clear_screen();
void display_intro();
void display_options();
void play_game();

int main()
{
    clear_screen();
    display_intro();
    display_options();
    play_game();
    return 0;
}

// Function definitions

void clear_screen()
{
    printf("\033[H\033[J");
}

void display_intro()
{
    printf("Welcome to Real Life Adventure Game!\n");
    printf("In this game, you will face various challenges and make decisions that will determine your success.\n");
    printf("\n\nPress enter to continue...");
    while (getchar() != '\n');
}

void display_options()
{
    printf("\n\nHere are your options:\n");
    printf("1. Get a job\n");
    printf("2. Start a business\n");
    printf("3. Travel the world\n");
    printf("4. Buy a house\n");
    printf("\nEnter your option number: ");
}

void play_game()
{
    char name[MAX_NAME_LENGTH];
    char msg[MAX_MSG_LENGTH];
    int choice;

    // get player's name
    printf("\n\nPlease enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    strtok(name, "\n");

    // welcome message
    printf("\nWelcome, %s! Let's get started.\n", name);

    // start game loop
    while (true)
    {
        display_options();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                printf("\n\nYou got a job and started earning money.");
                printf("\nCongratulations, %s! You are on your way to success.", name);
                break;

            case 2:
                printf("\n\nYou started a business and became your own boss.");
                printf("\nGood luck with your business, %s!", name);
                break;

            case 3:
                printf("\n\nYou traveled the world and had amazing experiences.");
                printf("\nHope you had a great time, %s!", name);
                break;

            case 4:
                printf("\n\nYou bought a house and started building your home.");
                printf("\nCheers, %s! You are now a homeowner.", name);
                break;

            default:
                printf("\nInvalid option. Please try again.");
                break;
        }

        // ask player to continue or quit
        printf("\n\nDo you want to play again? (y/n): ");
        fgets(msg, MAX_MSG_LENGTH, stdin);
        strtok(msg, "\n");

        if (strcmp(msg, "n") == 0)
        {
            break;
        }
    }

    printf("\nThanks for playing, %s! See you again soon.\n", name);
}