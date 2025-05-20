//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
// This is an imaginative C Table Game example program

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // Declare variables
    int player_score = 0;
    int computer_score = 0;
    int turn = 1;
    int player_choice, computer_choice, point;

    // Set random seed
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the Table Game!\n");
    printf("You will be playing against the computer.\n");
    printf("The goal of the game is to reach 21 points.\n");
    printf("You will take turns rolling a die.\n");
    printf("Each roll will add points to your score.\n");
    printf("Beware, if you roll a 1, you lose all the points in your turn!\n\n");

    // Game loop
    while (player_score < 21 && computer_score < 21)
    {
        printf("Turn %d:\n", turn);

        // Player's turn
        printf("Roll the die (enter 1 to roll): ");
        scanf("%d", &player_choice);

        if (player_choice == 1)
        {
            point = rand() % 6 + 1;

            printf("You rolled a %d.\n", point);

            if (point == 1)
            {
                printf("You lost all your points this turn!\n");
                player_score = 0;
            }
            else
            {
                player_score += point;
            }
        }

        // Computer's turn
        computer_choice = rand() % 2 + 1;

        if (computer_choice == 1)
        {
            point = rand() % 6 + 1;

            printf("The computer rolled a %d.\n", point);

            if (point == 1)
            {
                printf("The computer lost all its points this turn!\n");
                computer_score = 0;
            }
            else
            {
                computer_score += point;
            }
        }

        printf("Your score: %d\n", player_score);
        printf("Computer's score: %d\n\n", computer_score);

        // Increment turn
        turn++;
    }

    // Determine winner
    if (player_score >= 21)
    {
        printf("Congratulations, you win!\n");
    }
    else
    {
        printf("The computer wins, better luck next time!\n");
    }

    return 0;
}