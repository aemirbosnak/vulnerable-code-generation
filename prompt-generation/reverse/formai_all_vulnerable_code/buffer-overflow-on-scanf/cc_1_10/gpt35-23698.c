//FormAI DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>

// Function to generate random temperature between -20 and 50 degrees Celsius
float generateTemperature()
{
    return (float) (rand() % 71) - 20;
}

// Function to generate random rain between 0 and 20 millimeters
int generateRain()
{
    return rand() % 21;
}

// Function to generate random wind speed between 0 and 100 km/h
int generateWindSpeed()
{
    return rand() % 101;
}

int main()
{
    // Seed the random number generator with the current time
    srand((unsigned int) time(NULL));
    
    // Get user input for the number of days to simulate
    int numDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);
    
    for (int i = 1; i <= numDays; i++)
    {
        // Generate weather data for the day
        float temperature = generateTemperature();
        int rain = generateRain();
        int windSpeed = generateWindSpeed();
        
        // Print the weather data for the day
        printf("\nWeather for day %d:\n", i);
        printf("Temperature: %.1f degrees Celsius\n", temperature);
        printf("Rain: %d millimeters\n", rain);
        printf("Wind speed: %d km/h\n", windSpeed);
        
        // Determine the weather forecast for the day
        if (temperature < 0)
        {
            printf("The forecast is for snow.\n");
        }
        else if (temperature < 5 && rain > 0)
        {
            printf("The forecast is for sleet.\n");
        }
        else if (temperature < 20 && rain > 0)
        {
            printf("The forecast is for rain.\n");
        }
        else if (temperature >= 20)
        {
            printf("The forecast is for sunshine.\n");
        }
        else
        {
            printf("The forecast is for cloudy weather.\n");
        }
        
        // Determine whether there is a weather warning for the day
        if (temperature < 0 || (windSpeed > 50 && rain > 0))
        {
            printf("There is a weather warning in effect.\n");
        }
        else
        {
            printf("There are no weather warnings in effect.\n");
        }
    }
    
    return 0;
}