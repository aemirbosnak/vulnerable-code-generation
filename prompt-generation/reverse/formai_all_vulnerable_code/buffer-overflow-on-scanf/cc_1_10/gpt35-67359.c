//FormAI DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* generate random numbers between 1 and 100 and asks user to solve math problems */

int main()
{
    int num1, num2, answer, userAnswer, operationChoice, questionChoice;
    int correctAnswers = 0, totalQuestions = 0;
    char operation;
    char playAgain = 'y';

    srand(time(NULL));

    printf("Welcome to Math Mania!\n");

    do {
        /* choose an operation */
        printf("Choose an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        scanf("%d", &operationChoice);

        /* choose number of questions */
        printf("How many questions would you like to answer? ");
        scanf("%d", &questionChoice);

        for (int i = 1; i <= questionChoice; i++) {
            /* generate random numbers */
            num1 = rand() % 100 + 1;
            num2 = rand() % 100 + 1;

            /* perform chosen operation */
            switch (operationChoice) {
                case 1:
                    operation = '+';
                    answer = num1 + num2;
                    break;
                case 2:
                    operation = '-';
                    answer = num1 - num2;
                    break;
                case 3:
                    operation = '*';
                    answer = num1 * num2;
                    break;
                case 4:
                    operation = '/';
                    answer = num1 / num2;
                    break;
                default:
                    printf("Invalid operation choice.\n");
                    return 1;
            }

            /* ask user for answer */
            printf("Question %d: %d %c %d = ", i, num1, operation, num2);
            scanf("%d", &userAnswer);

            /* check answer and keep track of stats */
            if (userAnswer == answer) {
                printf("Correct!\n");
                correctAnswers++;
            } else {
                printf("Incorrect. The answer is %d.\n", answer);
            }
            totalQuestions++;
        }

        /* print statistics */
        printf("You answered %d out of %d questions correctly.\n", correctAnswers, totalQuestions);

        /* ask user to play again */
        printf("Would you like to play again? (y/n) ");
        scanf(" %c", &playAgain);

        /* reset variables for new game */
        correctAnswers = 0;
        totalQuestions = 0;

    } while (playAgain == 'y');

    printf("Thanks for playing Math Mania!\n");

    return 0;
}