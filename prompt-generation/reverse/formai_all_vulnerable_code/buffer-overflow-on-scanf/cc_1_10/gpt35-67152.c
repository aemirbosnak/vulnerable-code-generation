//FormAI DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score = 0, roll, sum = 0;
    char choice;

    printf("Welcome to C Table Game!\n\n");

    while (1)
    {
        printf("Your current score is: %d\n", score);

        printf("Do you want to roll the dice? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y')
        {
            srand(time(0));
            roll = rand() % 6 + 1;
            printf("You rolled: %d\n", roll);

            if (roll == 1)
            {
                sum = 0;
                printf("Oops! You lost all your points in this round.\n");
                break;
            }
            else
            {
                sum += roll;
            }

            if (sum >= 20)
            {
                score += sum;
                printf("Congratulations! You earned %d points this round.\n", sum);
                sum = 0;
                printf("Your current score is: %d\n", score);

                printf("Do you want to continue? (y/n): ");
                scanf(" %c", &choice);

                if (choice == 'n')
                {
                    break;
                }
            }
        }
        else if (choice == 'n')
        {
            break;
        }
        else
        {
            printf("Please enter a valid choice (y/n).\n");
        }
    }

    printf("\nYour final score is: %d\n", score);
    printf("Thank you for playing C Table Game!");

    return 0;
}