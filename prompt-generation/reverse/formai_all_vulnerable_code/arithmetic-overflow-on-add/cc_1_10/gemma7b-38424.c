//Gemma-7B DATASET v1.0 Category: Pattern printing ; Style: Donald Knuth
#include <stdio.h>

int main()
{
    int n, i, j, k, l, m, r, t;
    scanf("Enter the number of test cases: ", &t);

    for (k = 0; k < t; k++)
    {
        scanf("Enter the number of rows: ", &n);
        scanf("Enter the number of columns: ", &m);

        l = n + m - 2;
        r = n + m - 1;

        for (i = 0; i < l; i++)
        {
            for (j = 0; j < r; j++)
            {
                if (i >= n - 1 && j >= m - 1)
                {
                    printf(" ");
                }
                else
                {
                    printf("*");
                }
            }
            printf("\n");
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (i == 0)
                {
                    printf("%c", 'A' + j);
                }
                else if (j == 0)
                {
                    printf("%c", 'A' + i);
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}