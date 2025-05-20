//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2;
    char operator;
    int result;
    int choice;
    int correct_ans = 0;
    int total_ques = 0;
    int score = 0;

    printf("Welcome to the Arithmetic Quiz!\n");
    printf("How many questions do you want to answer? ");
    scanf("%d", &total_ques);

    srand(time(0));
    int num1_range = rand() % 100 + 1;
    int num2_range = rand() % 100 + 1;

    for (int i = 0; i < total_ques; i++)
    {
        num1 = rand() % num1_range + 1;
        num2 = rand() % num2_range + 1;

        operator = rand() % 4;

        switch (operator)
        {
            case 0:
                printf("What is %d + %d? ", num1, num2);
                scanf("%d", &result);
                if (result == num1 + num2)
                {
                    correct_ans++;
                }
                break;
            case 1:
                printf("What is %d - %d? ", num1, num2);
                scanf("%d", &result);
                if (result == num1 - num2)
                {
                    correct_ans++;
                }
                break;
            case 2:
                printf("What is %d * %d? ", num1, num2);
                scanf("%d", &result);
                if (result == num1 * num2)
                {
                    correct_ans++;
                }
                break;
            case 3:
                printf("What is %d / %d? ", num1, num2);
                scanf("%d", &result);
                if (result == num1 / num2)
                {
                    correct_ans++;
                }
                break;
        }
    }

    printf("\nYou answered %d out of %d questions correctly.\n", correct_ans, total_ques);

    return 0;
}