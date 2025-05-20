//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int choice, len, i, j, k, score = 0;
    char response;

    do
    {
        system("clear");

        printf("\n\n\t\tWELCOME TO THE NUMBER GAME\n\n");

        printf("\t\t1. Easy\n");
        printf("\t\t2. Medium\n");
        printf("\t\t3. Hard\n");
        printf("\t\t4. Quit\n");

        printf("\n\t\tPlease choose a level: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            len = 3;
            break;

        case 2:
            len = 4;
            break;

        case 3:
            len = 5;
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\n\t\tInvalid Choice. Please try again.\n");
            break;
        }

        if (choice == 1 || choice == 2 || choice == 3)
        {

            int num[len], guess[len];

            srand(time(NULL));

            for (i = 0; i < len; i++)
            {
                num[i] = rand() % 9 + 1;
            }

            printf("\n\t\tThe computer has generated a %d digit number between 1-9.\n", len);
            printf("\t\tYour task is to guess the number.\n");
            printf("\t\tEnter %d numbers separated by space.\n", len);

            for (i = 0; i < len; i++)
            {
                scanf("%d", &guess[i]);
            }

            printf("\n\t\tThe computer's number is: ");

            for (i = 0; i < len; i++)
            {
                printf("%d ", num[i]);
            }

            printf("\n\t\tYour guess is: ");

            for (i = 0; i < len; i++)
            {
                printf("%d ", guess[i]);
            }

            printf("\n\n");

            for (i = 0; i < len; i++)
            {

                if (guess[i] == num[i])
                {
                    score++;
                }

                for (j = 0; j < len; j++)
                {

                    if (i != j)
                    {

                        if (guess[i] == num[j])
                        {
                            score--;
                        }
                    }
                }
            }

            if (score == len)
            {
                printf("\t\tCongratulations! You have guessed the number correctly.\n");
            }
            else
            {
                printf("\n\t\tSorry, you were unable to guess the number correctly.\n");
            }

            printf("\n\t\tYour score is %d.\n", score);

            printf("\t\tDo you want to play again? (y/n): ");
            getchar();
            scanf("%c", &response);
        }

    } while (response == 'y' || response == 'Y');

    printf("\n\t\tThank you for playing the game.\n");

    return 0;
}