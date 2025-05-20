//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: scalable
#include <stdio.h>
#include <math.h>

#define MAX 1000

int main()
{
    int n, i, j, a[MAX], b[MAX], c[MAX];
    double p, r, t, amort, total, balance;

    printf("Enter the number of loans: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the loan amount: ");
        scanf("%d", &a[i]);

        printf("Enter the interest rate: ");
        scanf("%lf", &r);

        printf("Enter the number of years: ");
        scanf("%d", &t);

        amort = a[i] * (r / 100) * t;
        c[i] = amort;
        balance = a[i] - amort;
        b[i] = balance;
    }

    total = 0;
    for (i = 0; i < n; i++)
    {
        total += c[i];
    }

    printf("Total amortization: %.2lf", total);

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Loan %d:\n", i + 1);
        printf("Loan amount: %d\n", a[i]);
        printf("Amortization: %.2lf\n", c[i]);
        printf("Balance: %.2lf\n", b[i]);
        printf("\n");
    }

    return 0;
}