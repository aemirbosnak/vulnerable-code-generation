//FormAI DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Declare variables
    int lightLevel = 0;
    int currentTemp = 0;
    int desiredTemp = 0;

    // Prompt user for desired temperature level
    printf("Enter desired temperature level: ");
    scanf("%d", &desiredTemp);

    // Simulate the temperature change
    while (currentTemp != desiredTemp)
    {
        if (currentTemp < desiredTemp)
        {
            currentTemp++;
        }
        else
        {
            currentTemp--;
        }

        // Check the current temperature level
        printf("Current temperature level: %d\n", currentTemp);

        // Simulate the light control
        if (currentTemp >= 20 && currentTemp <= 25)
        {
            lightLevel = 50;
        }
        else if (currentTemp > 25 && currentTemp <= 30)
        {
            lightLevel = 75;
        }
        else if (currentTemp > 30)
        {
            lightLevel = 100;
        }
        else
        {
            lightLevel = 25 + rand() % 25;
        }

        // Display the light level
        printf("Light level: %d\n\n", lightLevel);

        // Wait for 1 second before the next iteration
        sleep(1);
    }

    return 0;
}