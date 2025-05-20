//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the Text-Based Adventure Game!\n\n");

    // Set the seed for random number generation
    srand(time(NULL));

    // Possible outcomes for the game
    char outcomes[3][50] = {"You win!",
                            "You lose!",
                            "You stumble upon a hidden treasure!"};

    // Initialize variables
    int choice;
    int outcome_index;

    // Prompt user for input
    printf("To start the game, enter 1.\n");

    // Get user input
    scanf("%d", &choice);

    // Check if input is valid
    if(choice != 1)
    {
        printf("Invalid input. Exiting game.\n");
        return 0;
    }

    // Generate a random outcome for the game
    outcome_index = rand() % 3;

    // Display outcome
    printf("%s\n", outcomes[outcome_index]);

    // Check if player found treasure
    if(outcome_index == 2)
    {
        printf("You found the treasure! Congratulations!\n");
        return 0;
    }

    // If player didn't win, prompt them to try again
    printf("Would you like to try again? Enter 1 for yes, 0 for no.\n");

    scanf("%d", &choice);

    // Check if input is valid
    if(choice != 0 && choice != 1)
    {
        printf("Invalid input. Exiting game.\n");
        return 0;
    }

    // If they want to play again, recursively call main function
    if(choice == 1)
    {
        main();
    }

    return 0;
}