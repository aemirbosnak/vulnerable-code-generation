//FormAI DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_choice, computer_choice, player_score = 0, computer_score = 0, rounds;

    srand(time(NULL)); // seeding the random number generator

    printf("Welcome to the Happy Game!\n\n");

    printf("How many rounds would you like to play? ");
    scanf("%d", &rounds);

    printf("\nLet's begin!\n\n");

    for (int i = 1; i <= rounds; i++)
    {
        printf("Round %d:\n", i);

        printf("Choose your weapon:\n1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &player_choice);

        computer_choice = rand() % 3 + 1; // generating a random weapon for the computer

        printf("Computer chooses: ");

        switch (computer_choice)
        {
            case 1:
                printf("rock\n");
                break;
            case 2:
                printf("paper\n");
                break;
            case 3:
                printf("scissors\n");
                break;
        }

        if (player_choice == 1 && computer_choice == 3 || player_choice == 2 && computer_choice == 1 || player_choice == 3 && computer_choice == 2)
        {
            printf("You win!\n");
            player_score++;
        }
        else if (player_choice == computer_choice)
        {
            printf("It's a tie!\n");
        }
        else
        {
            printf("Computer wins!\n");
            computer_score++;
        }

        printf("Score:\nYou: %d\nComputer: %d\n\n", player_score, computer_score);
    }

    printf("Game over!\n");

    if (player_score > computer_score)
    {
        printf("Congratulations, you are the winner!\n");
    }
    else if (player_score < computer_score)
    {
        printf("Better luck next time, the computer wins!\n");
    }
    else
    {
        printf("It's a tie, both players win!\n");
    }

    return 0;
}