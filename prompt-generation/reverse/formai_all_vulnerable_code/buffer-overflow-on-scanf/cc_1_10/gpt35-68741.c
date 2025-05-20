//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE 0
#define BEEP_LIMIT 90

int main()
{
    int temperature = 0;
    int total = 0;
    int count = 0;
    int average = 0;

    printf("Temperature Monitoring System\n");

    while (temperature != -999)
    {
        printf("Enter temperature (-999 to exit): ");
        scanf("%d", &temperature);

        if (temperature >= MIN_TEMPERATURE && temperature <= MAX_TEMPERATURE)
        {
            total += temperature;
            count++;

            if (temperature >= BEEP_LIMIT)
            {
                printf("WARNING: High temperature detected! Beep! Beep! Beep!\n");
            }
        }
        else if (temperature != -999)
        {
            printf("Invalid temperature entered. Please try again.\n");
        }
    }

    if (count > 0)
    {
        average = total / count;
    }

    printf("Total temperature count: %d\n", count);

    if (count > 0)
    {
        printf("Average temperature: %d\n", average);
    }
    else
    {
        printf("No temperature readings taken.\n");
    }

    return 0;
}