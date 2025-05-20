//FormAI DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, answer, choice, correctAns = 0, wrongAns = 0;
    srand(time(0)); // random number generator seed

    printf("Welcome to the C Online Examination System!\n");
    printf("You will be presented with 10 multiple choice questions.\n");
    printf("Please choose the correct answer by entering the choice number.\n");

    for (i = 0; i < 10; i++)
    {
        int num1 = rand() % 20 + 1; // random number generator for first number
        int num2 = rand() % 20 + 1; // random number generator for second number

        printf("\nQuestion %d: What is %d + %d?\n", i+1, num1, num2);
        printf("1. %d\n", num1 + num2);
        printf("2. %d\n", num1 - num2);
        printf("3. %d\n", num1 * num2);
        printf("4. %d\n", num1 / num2);

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                answer = num1 + num2;
                break;
            case 2:
                answer = num1 - num2;
                break;
            case 3:
                answer = num1 * num2;
                break;
            case 4:
                answer = num1 / num2;
                break;
            default:
                printf("Invalid choice! Skipping question.\n");
                continue;
        }

        if (answer == num1 + num2)
        {
            printf("Correct!\n");
            correctAns++;
        }
        else
        {
            printf("Incorrect! The correct answer is: %d\n", num1 + num2);
            wrongAns++;
        }
    }

    printf("\nYour exam has ended.\n");
    printf("You answered %d questions correctly and %d questions incorrectly.\n", correctAns, wrongAns);

    return 0;
}