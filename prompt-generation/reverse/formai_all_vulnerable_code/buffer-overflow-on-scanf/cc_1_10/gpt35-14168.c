//FormAI DATASET v1.0 Category: Temperature monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int temperature = 0;
    int prevTemp = 0;
    int highTempCount = 0;
    int lowTempCount = 0;

    printf("Welcome to the temperature monitor!\n");

    while(1)
    {
        printf("Please enter the current temperature: ");
        scanf("%d", &temperature);

        if(temperature > prevTemp)
        {
            highTempCount++;
        }
        else if(temperature < prevTemp)
        {
            lowTempCount++;
        }

        if(highTempCount == 3)
        {
            printf("WARNING: Temperature is climbing rapidly!\n");
            highTempCount = 0;
        }
        else if(lowTempCount == 3)
        {
            printf("WARNING: Temperature is dropping rapidly!\n");
            lowTempCount = 0;
        }

        if(temperature > 100)
        {
            printf("Temperature is too high! Initiating emergency cooling measures...\n");
            sleep(5);
            printf("Cooling measures complete.\n");
        }

        prevTemp = temperature;
    }

    return 0;
}