//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int weather_type;
    int temperature;
    int humidity;
    int wind_speed;
    int cloud_coverage;
    int precipitation;
    int num_days;

    // Get user input for number of days to simulate
    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    // Initialize random seed
    srand(time(NULL));

    // Loop through each day and generate weather conditions
    for (int i = 0; i < num_days; i++) {
        // Generate weather type
        weather_type = rand() % 5;

        // Generate temperature
        temperature = rand() % 41 - 20;

        // Generate humidity
        humidity = rand() % 81;

        // Generate wind speed
        wind_speed = rand() % 21;

        // Generate cloud coverage
        cloud_coverage = rand() % 101;

        // Generate precipitation
        precipitation = rand() % 2;

        // Print weather conditions for each day
        printf("Day %d:\n", i + 1);
        printf("Weather type: ");
        switch (weather_type) {
            case 0:
                printf("Sunny\n");
                break;
            case 1:
                printf("Cloudy\n");
                break;
            case 2:
                printf("Rainy\n");
                break;
            case 3:
                printf("Stormy\n");
                break;
            case 4:
                printf("Snowy\n");
                break;
            default:
                printf("Invalid weather type\n");
        }
        printf("Temperature: %d degrees Celsius\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind speed: %d km/h\n", wind_speed);
        printf("Cloud coverage: %d%%\n", cloud_coverage);
        printf("Precipitation: %s\n", precipitation == 0? "No" : "Yes");
        printf("\n");
    }

    return 0;
}