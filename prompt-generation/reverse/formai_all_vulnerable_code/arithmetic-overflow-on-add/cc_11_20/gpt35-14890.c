//FormAI DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);               // Wait for the specified seconds
}

int main() {
    int temperature = 68;                     // Default temperature is 68 degrees in Fahrenheit
    int pressure = 1013;                       // Default pressure is 1013 hPa
    int humidity = 50;                         // Default humidity is 50 percent
    int windSpeed = 5;                         // Default wind speed is 5 mph
    int clouds = 0;                            // Default cloud cover is 0 percent

    srand(time(NULL));                         // Initialize random seed

    printf("Simulating weather conditions...\n");

    for (int hour = 0; hour < 24; hour++) {
        printf("Hour %d\n", hour);

        // Adjust temperature based on time of day
        if (hour >= 6 && hour < 12) {           // Morning
            temperature += (rand() % 5) - 2;    // Random temperature change from -2 to +2 degrees Fahrenheit
        }
        else if (hour >= 12 && hour < 18) {     // Afternoon
            temperature += (rand() % 10) - 5;   // Random temperature change from -5 to +5 degrees Fahrenheit
        }
        else {                                  // Evening and night
            temperature += (rand() % 3) - 1;    // Random temperature change from -1 to +1 degrees Fahrenheit
        }

        // Adjust pressure based on weather conditions
        if (temperature > 80 && humidity > 60) {
            pressure -= (rand() % 5);           // Random pressure decrease from 0 to 4 hPa
            if (pressure < 990) {
                pressure = 990;                 // Minimum pressure is 990 hPa
            }
        }
        else if (temperature < 60 && humidity < 40) {
            pressure += (rand() % 5);           // Random pressure increase from 0 to 4 hPa
            if (pressure > 1030) {
                pressure = 1030;                // Maximum pressure is 1030 hPa
            }
        }

        // Adjust humidity based on temperature and time of day
        if (temperature > 90) {
            humidity -= (rand() % 10);          // Random humidity decrease from 0 to 9 percent
            if (humidity < 20) {
                humidity = 20;                  // Minimum humidity is 20 percent
            }
        }
        else if (temperature < 40) {
            humidity += (rand() % 10);          // Random humidity increase from 0 to 9 percent
            if (humidity > 80) {
                humidity = 80;                  // Maximum humidity is 80 percent
            }
        }
        else {
            if (hour >= 12 && hour < 18) {      // Afternoon
                humidity -= (rand() % 5);       // Random humidity decrease from 0 to 4 percent
            }
            else {                              // Morning, evening, and night
                humidity += (rand() % 5);       // Random humidity increase from 0 to 4 percent
            }
            if (humidity < 30) {
                humidity = 30;                  // Minimum humidity is 30 percent
            }
            else if (humidity > 70) {
                humidity = 70;                  // Maximum humidity is 70 percent
            }
        }

        // Adjust wind speed based on pressure and humidity
        if (pressure < 1000 && humidity > 50) {
            windSpeed += (rand() % 5);           // Random wind speed increase from 0 to 4 mph
            if (windSpeed > 20) {
                windSpeed = 20;                  // Maximum wind speed is 20 mph
            }
        }
        else if (pressure > 1020 && humidity < 40) {
            windSpeed -= (rand() % 5);           // Random wind speed decrease from 0 to 4 mph
            if (windSpeed < 0) {
                windSpeed = 0;                   // Minimum wind speed is 0 mph
            }
        }

        // Adjust cloud cover based on humidity and wind speed
        if (humidity > 60 && windSpeed > 10) {
            clouds += (rand() % 10);             // Random cloud cover increase from 0 to 9 percent
            if (clouds > 80) {
                clouds = 80;                     // Maximum cloud cover is 80 percent
            }
        }
        else if (humidity < 40 && windSpeed < 5) {
            clouds -= (rand() % 10);             // Random cloud cover decrease from 0 to 9 percent
            if (clouds < 0) {
                clouds = 0;                      // Minimum cloud cover is 0 percent
            }
        }

        printf("   Temperature: %d F\n", temperature);
        printf("   Pressure: %d hPa\n", pressure);
        printf("   Humidity: %d%%\n", humidity);
        printf("   Wind speed: %d mph\n", windSpeed);
        printf("   Cloud cover: %d%%\n", clouds);

        if (hour < 23) {
            printf("Waiting for 1 hour...\n");
            waitFor(1);
        }

        else {
            printf("Simulation complete!\n");
        }
    }

    return 0;
}