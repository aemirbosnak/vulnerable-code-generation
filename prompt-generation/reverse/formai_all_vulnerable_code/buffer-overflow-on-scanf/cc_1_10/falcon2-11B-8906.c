//Falcon2-11B DATASET v1.0 Category: Weather simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int days[7];
    int i;
    int sum = 0;

    for (i = 0; i < 7; i++)
    {
        days[i] = rand() % 100 + 1;
    }

    printf("Weather Simulation\n\n");
    printf("Enter the temperature for day 1: ");
    scanf("%d", &days[0]);

    for (i = 1; i < 7; i++)
    {
        printf("Enter the temperature for day %d: ", i + 1);
        scanf("%d", &days[i]);
    }

    printf("Enter the wind speed for day 1: ");
    scanf("%d", &days[0]);

    for (i = 1; i < 7; i++)
    {
        printf("Enter the wind speed for day %d: ", i + 1);
        scanf("%d", &days[i]);
    }

    printf("Enter the humidity for day 1: ");
    scanf("%d", &days[0]);

    for (i = 1; i < 7; i++)
    {
        printf("Enter the humidity for day %d: ", i + 1);
        scanf("%d", &days[i]);
    }

    printf("Day 1: %d, %d, %d\n", days[0], days[1], days[2]);
    printf("Day 2: %d, %d, %d\n", days[3], days[4], days[5]);
    printf("Day 3: %d, %d, %d\n", days[6], days[7], days[8]);

    for (i = 0; i < 7; i++)
    {
        sum += days[i];
    }

    printf("Average Temperature: %d\n", sum / 7);
    printf("Average Wind Speed: %d\n", sum / 7);
    printf("Average Humidity: %d\n", sum / 7);

    return 0;
}