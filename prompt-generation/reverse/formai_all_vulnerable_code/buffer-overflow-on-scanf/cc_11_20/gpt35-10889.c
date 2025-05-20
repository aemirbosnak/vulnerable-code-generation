//FormAI DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables for user input
    int userChoice, temperature, humidity, windSpeed;
    
    // Declare variables for random weather simulation
    int randomTemp, randomHumidity, randomWindSpeed;
    
    // Seed the random number generator with current time
    srand(time(NULL));
    
    // Display menu options to user
    printf("Select an option:\n");
    printf("1. Enter weather data manually\n");
    printf("2. Simulate random weather data\n");
    scanf("%d", &userChoice);
    
    if(userChoice == 1)
    {
        // Prompt user to input temperature, humidity, and wind speed
        printf("Enter temperature in Celsius: ");
        scanf("%d", &temperature);
        printf("Enter humidity in percentage: ");
        scanf("%d", &humidity);
        printf("Enter wind speed in km/h: ");
        scanf("%d", &windSpeed);
    }
    else if(userChoice == 2)
    {
        // Generate random temperature between -10 and 40 degrees Celsius
        randomTemp = rand() % 51 - 10;
        
        // Generate random humidity between 20 and 100 percent
        randomHumidity = rand() % 81 + 20;
        
        // Generate random wind speed between 0 and 100 km/h
        randomWindSpeed = rand() % 101;
        
        // Set temperature, humidity, and wind speed to random values
        temperature = randomTemp;
        humidity = randomHumidity;
        windSpeed = randomWindSpeed;
    }
    else
    {
        // Display error message and exit program
        printf("Invalid choice. Please select 1 or 2.\n");
        return 0;
    }
    
    // Display weather data to user
    printf("Current weather conditions:\n");
    printf("- Temperature: %d degrees Celsius\n", temperature);
    printf("- Humidity: %d percent\n", humidity);
    printf("- Wind speed: %d km/h\n", windSpeed);
    
    // Determine weather condition based on temperature and humidity
    if(temperature < 0 && humidity > 80)
    {
        printf("Weather condition: Snowstorm\n");
    }
    else if(temperature >= 0 && temperature < 10 && humidity > 80)
    {
        printf("Weather condition: Rainy\n");
    }
    else if(temperature >= 10 && temperature < 20 && humidity > 60)
    {
        printf("Weather condition: Cloudy\n");
    }
    else if(temperature >= 20 && temperature < 30 && humidity > 50)
    {
        printf("Weather condition: Partly cloudy\n");
    }
    else if(temperature >= 30 && humidity < 50 && windSpeed < 20)
    {
        printf("Weather condition: Sunny\n");
    }
    else if(temperature >= 30 && humidity >= 50 && windSpeed >= 20)
    {
        printf("Weather condition: Hurricane\n");
    }
    else
    {
        printf("Weather condition: Unknown\n");
    }
    
    return 0;
}