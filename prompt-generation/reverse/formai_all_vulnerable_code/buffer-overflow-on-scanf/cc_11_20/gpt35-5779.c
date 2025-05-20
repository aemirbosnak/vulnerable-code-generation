//FormAI DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    float temperature = 20.0; // initial temperature in degrees Celsius
    int humidity = 50; // initial humidity in percentage
    int windSpeed = 5; // initial wind speed in km/h
    char skyCondition[10] = "Clear"; // initial sky condition
    char date[20];

    printf("Enter today's date (dd-mm-yyyy): ");
    scanf("%s", date);

    // Print header
    printf("Weather simulation for %s\n", date);
    printf("======================================\n");

    // Simulate weather for the next 24 hours
    for (int i = 1; i <= 24; i++) {

        // Generate random changes in temperature, humidity, wind speed and sky condition
        float tempChange = (float)(rand() % 10) * 0.1 - 0.5; // random change in temperature
        int humChange = rand() % 6 - 3; // random change in humidity
        int windChange = rand() % 5 - 2; // random change in wind speed
        int skyChange = rand() % 10; // random number to determine sky condition change

        // Apply changes
        temperature += tempChange;
        humidity += humChange;
        windSpeed += windChange;

        // Determine the new sky condition
        switch(skyChange) {
            case 0:
            case 1:
                strcpy(skyCondition, "Clear");
                break;
            case 2:
            case 3:
                strcpy(skyCondition, "Partly cloudy");
                break;
            case 4:
            case 5:
                strcpy(skyCondition, "Mostly cloudy");
                break;
            case 6:
            case 7:
                strcpy(skyCondition, "Overcast");
                break;
            case 8:
            case 9:
                strcpy(skyCondition, "Rainy");
                break;
        }

        // Print simulated weather for this hour
        printf("Hour %d: %.1f C, %d%% humidity, %d km/h wind, %s\n", i, temperature, humidity, windSpeed, skyCondition);
    }

    return 0;
}