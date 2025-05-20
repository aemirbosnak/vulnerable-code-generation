//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, a[MAX], b[MAX], c[MAX], d[MAX];
    n = 0;
    a[n] = 0;
    b[n] = 0;
    c[n] = 0;
    d[n] = 0;

    printf("Welcome to the Greedy Algorithm Shock Show!\n");
    printf("Prepare for a heaping dose of code!\n");

    while (1)
    {
        printf("Enter the number of items you want to manage: ");
        scanf("%d", &k);

        if (k == 0)
        {
            break;
        }

        n++;
        a[n] = k;
        b[n] = 0;
        c[n] = 0;
        d[n] = 0;

        for (i = 0; i < k; i++)
        {
            printf("Enter the weight of item %d: ", i + 1);
            scanf("%d", &c[n]);
        }

        for (i = 0; i < k; i++)
        {
            printf("Enter the value of item %d: ", i + 1);
            scanf("%d", &d[n]);
        }

        for (i = 0; i < k; i++)
        {
            b[n] += c[n] * d[n];
        }

        printf("Total value of items: $%d\n", b[n]);
    }

    printf("Thanks for joining the Greedy Algorithm Shock Show!\n");

    return 0;
}