//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100];

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of elements in the array: ");
        scanf("%d", &m);

        printf("Enter the elements of the array: ");
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[j]);
        }

        printf("Enter the number of operations: ");
        scanf("%d", &l);

        for (k = 0; k < l; k++)
        {
            printf("Enter the operation type (add/subtract/multiply/divide): ");
            scanf("%s", c);

            printf("Enter the operands: ");
            scanf("%d", &b[k]);

            if (strcmp(c, "add") == 0)
            {
                d[k] = a[j] + b[k];
            }
            else if (strcmp(c, "subtract") == 0)
            {
                d[k] = a[j] - b[k];
            }
            else if (strcmp(c, "multiply") == 0)
            {
                d[k] = a[j] * b[k];
            }
            else if (strcmp(c, "divide") == 0)
            {
                if (b[k] == 0)
                {
                    printf("Error: division by zero is not allowed.\n");
                }
                else
                {
                    d[k] = a[j] / b[k];
                }
            }
        }

        printf("The elements of the array after the operations are: ");
        for (j = 0; j < m; j++)
        {
            printf("%d ", d[j]);
        }

        printf("\n");
    }

    return 0;
}