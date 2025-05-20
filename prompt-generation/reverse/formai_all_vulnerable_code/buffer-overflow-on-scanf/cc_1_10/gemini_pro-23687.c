//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to print the intro message
void intro()
{
    printf("\n   ___ ___  _______      __    __   _______  __       __   _______\n");
    printf("  |   |   ||   ____|    |  |  |  | |   ____||  |     |  | |   ____|\n");
    printf("  | _   _ ||  |__       |  |_|  | |  |__   |  |     |  | |  |__   \n");
    printf("  |_) | |_||   __|      |   _   | |   __|  |  |     |  | |   __|  \n");
    printf("  |_______||  |____    |  | |  | |  |____  |  `----.|  | |  |____ \n");
    printf("        |_______|    |__| |__| |_______| |_______||__| |_______|\n\n");
    printf(" Welcome to the Recursive Adventure Game!\n");
    printf(" You are about to embark on a journey through a mysterious world,\n");
    printf(" where you will encounter strange creatures, solve puzzles,\n");
    printf(" and ultimately discover your own destiny.\n\n");
    printf(" Are you ready to begin? (Y/N)\n");
}

// Function to get the player's input
char getInput()
{
    char input;
    scanf(" %c", &input);
    return input;
}

// Function to play the game
void playGame(int level)
{
    // Print the current level
    printf("\nLevel %d\n", level);

    // Check if the player has reached the end of the game
    if (level == 5)
    {
        printf("\nCongratulations! You have completed the game!\n");
        return;
    }

    // Get the player's input
    char input = getInput();

    // Check the player's input
    switch (input)
    {
    case 'N':
        // The player wants to go north
        printf("\nYou go north.\n");
        playGame(level + 1);
        break;
    case 'S':
        // The player wants to go south
        printf("\nYou go south.\n");
        playGame(level - 1);
        break;
    case 'E':
        // The player wants to go east
        printf("\nYou go east.\n");
        playGame(level + 1);
        break;
    case 'W':
        // The player wants to go west
        printf("\nYou go west.\n");
        playGame(level - 1);
        break;
    case 'Q':
        // The player wants to quit the game
        printf("\nThank you for playing!\n");
        exit(0);
        break;
    default:
        // The player entered an invalid input
        printf("\nInvalid input. Please enter N, S, E, W, or Q.\n");
        playGame(level);
    }
}

// Main function
int main()
{
    // Print the intro message
    intro();

    // Get the player's input
    char input = getInput();

    // Check the player's input
    if (input == 'Y')
    {
        // The player wants to play the game
        playGame(1);
    }
    else if (input == 'N')
    {
        // The player does not want to play the game
        printf("\nThank you for playing!\n");
    }
    else
    {
        // The player entered an invalid input
        printf("\nInvalid input. Please enter Y or N.\n");
        main();
    }

    return 0;
}