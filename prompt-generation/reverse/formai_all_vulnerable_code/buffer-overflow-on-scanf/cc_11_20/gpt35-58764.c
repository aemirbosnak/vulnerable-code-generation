//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double num1, num2, num3, ans, result;
    char operator, response;
    int i;

    printf("Welcome to the Math Quiz Program!\n");
    printf("You will be given 10 mathematical equations to solve.\n");
    printf("****************************************************\n");

    srand(time(0));  // Setting random seed for numbers
    for (i = 1; i <= 10; i++)
    {
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;
        num3 = rand() % 100 + 1;
        operator = rand() % 4;  // 0 = +, 1 = -, 2 = *, 3 = /

        switch (operator)
        {
        case 0:
            ans = num1 + num2 + num3;
            printf("Question %d: %.0f + %.0f + %.0f = ", i, num1, num2, num3);
            break;
        case 1:
            ans = num1 - num2 - num3;
            printf("Question %d: %.0f - %.0f - %.0f = ", i, num1, num2, num3);
            break;
        case 2:
            ans = num1 * num2 * num3;
            printf("Question %d: %.0f * %.0f * %.0f = ", i, num1, num2, num3);
            break;
        case 3:
            if (num2 == 0 || num3 == 0)
            {
                num2++;
                num3++;
            }
            ans = num1 / num2 / num3;
            printf("Question %d: %.0f / %.0f / %.0f = ", i, num1, num2, num3);
            break;
        }

        scanf("%lf", &result);
        if (result == ans)
        {
            printf("Correct! Keep up the good work.\n");
        }
        else
        {
            printf("Incorrect. The answer is %.2f\n", ans);
        }

        printf("Press any key to continue or 'q' to quit.\n");
        response = getchar();
        if (response == 'q' || response == 'Q')
        {
            break;
        }

        printf("\n");
    }

    printf("Thank you for playing the Math Quiz Program!");
    return 0;
}