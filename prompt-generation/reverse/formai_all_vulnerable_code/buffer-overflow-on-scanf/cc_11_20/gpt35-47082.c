//FormAI DATASET v1.0 Category: Table Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int comp_choice, usr_choice, result;
    int score[2] = {0, 0};
    char choices[3][9] = {"rock", "paper", "scissors"};

    srand(time(0));

    printf("\nWelcome to Rock-Paper-Scissors game!\n");

    while (1)
    {
        printf("\nPlease enter your choice:\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d. %s\n", i + 1, choices[i]);
        }
        printf("4. Quit game\n");
        printf("Your choice: ");
        scanf("%d", &usr_choice);

        if (usr_choice == 4)
        {
            printf("\nThanks for playing. Final score: Computer %d, you %d\n", score[0], score[1]);
            break;
        }
        else if (usr_choice < 1 || usr_choice > 3)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        comp_choice = rand() % 3 + 1;

        printf("You chose %s. Computer chose %s. ", choices[usr_choice - 1], choices[comp_choice - 1]);

        if (usr_choice == comp_choice)
        {
            result = 0;
            printf("It's a draw.\n");
        }
        else if ((usr_choice == 1 && comp_choice == 3) || 
                 (usr_choice == 2 && comp_choice == 1) || 
                 (usr_choice == 3 && comp_choice == 2))
        {
            result = 1;
            printf("You won this round!\n");
            score[1]++;
        }
        else
        {
            result = -1;
            printf("Computer won this round.\n");
            score[0]++;
        }

        if (score[0] == 5 || score[1] == 5)
        {
            printf("\nGame over! Final score: Computer %d, you %d\n", score[0], score[1]);
            break;
        }

    }

    return 0;
}