//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the current date and time
void printDateTime() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("Current date and time: %s", asctime(t));
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

int main() {
    float temperature;
    char choice;

    do {
        // Display menu options
        printf("\nTemperature Monitor Menu:\n");
        printf("1. Enter temperature in Celsius\n");
        printf("2. Enter temperature in Fahrenheit\n");
        printf("3. Convert Celsius to Fahrenheit\n");
        printf("4. Convert Fahrenheit to Celsius\n");
        printf("5. Display current date and time\n");
        printf("6. Exit\n");

        // Get user choice
        scanf("%c", &choice);

        // Perform selected option
        switch(choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, fahrenheitToCelsius(temperature));
                break;
            case '3':
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
                break;
            case '4':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, fahrenheitToCelsius(temperature));
                break;
            case '5':
                printDateTime();
                break;
            case '6':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '6');

    return 0;
}