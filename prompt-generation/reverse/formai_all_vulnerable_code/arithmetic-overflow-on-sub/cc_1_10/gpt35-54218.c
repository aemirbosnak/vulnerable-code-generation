//FormAI DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_MIN -50.0
#define TEMP_MAX 100.0

int main()
{
    double currentTemp = 20.0;
    double tempThreshold = 30.0;
    clock_t lastTime = clock();

    printf("Current temperature: %lf\n", currentTemp);

    while (1)
    {
        // Check if it's been 30 seconds since the last temperature update
        if (clock() - lastTime >= CLOCKS_PER_SEC * 30)
        {
            // Generate a random temperature change between -5 and 5 degrees
            double tempChange = ((double)rand() / RAND_MAX) * 10.0 - 5.0;
            currentTemp += tempChange;

            // Clamp the temperature within the valid range
            if (currentTemp < TEMP_MIN)
            {
                currentTemp = TEMP_MIN;
            }
            else if (currentTemp > TEMP_MAX)
            {
                currentTemp = TEMP_MAX;
            }

            printf("Current temperature: %lf\n", currentTemp);
            lastTime = clock();
        }

        // Check if the temperature has exceeded the threshold
        if (currentTemp >= tempThreshold)
        {
            printf("Temperature threshold exceeded! Current temp: %lf\n", currentTemp);
            // Prompt user to set a new threshold
            printf("Enter new temperature threshold: ");
            scanf("%lf", &tempThreshold);
        }
    }

    return 0;
}