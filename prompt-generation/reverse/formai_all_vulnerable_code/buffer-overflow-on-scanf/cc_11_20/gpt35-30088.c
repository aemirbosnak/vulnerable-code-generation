//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int user_choice, computer_choice, result;
    int user_score = 0, computer_score = 0, draws = 0;
    char play_again;

    srand(time(NULL));
    printf("Welcome to the Introspective Table Game!\n");

    do
    {
        printf("\nPlease select your choice:\n");
        printf("1. Me\n2. The world\n3. Fate\n");
        scanf("%d", &user_choice);

        computer_choice = rand() % 3 + 1;

        printf("You chose ");
        switch (user_choice)
        {
        case 1:
            printf("Me.\n");
            break;
        case 2:
            printf("The world.\n");
            break;
        case 3:
            printf("Fate.\n");
            break;
        default:
            printf("an invalid option.\n");
            break;
        }

        printf("The computer chose ");
        switch (computer_choice)
        {
        case 1:
            printf("Me.\n");
            break;
        case 2:
            printf("The world.\n");
            break;
        case 3:
            printf("Fate.\n");
            break;
        }

        if (user_choice == computer_choice)
        {
            printf("\nIt's a draw!\n");
            draws++;
        }
        else if ((user_choice == 1 && computer_choice == 2) || 
                (user_choice == 2 && computer_choice == 3) ||
                (user_choice == 3 && computer_choice == 1))
        {
            printf("\nYou win!\n");
            user_score++;
        }
        else
        {
            printf("\nSorry, you lost!\n");
            computer_score++;
        }

        printf("\nScoreboard:\n");
        printf("You: %d\nComputer: %d\nDraws: %d\n", user_score, computer_score, draws);

        printf("\nDo you want to play again? (y/n)\n");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    printf("\nThanks for playing Introspective Table Game!\n");

    return 0;
}