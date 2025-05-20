//FormAI DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, op, answer, user_answer, count = 0;

    srand(time(0));
    printf("Enter the number of math problems you would like to solve: ");
    scanf("%d", &num1);

    printf("\n*************************************************\n");
    printf("************* Retro Style Math Quiz! *************");
    printf("\n*************************************************\n");

    for (int i=1; i<=num1; i++) 
    {
        num2 = (rand() % 10) + 1;
        op = rand() % 3;

        if (op == 0) 
        {
            printf("\n%d) %d + %d = ", i, num1, num2);
            answer = num1 + num2;
            scanf("%d", &user_answer);
        }
        else if (op == 1) 
        {
            printf("\n%d) %d - %d = ", i, num1, num2);
            answer = num1 - num2;
            scanf("%d", &user_answer);
        }
        else 
        {
            printf("\n%d) %d * %d = ", i, num1, num2);
            answer = num1 * num2;
            scanf("%d", &user_answer);
        }

        if (user_answer == answer) 
        {
            count++;
            printf("\nCorrect!\n");
        }
        else
            printf("\nIncorrect! The answer is %d\n", answer);
    }
    printf("\n*************************************************\n");
    printf("********************* Results *******************");
    printf("\n*************************************************\n");
    printf("\nYou answered %d out of %d problems correctly. Well done!\n", count, num1);

    return 0;
}