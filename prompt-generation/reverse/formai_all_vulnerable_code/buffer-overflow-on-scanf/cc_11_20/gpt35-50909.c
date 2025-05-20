//FormAI DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_score = 0, computer_score = 0, round = 0, player_choice = 0, computer_choice = 0;

    srand(time(NULL)); // seed for randomness

    printf("Welcome to the C Table Game!\n");

    do
    {
        round++;

        printf("Round %d\n\n", round);

        // Player's turn
        printf("Your turn!\n");
        printf("1. Rock\n2. Paper\n3. Scissors\nEnter your choice: ");
        scanf("%d", &player_choice);

        switch (player_choice)
        {
            case 1:
                printf("You chose Rock.\n");
                break;
            case 2:
                printf("You chose Paper.\n");
                break;
            case 3:
                printf("You chose Scissors.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
                round--;
                continue; // skips to the next iteration of the loop
        }

        // Computer's turn
        computer_choice = rand() % 3 + 1;

        switch (computer_choice)
        {
            case 1:
                printf("Computer chose Rock.\n");
                break;
            case 2:
                printf("Computer chose Paper.\n");
                break;
            case 3:
                printf("Computer chose Scissors.\n");
                break;
        }

        // Determines winner and updates scores
        if (player_choice == computer_choice)
        {
            printf("It's a tie!\n\n");
        }
        else if ((player_choice == 1 && computer_choice == 3) || (player_choice == 2 && computer_choice == 1) || (player_choice == 3 && computer_choice == 2))
        {
            printf("You win this round!\n\n");
            player_score++;
        }
        else
        {
            printf("Computer wins this round!\n\n");
            computer_score++;
        }

        // Displays current score
        printf("Current score:\nYou: %d\tComputer: %d\n\n", player_score, computer_score);

    } while (player_score < 5 && computer_score < 5); // first player to win 5 rounds wins the game

    // Determines overall winner and displays final score
    if (player_score == computer_score)
    {
        printf("It's a tie!\n");
    }
    else if (player_score > computer_score)
    {
        printf("Congratulations! You win!\n");
    }
    else
    {
        printf("Better luck next time. Computer wins!\n");
    }

    printf("Final score:\nYou: %d\tComputer: %d\n", player_score, computer_score);

    return 0;
}