//Gemma-7B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>

int main()
{
    int n, i, j, k, l, m, a[1000], b[1000], c[1000], d[1000];

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of elements: ");
        scanf("%d", &l);

        printf("Enter the elements: ");
        for (j = 0; j < l; j++)
        {
            scanf("%d", &a[j]);
        }

        printf("Enter the operation: ");
        scanf("%s", b);

        printf("Enter the second number: ");
        scanf("%d", &m);

        switch (b[0])
        {
            case '+':
                c[i] = a[0] + m;
                break;
            case '-':
                c[i] = a[0] - m;
                break;
            case '*':
                c[i] = a[0] * m;
                break;
            case '/':
                if (m == 0)
                {
                    c[i] = -1;
                }
                else
                {
                    c[i] = a[0] / m;
                }
                break;
            default:
                c[i] = -1;
                break;
        }

        printf("The result is: %d\n", c[i]);
    }

    return 0;
}