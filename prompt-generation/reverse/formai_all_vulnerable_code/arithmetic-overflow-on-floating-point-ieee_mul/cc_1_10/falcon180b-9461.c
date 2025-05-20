//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to print temperature in Celsius and Fahrenheit
void printTemperature(float celsius) {
    printf("Temperature in Celsius: %.2f C\n", celsius);
    printf("Temperature in Fahrenheit: %.2f F\n", celsiusToFahrenheit(celsius));
}

int main() {
    float temperatureCelsius = 0;
    float temperatureFahrenheit = 0;
    char choice = 'y';
    time_t startTime, endTime;

    while(choice == 'y' || choice == 'Y') {
        printf("\nEnter temperature in Celsius: ");
        scanf("%f", &temperatureCelsius);

        // Convert Celsius to Fahrenheit
        temperatureFahrenheit = celsiusToFahrenheit(temperatureCelsius);

        // Print temperature in Celsius and Fahrenheit
        printf("\nCurrent temperature in Celsius: %.2f C\n", temperatureCelsius);
        printf("Current temperature in Fahrenheit: %.2f F\n", temperatureFahrenheit);

        // Wait for 5 seconds before updating temperature
        time(&startTime);
        while(difftime(time(NULL), startTime) < 5) {
            time(&endTime);
        }

        // Ask user if they want to continue monitoring temperature
        printf("\nDo you want to continue monitoring temperature? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}