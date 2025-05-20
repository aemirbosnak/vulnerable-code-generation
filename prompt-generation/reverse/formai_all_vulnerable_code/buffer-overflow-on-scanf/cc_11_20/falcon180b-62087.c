//Falcon-180B DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize random seed

    int player_score = 0;
    int computer_score = 0;
    int choice;

    char *choices[] = {"Rock", "Paper", "Scissors"};

    do
    {
        printf("Player score: %d\n", player_score);
        printf("Computer score: %d\n", computer_score);

        printf("Choose one of the following:\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d. %s\n", i + 1, choices[i]);
        }

        scanf("%d", &choice);

        if (choice < 1 || choice > 3)
        {
            printf("Invalid choice! Please enter a number between 1 and 3.\n");
            continue;
        }

        int computer_choice = rand() % 3;

        if (choice == computer_choice)
        {
            printf("It's a tie!\n");
        }
        else if ((choice == 1 && computer_choice == 2) ||
                 (choice == 2 && computer_choice == 1) ||
                 (choice == 3 && computer_choice == 2) ||
                 (choice == 2 && computer_choice == 3))
        {
            printf("You win this round!\n");
            player_score++;
        }
        else
        {
            printf("You lose this round.\n");
            computer_score++;
        }

    } while (player_score!= 5 && computer_score!= 5);

    if (player_score == 5)
    {
        printf("Congratulations! You've won the game.\n");
    }
    else
    {
        printf("Sorry, you've lost the game.\n");
    }

    return 0;
}