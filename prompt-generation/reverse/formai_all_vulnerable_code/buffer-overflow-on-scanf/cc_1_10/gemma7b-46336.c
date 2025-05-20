//Gemma-7B DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int main()
{

    int n, i, j, k, l, x, y, z, sum = 0;
    char ch, str[MAX];
    float f, pi = 3.14159f;

    // Mathematical Queries
    printf("Enter the number of queries: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the operation: ");
        scanf(" %c", &ch);

        switch (ch)
        {
            case 'a':
                printf("Enter two numbers: ");
                scanf("%d %d", &x, &y);
                sum = x + y;
                printf("The sum is: %d\n", sum);
                break;

            case 's':
                printf("Enter two numbers: ");
                scanf("%d %d", &x, &y);
                sum = x - y;
                printf("The difference is: %d\n", sum);
                break;

            case 'm':
                printf("Enter two numbers: ");
                scanf("%d %d", &x, &y);
                sum = x * y;
                printf("The product is: %d\n", sum);
                break;

            case 'd':
                printf("Enter two numbers: ");
                scanf("%d %d", &x, &y);
                sum = x / y;
                printf("The quotient is: %d\n", sum);
                break;

            case 'p':
                printf("Enter a number: ");
                scanf("%f", &f);
                printf("The square of %f is: %f\n", f, f * f);
                break;

            case 'c':
                printf("Enter a number: ");
                scanf("%f", &f);
                printf("The cube of %f is: %f\n", f, f * f * f);
                break;

            default:
                printf("Invalid operation.\n");
                break;
        }
    }

    return 0;
}