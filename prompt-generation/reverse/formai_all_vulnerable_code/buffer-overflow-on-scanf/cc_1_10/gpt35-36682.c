//FormAI DATASET v1.0 Category: Table Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_score = 0, computer_score = 0, player_choice = 0, computer_choice = 0;
    int round = 1;
    srand(time(0));

    printf("Welcome to the C Table Game!\n");
    printf("In this game, you will roll a dice against the computer.\n");
    printf("The player with the highest score at the end of three rounds wins!\n\n");

    // Start the game
    while (round <= 3)
    {
        printf("Round %d\n", round);

        // Get user's choice
        printf("Enter 1 to roll the dice: ");
        scanf("%d", &player_choice);

        // Generate computer's choice
        computer_choice = rand() % 6 + 1;

        // Display dice rolls
        printf("You rolled a %d\n", player_choice);
        printf("The computer rolled a %d\n", computer_choice);

        // Update scores
        player_score += player_choice;
        computer_score += computer_choice;

        // Display scores
        printf("Your score: %d\n", player_score);
        printf("Computer's score: %d\n\n", computer_score);

        round++;
    }

    // Display final scores
    printf("Final scores:\n");
    printf("Your score: %d\n", player_score);
    printf("Computer's score: %d\n\n", computer_score);

    // Determine winner
    if (player_score > computer_score)
    {
        printf("Congratulations! You won!\n");
    }
    else if (player_score < computer_score)
    {
        printf("Sorry, the computer won. Better luck next time!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}