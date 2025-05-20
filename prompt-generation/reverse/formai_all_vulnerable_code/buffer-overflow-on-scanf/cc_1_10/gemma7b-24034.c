//Gemma-7B DATASET v1.0 Category: Educational ; Style: scientific
#include <stdio.h>

int main()
{
    int n, i, j, k, l, m, x, y, z;
    float a, b, c, d, e, f, g;

    printf("Welcome to the cosmic calculator!\n");

    printf("Please enter the number of celestial objects: ");
    scanf("%d", &n);

    printf("Enter the mass of each object (in kilograms): ");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a);
        printf("Object %d has a mass of %.2f kilograms.\n", i + 1, a);
    }

    printf("Enter the gravitational force between each pair of objects (in newtons): ");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            scanf("%f", &b);
            printf("The force between objects %d and %d is %.2f newtons.\n", i + 1, j + 1, b);
        }
    }

    printf("Calculating the total mass of the universe...");
    m = 0;
    for (i = 0; i < n; i++)
    {
        m += a;
    }
    printf("The total mass of the universe is %.2f kilograms.\n", m);

    printf("Calculating the gravitational force between all objects...");
    x = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            x += b;
        }
    }
    printf("The total gravitational force between all objects is %.2f newtons.\n", x);

    return 0;
}