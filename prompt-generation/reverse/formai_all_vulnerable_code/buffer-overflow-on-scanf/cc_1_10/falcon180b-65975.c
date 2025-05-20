//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int count = 0;
    int num1, num2, sum;
    char operation;

    srand(time(NULL));

    printf("Welcome to the Arithmetic Calculator!\n\n");
    printf("This program will generate random arithmetic problems for you to solve.\n");
    printf("Press enter to begin.\n");
    scanf("%c", &operation);

    while(count < 200)
    {
        printf("\nProblem %d:\n", count+1);

        num1 = rand() % 100;
        num2 = rand() % 100;
        switch(operation)
        {
            case 'a':
                sum = num1 + num2;
                break;
            case 'b':
                sum = num1 - num2;
                break;
            case 'c':
                sum = num1 * num2;
                break;
            case 'd':
                if(num2 == 0)
                {
                    printf("Cannot divide by zero.\n");
                    count--;
                }
                else
                {
                    sum = num1 / num2;
                }
                break;
            default:
                printf("Invalid operation.\n");
                count--;
        }

        printf("Solve the following problem:\n");
        printf("%d %c %d = ", num1, operation, num2);

        scanf("%d", &a);

        if(a == sum)
        {
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n", sum);
        }

        count++;
    }

    printf("\nCongratulations! You have completed 200 arithmetic problems.\n");

    return 0;
}