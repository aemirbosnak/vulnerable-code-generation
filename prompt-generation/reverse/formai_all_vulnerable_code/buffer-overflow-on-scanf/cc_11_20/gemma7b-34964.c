//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100], f[100];
    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        b[i] = a[i] * 2;
    }

    for (i = 0; i < n; i++)
    {
        c[i] = a[i] + 10;
    }

    for (i = 0; i < n; i++)
    {
        d[i] = a[i] - 5;
    }

    for (i = 0; i < n; i++)
    {
        e[i] = a[i] * 3;
    }

    for (i = 0; i < n; i++)
    {
        f[i] = a[i] / 2;
    }

    for (i = 0; i < n; i++)
    {
        printf("The marks of student %d after doubling are: %d\n", i + 1, b[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("The marks of student %d after adding 10 are: %d\n", i + 1, c[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("The marks of student %d after subtracting 5 are: %d\n", i + 1, d[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("The marks of student %d after multiplying by 3 are: %d\n", i + 1, e[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("The marks of student %d after dividing by 2 are: %d\n", i + 1, f[i]);
    }

    return 0;
}