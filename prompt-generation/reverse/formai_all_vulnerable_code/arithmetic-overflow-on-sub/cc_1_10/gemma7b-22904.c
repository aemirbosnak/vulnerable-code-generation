//Gemma-7B DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, x, y, z, a[100], b[100], c[100], d[100];

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of elements: ");
        scanf("%d", &x);

        printf("Enter the elements: ");
        for (j = 0; j < x; j++)
        {
            scanf("%d", &a[j]);
        }

        printf("Enter the operation: (+, -, *, /) ");
        scanf("%s", &y);

        printf("Enter the second operand: ");
        scanf("%d", &z);

        switch (y)
        {
            case '+':
                c[i] = a[i] + z;
                break;
            case '-':
                c[i] = a[i] - z;
                break;
            case '*':
                c[i] = a[i] * z;
                break;
            case '/':
                if (z == 0)
                {
                    printf("Cannot divide by zero\n");
                }
                else
                {
                    c[i] = a[i] / z;
                }
                break;
            default:
                printf("Invalid operation\n");
                break;
        }

        printf("The result is: %d\n", c[i]);
    }

    return 0;
}