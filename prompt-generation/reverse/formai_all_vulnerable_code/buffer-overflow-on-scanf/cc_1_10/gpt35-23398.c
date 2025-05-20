//FormAI DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>

float calculate_average(float array[]);
float calculate_maximum(float array[]);
float calculate_minimum(float array[]);

int main()
{
    float temperature[7];

    printf("Enter temperatures for the week: \n");

    for (int i = 0; i < 7; i++)
    {
        printf("Day %d: ", i + 1);
        scanf("%f", &temperature[i]);
    }

    printf("\nTemperature Report:\n");
    printf("=================================\n");
    printf("Maximum Temperature: %.2f degrees\n", calculate_maximum(temperature));
    printf("Minimum Temperature: %.2f degrees\n", calculate_minimum(temperature));
    printf("Average Temperature: %.2f degrees\n", calculate_average(temperature));

    return 0;
}

float calculate_average(float array[])
{
    float sum = 0, average;
    int i;

    for (i = 0; i < 7; i++)
    {
        sum += array[i];
    }

    average = sum / 7;

    return average;
}

float calculate_maximum(float array[])
{
    float maximum = array[0];
    int i;

    for (i = 0; i < 7; i++)
    {
        if (array[i] > maximum)
        {
            maximum = array[i];
        }
    }

    return maximum;
}

float calculate_minimum(float array[])
{
    float minimum = array[0];
    int i;

    for (i = 0; i < 7; i++)
    {
        if (array[i] < minimum)
        {
            minimum = array[i];
        }
    }

    return minimum;
}