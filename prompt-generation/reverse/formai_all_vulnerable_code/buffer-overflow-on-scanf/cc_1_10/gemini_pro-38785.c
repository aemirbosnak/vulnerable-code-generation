//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome message
    printf("*****************************************\n");
    printf("* Welcome to the Retro Temperature Monitor *");
    printf("\n*****************************************\n\n");

    // Variables
    int temperature;
    int max_temperature = 0;
    int min_temperature = 100;
    int avg_temperature = 0;
    int total_temperature = 0;
    int num_readings = 0;

    // Main loop
    while (1)
    {
        // Get temperature reading
        printf("Enter temperature reading (°C): ");
        scanf("%d", &temperature);

        // Update variables
        total_temperature += temperature;
        num_readings++;

        // Update max and min
        if (temperature > max_temperature)
            max_temperature = temperature;
        if (temperature < min_temperature)
            min_temperature = temperature;

        // Display current readings
        printf("Current temperature: %d°C\n", temperature);
        printf("Highest temperature: %d°C\n", max_temperature);
        printf("Lowest temperature: %d°C\n\n", min_temperature);

        // Display average
        if (num_readings > 0)
        {
            avg_temperature = total_temperature / num_readings;
            printf("Average temperature: %d°C\n\n", avg_temperature);
        }

        // Exit loop if user enters -1
        if (temperature == -1)
            break;
    }

    // Goodbye message
    printf("\nThank you for using the Retro Temperature Monitor!\n");

    return 0;
}