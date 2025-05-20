//FormAI DATASET v1.0 Category: Weather simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    float temperature = 0; //temperature in Celsius
    float humidity = 0; //humidity percentage
    float precipitation = 0; //precipitation amount in millimeters
    float windSpeed = 0; //wind speed in km/h
    int cloudCover = 0; //percentage of cloudy sky
    int currentHour = 0; //current hour of the day

    printf("Welcome to the Weather Simulation!\n");
    printf("Enter the current hour (0-23): ");
    scanf("%d", &currentHour);

    printf("\nHour %d Weather Report:\n", currentHour);

    //generate random weather data based on the current hour
    if (currentHour >= 6 && currentHour < 12) { //morning
        temperature = (rand() % (16 - 10 + 1)) + 10; //10°C - 16°C
        humidity = (rand() % (90 - 60 + 1)) + 60; //60% - 90%
        precipitation = (rand() % 3) / 10.0; //0 - 0.2 mm
        windSpeed = (rand() % (10 - 5 + 1)) + 5; //5 km/h - 10 km/h
        cloudCover = (rand() % (40 - 20 + 1)) + 20; //20% - 40%
    }
    else if (currentHour >= 12 && currentHour < 18) { //afternoon
        temperature = (rand() % (20 - 16 + 1)) + 16; //16°C - 20°C
        humidity = (rand() % (70 - 40 + 1)) + 40; //40% - 70%
        precipitation = (rand() % 3) / 10.0; //0 - 0.2 mm
        windSpeed = (rand() % (15 - 10 + 1)) + 10; //10 km/h - 15 km/h
        cloudCover = (rand() % (50 - 30 + 1)) + 30; //30% - 50%
    }
    else if (currentHour >= 18 && currentHour < 24) { //evening
        temperature = (rand() % (18 - 14 + 1)) + 14; //14°C - 18°C
        humidity = (rand() % (80 - 50 + 1)) + 50; //50% - 80%
        precipitation = (rand() % 3) / 10.0; //0 - 0.2 mm
        windSpeed = (rand() % (10 - 5 + 1)) + 5; //5 km/h - 10 km/h
        cloudCover = (rand() % (60 - 40 + 1)) + 40; //40% - 60%
    }
    else if (currentHour >= 0 && currentHour < 6) { //night
        temperature = (rand() % (12 - 8 + 1)) + 8; //8°C - 12°C
        humidity = (rand() % (90 - 70 + 1)) + 70; //70% - 90%
        precipitation = (rand() % 3) / 10.0; //0 - 0.2 mm
        windSpeed = (rand() % (5 - 0 + 1)); //0 km/h - 5 km/h
        cloudCover = (rand() % (20 - 0 + 1)); //0% - 20%
    }

    //print out the weather report
    printf("Temperature: %.1f°C\n", temperature);
    printf("Humidity: %.1f%%\n", humidity);
    printf("Precipitation: %.1f mm\n", precipitation);
    printf("Wind Speed: %.1f km/h\n", windSpeed);
    printf("Cloud Cover: %d%%\n", cloudCover);

    return 0;
}