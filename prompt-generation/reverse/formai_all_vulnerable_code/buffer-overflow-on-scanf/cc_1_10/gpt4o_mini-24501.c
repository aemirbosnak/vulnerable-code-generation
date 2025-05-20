//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n*************************************\n");
    printf("*           Temperature Converter    *\n");
    printf("*************************************\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("*************************************\n");
    printf("Please select an option (1-3): ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    int choice;
    float temperature, convertedTemperature;

    while (1) {
        displayMenu();
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("Surprisingly, the temperature in Fahrenheit is: %.2f°F\n", convertedTemperature);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("Unexpectedly, the temperature in Celsius is: %.2f°C\n", convertedTemperature);
                break;
            case 3:
                printf("Thank you for using the Temperature Converter! Exiting...\n");
                exit(0);
            default:
                printf("Wow! That option is not valid. Please choose 1-3.\n");
        }
    }
    return 0;
}