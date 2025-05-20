//FormAI DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Creating a random number generator seed
    srand(time(NULL));

    // Variables for Celsius and Fahrenheit
    int celsius, fahrenheit;

    // Displaying initial message
    printf("This is a weather simulation program.\n");
    printf("Enter a temperature in Celsius: ");

    // Gathering user input for Celsius temperature
    scanf("%d", &celsius);

    // Converting Celsius to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;

    // Displaying conversion results
    printf("%d degrees Celsius is %d degrees Fahrenheit.\n", celsius, fahrenheit);
    printf("Simulating weather patterns...\n");

    // Generating random weather conditions
    int weather = rand() % 3;
    switch(weather) {
        case 0:
            printf("It is currently sunny outside.\n");
            break;
        case 1:
            printf("It is currently cloudy outside.\n");
            break;
        case 2:
            printf("It is currently rainy outside.\n");
            break;
        default:
            printf("Error: invalid weather condition.\n");
            break;
    }

    // Generating random wind speed between 0 and 50 mph
    int wind_speed = rand() % 51;
    printf("The wind speed is currently %d mph.\n", wind_speed);

    // Generating random humidity level between 0 and 100 percent
    int humidity = rand() % 101;
    printf("The humidity level is currently %d percent.\n", humidity);

    // Generating random air pressure between 970 and 1030 millibars
    int air_pressure = rand() % 61 + 970;
    printf("The air pressure is currently %d millibars.\n", air_pressure);

    // Displaying final message
    printf("Thank you for using the weather simulation program.\n");

    return 0;
}