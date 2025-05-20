//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, x, y, z;
    char weather[20];

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of the city: ");
        scanf("%s", weather);

        printf("Enter the temperature in Fahrenheit: ");
        scanf("%d", &x);

        printf("Enter the humidity in percentage: ");
        scanf("%d", &y);

        printf("Enter the precipitation in inches: ");
        scanf("%d", &z);

        printf("The weather forecast for %s is: ", weather);

        if (x >= 90)
        {
            printf("Hot\n");
        }
        else if (x >= 60)
        {
            printf("Mild\n");
        }
        else if (x >= 32)
        {
            printf("Cool\n");
        }
        else
        {
            printf("Cold\n");
        }

        printf("Humidity: %d%\n", y);

        printf("Precipitation: %d inches\n", z);

        printf("\n");
    }

    return 0;
}