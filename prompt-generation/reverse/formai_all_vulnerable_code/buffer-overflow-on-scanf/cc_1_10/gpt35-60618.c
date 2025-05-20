//FormAI DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Math Exercise Generator\n");
    printf("---------------------------------------\n");
    printf("Please choose the difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    int choice;
    scanf("%d", &choice);

    int num_exercises;
    if (choice == 1)
        num_exercises = 5;
    else if (choice == 2)
        num_exercises = 10;
    else
        num_exercises = 15;

    printf("---------------------------------------\n");
    printf("Generating %d Math Exercises...\n", num_exercises);
    printf("---------------------------------------\n");

    srand(time(0));
    int correct_answers = 0;
    int wrong_answers = 0;
    for (int i = 0; i < num_exercises; i++)
    {
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;
        int operation = rand() % 3;

        if (operation == 0) // addition
        {
            printf("%d + %d = ", num1, num2);
            int answer;
            scanf("%d", &answer);
            if (answer == num1 + num2)
            {
                correct_answers++;
                printf("Correct!\n");
            }
            else
            {
                wrong_answers++;
                printf("Wrong!\n");
            }
        }
        else if (operation == 1) // subtraction
        {
            printf("%d - %d = ", num1, num2);
            int answer;
            scanf("%d", &answer);
            if (answer == num1 - num2)
            {
                correct_answers++;
                printf("Correct!\n");
            }
            else
            {
                wrong_answers++;
                printf("Wrong!\n");
            }
        }
        else // multiplication
        {
            printf("%d * %d = ", num1, num2);
            int answer;
            scanf("%d", &answer);
            if (answer == num1 * num2)
            {
                correct_answers++;
                printf("Correct!\n");
            }
            else
            {
                wrong_answers++;
                printf("Wrong!\n");
            }
        }
    }

    printf("---------------------------------------\n");
    printf("Math Exercises Completed!\n");
    printf("Correct Answers: %d\n", correct_answers);
    printf("Wrong Answers: %d\n", wrong_answers);
    printf("---------------------------------------\n");
    printf("Thank you for using the Math Exercise Generator!\n");

    return 0;
}