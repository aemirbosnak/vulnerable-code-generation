//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int main()
{

    int i, j, k, l, m, n, a[MAX], b[MAX], c[MAX], d[MAX], e[MAX], f[MAX], g[MAX];

    printf("Enter the number of circuits: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of components for circuit %d: ", i + 1);
        scanf("%d", &m);

        for (j = 0; j < m; j++)
        {
            printf("Enter the type of component %d (R/L/C): ", j + 1);
            scanf("%c", &a[j]);

            printf("Enter the value of component %d: ", j + 1);
            scanf("%d", &b[j]);
        }

        printf("Enter the voltage of circuit %d: ", i + 1);
        scanf("%d", &c[i]);

        printf("Enter the resistance of circuit %d: ", i + 1);
        scanf("%d", &d[i]);
    }

    for (i = 0; i < n; i++)
    {
        e[i] = c[i] / d[i];
        f[i] = e[i] * b[i];
        g[i] = f[i] * a[i];
    }

    printf("The results of the simulations are: ");

    for (i = 0; i < n; i++)
    {
        printf("Circuit %d: ", i + 1);
        printf("Voltage: %.2f V, ", c[i]);
        printf("Resistance: %.2f ohms, ", d[i]);
        printf("Power: %.2f watts\n", g[i]);
    }

    return 0;
}