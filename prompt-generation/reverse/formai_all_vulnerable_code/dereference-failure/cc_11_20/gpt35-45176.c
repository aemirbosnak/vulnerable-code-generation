//FormAI DATASET v1.0 Category: Weather simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Initialize weather variables
    int temperature = 0;
    int humidity = 0;
    int wind_speed = 0;
    char sky[10];

    // Generate random weather variables
    temperature = rand() % 50 - 10; // temperature range: -10 to 40 degrees Celsius
    humidity = rand() % 100; // humidity range: 0 to 100%
    wind_speed = rand() % 40; // wind speed range: 0 to 40 km/h

    // Determine sky conditions based on humidity and temperature
    if (temperature >= 30 && humidity >= 60)
    {
        strcpy(sky, "hot and humid");
    }
    else if (temperature > 20 && temperature < 30 && humidity > 50)
    {
        strcpy(sky, "partly cloudy");
    }
    else if (temperature > 10 && temperature <= 20 && humidity < 70)
    {
        strcpy(sky, "sunny");
    }
    else if (temperature < 0 && humidity < 30)
    {
        strcpy(sky, "snowing");
    }
    else
    {
        strcpy(sky, "cloudy");
    }

    // Print weather information
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Sky: %s\n", sky);

    return 0;
}