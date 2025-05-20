//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, ans, user_ans, score;
    char choice;

    srand(time(NULL)); // seed for random numbers

    do // repeat until user chooses to stop
    {
        score = 0; // reset score for each new game
        printf("\n-----------------------------\n");
        printf("   C Math Exercise Example   \n");
        printf("-----------------------------\n");

        // ask user for the difficulty level
        int level;
        printf("\n Choose the difficulty level:\n");
        printf(" [1] Easy \n [2] Medium \n [3] Hard \n");
        printf(" Enter your choice (1, 2 or 3): ");
        scanf("%d", &level);

        // set limits for random numbers based on difficulty level
        int lower, upper;
        switch (level)
        {
            case 1:
                lower = 1;
                upper = 10;
                break;
            case 2:
                lower = 10;
                upper = 100;
                break;
            case 3:
                lower = 100;
                upper = 1000;
                break;
            default:
                printf("\n Invalid input! Please choose 1, 2 or 3.\n");
                continue;
        }

        printf("\n Starting game with difficulty level %d...\n", level);

        for (int i = 1; i <= 10; i++) // generate 10 random questions
        {
            num1 = rand() % (upper - lower + 1) + lower;
            num2 = rand() % (upper - lower + 1) + lower;

            // choose a random operation
            int op = rand() % 4;

            switch (op)
            {
                case 0:
                    ans = num1 + num2;
                    printf("\n Q%d: What is %d + %d? ", i, num1, num2);
                    break;
                case 1:
                    ans = num1 - num2;
                    printf("\n Q%d: What is %d - %d? ", i, num1, num2);
                    break;
                case 2:
                    ans = num1 * num2;
                    printf("\n Q%d: What is %d * %d? ", i, num1, num2);
                    break;
                case 3:
                    ans = num1 / num2;
                    printf("\n Q%d: What is %d / %d (rounded down to nearest integer)? ", i, num1, num2);
                    break;
                default:
                    break;
            }

            scanf("%d", &user_ans);

            if (user_ans == ans)
            {
                score++;
                printf("CORRECT!\n");
            }
            else
            {
                printf("WRONG! The correct answer is: %d\n", ans);
            }
        }

        printf("\n-----------------------------\n");
        printf("         GAME OVER           \n");
        printf("-----------------------------\n");
        printf("  You scored %d out of 10.    \n", score);
        printf("-------------------------------\n");

        // ask user if they want to play again
        printf(" Do you want to play again? (Y/N): ");
        scanf(" %c", &choice);
    }
    while (choice == 'y' || choice == 'Y');

    printf("\n Thank you for playing! Goodbye!\n");

    return 0;
}