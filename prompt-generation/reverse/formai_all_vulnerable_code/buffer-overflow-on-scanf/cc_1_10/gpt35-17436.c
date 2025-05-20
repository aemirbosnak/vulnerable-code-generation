//FormAI DATASET v1.0 Category: Temperature monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float read_temperature(void);

int main(void)
{
    float temperature;
    bool is_high = false;
    bool is_low = false;

    printf("Temperature Monitor\n\n");

    while (true)
    {
        temperature = read_temperature();

        printf("Current temperature: %.2f C\n", temperature);

        if (temperature >= 30.0)
        {
            is_high = true;

            if (is_low)
            {
                printf("Temperature has risen above 30.0 C, but previously it was low.\n");
                is_low = false;
            }
            else
            {
                printf("Temperature is very high!\n");
            }
        }
        else if (temperature <= 10.0)
        {
            is_low = true;

            if (is_high)
            {
                printf("Temperature has dropped below 10.0 C, but previously it was high.\n");
                is_high = false;
            }
            else
            {
                printf("Temperature is very low!\n");
            }
        }
        else
        {
            if (is_high)
            {
                printf("Temperature has dropped from high to safe.\n");
                is_high = false;
            }
            else if (is_low)
            {
                printf("Temperature has risen from low to safe.\n");
                is_low = false;
            }
            else
            {
                printf("Temperature is safe.\n");
            }
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}

float read_temperature(void)
{
    float temperature;

    printf("Please enter temperature value (Celsius): ");
    scanf("%f", &temperature);

    return temperature;
}