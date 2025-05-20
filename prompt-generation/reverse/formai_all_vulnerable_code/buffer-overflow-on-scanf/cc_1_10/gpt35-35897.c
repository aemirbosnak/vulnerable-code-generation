//FormAI DATASET v1.0 Category: Math exercise ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, answer, i;
    char operator;
    int score = 0;
    srand(time(0));

    printf("\n\n\t\t\t Welcome to Math Exercise Game\n\n");
    printf("\t\t\t------------------------------\n\n");

    for(i=1; i<=10; i++)
    {
        num1 = rand() % 20;
        num2 = rand() % 10;
        result = num1 + num2;

        switch(rand() % 4)
        {
            case 0: operator = '+';
                    break;

            case 1: operator = '-';
                    break;

            case 2: operator = 'x';
                    break;

            case 3: operator = '/';
                    break;
        }

        printf("\n\n%2d. What is %2d %c %2d? ", i, num1, operator, num2);
        scanf("%d", &answer);

        if(answer == result)
        {
            printf("\n\t\t  Correct! Well done!\n");
            score++;
        }
        else
        {
            printf("\n\t\t  Wrong! The correct answer is %d.\n", result);
        }
    }

    printf("\n\n\t\t\t  Game Over! Your final score is %d.\n\n", score);

    return 0;
}