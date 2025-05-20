//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player_score = 0;
    int computer_score = 0;
    int round;

    srand(time(NULL)); // Seed for random number generation

    printf("WELCOME TO THE DECNETRALIZED GAME!\n\n");

    // Game loop
    for(round = 1; round <= 10; round++)
    {
        int player_choice, computer_choice;

        printf("ROUND %d\n", round);

        // Player input
        do
        {
            printf("Choose your weapon (1 for rock, 2 for paper, 3 for scissors): ");
            scanf("%d", &player_choice);
        } while(player_choice < 1 || player_choice > 3);

        // Computer input (random)
        computer_choice = rand() % 3 + 1; // Generate random number between 1 and 3

        // Determine winner
        if(player_choice == computer_choice)
        {
            printf("It's a tie!\n");
        }
        else if(player_choice == 1 && computer_choice == 3 ||
                player_choice == 2 && computer_choice == 1 ||
                player_choice == 3 && computer_choice == 2)
        {
            printf("You win this round!\n");
            player_score++;
        }
        else
        {
            printf("The computer wins this round!\n");
            computer_score++;
        }

        printf("Your score: %d\n", player_score);
        printf("Computer score: %d\n\n", computer_score);
    }

    // Determine overall winner
    if(player_score > computer_score)
    {
        printf("Congratulations, you win the game!");
    }
    else if(computer_score > player_score)
    {
        printf("Sorry, the computer wins the game!");
    }
    else
    {
        printf("It's a tie!");
    }

    return 0;
}