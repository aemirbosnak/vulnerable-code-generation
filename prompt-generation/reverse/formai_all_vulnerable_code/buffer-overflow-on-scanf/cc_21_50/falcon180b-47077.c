//Falcon-180B DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int player_score = 0, computer_score = 0;
    char choice;

    printf("Welcome to the C Table Game!\n");
    printf("You will play against the computer.\n");
    printf("Choose rock, paper or scissors.\n");
    scanf("%c", &choice);

    int computer_choice = rand() % 3;

    if (computer_choice == 0)
        computer_choice = 'r';
    else if (computer_choice == 1)
        computer_choice = 'p';
    else
        computer_choice ='s';

    printf("Computer chooses %c\n", computer_choice);

    if (choice == computer_choice)
    {
        printf("It's a tie!\n");
    }
    else if ((choice == 'r' && computer_choice == 'p') ||
             (choice == 'p' && computer_choice =='s') ||
             (choice =='s' && computer_choice == 'r'))
    {
        printf("You win!\n");
        player_score++;
    }
    else
    {
        printf("You lose!\n");
        computer_score++;
    }

    int rounds = 5;

    for (int i = 1; i <= rounds; i++)
    {
        printf("\nRound %d\n", i);
        printf("Your score: %d\n", player_score);
        printf("Computer score: %d\n", computer_score);

        printf("Choose rock, paper or scissors.\n");
        scanf("%c", &choice);

        computer_choice = rand() % 3;

        if (computer_choice == 0)
            computer_choice = 'r';
        else if (computer_choice == 1)
            computer_choice = 'p';
        else
            computer_choice ='s';

        printf("Computer chooses %c\n", computer_choice);

        if (choice == computer_choice)
        {
            printf("It's a tie!\n");
        }
        else if ((choice == 'r' && computer_choice == 'p') ||
                 (choice == 'p' && computer_choice =='s') ||
                 (choice =='s' && computer_choice == 'r'))
        {
            printf("You win!\n");
            player_score++;
        }
        else
        {
            printf("You lose!\n");
            computer_score++;
        }

        printf("\n");
    }

    if (player_score > computer_score)
    {
        printf("Congratulations! You won the game!\n");
    }
    else if (computer_score > player_score)
    {
        printf("Sorry, you lost the game.\n");
    }
    else
    {
        printf("It's a tie game.\n");
    }

    return 0;
}