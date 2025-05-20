//FormAI DATASET v1.0 Category: Weather simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temp, minTemp, maxTemp, randomTemp, humidity, windSpeed, cloudCoverage;
    char weatherConditions[10];
    srand(time(0)); //seeding the random function with current time

    printf("Welcome to the weather simulator\n\n");

    //getting user inputs
    printf("Enter minimum temperature: ");
    scanf("%d", &minTemp);

    printf("Enter maximum temperature: ");
    scanf("%d", &maxTemp);

    printf("Enter humidity (in percentage): ");
    scanf("%d", &humidity);

    printf("Enter wind speed (in km/h): ");
    scanf("%d", &windSpeed);

    printf("Enter cloud coverage (in percentage): ");
    scanf("%d", &cloudCoverage);

    //generating random temperature within the given range by user
    randomTemp = (rand() % (maxTemp - minTemp + 1)) + minTemp;

    //determining weather conditions based on humidity, wind speed and cloud coverage inputs
    if (humidity >= 80)
    {
        if (cloudCoverage >= 70)
            strcpy(weatherConditions, "Rainy");
        else
            strcpy(weatherConditions, "Cloudy");
    }
    else if (humidity >= 60)
    {
        if (windSpeed >= 25)
            strcpy(weatherConditions, "Windy");
        else
            strcpy(weatherConditions, "Partly cloudy");
    }
    else
    {
        if (cloudCoverage >= 50)
            strcpy(weatherConditions, "Mostly cloudy");
        else
            strcpy(weatherConditions, "Sunny");
    }

    //printing weather report
    printf("\n\nWeather Report:\n");
    printf("Temperature: %d°C\n", randomTemp);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", windSpeed);
    printf("Cloud Coverage: %d%%\n", cloudCoverage);
    printf("Weather Conditions: %s\n", weatherConditions);

    return 0;
}