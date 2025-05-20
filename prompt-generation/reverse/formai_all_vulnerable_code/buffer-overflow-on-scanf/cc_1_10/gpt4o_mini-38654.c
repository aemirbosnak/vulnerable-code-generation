//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToCelsius(float kelvin);
float kelvinToFahrenheit(float kelvin);

int main() {
    int choice;
    float inputTemp, convertedTemp;

    do {
        displayMenu();
        printf("Enter your choice (1-5, or 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Brave adventurer, you have chosen to leave the realm of temperature conversions. Farewell!\n");
            break;
        } else if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please select a valid option.\n");
            continue;
        }

        printf("Enter the temperature to convert: ");
        scanf("%f", &inputTemp);

        switch (choice) {
            case 1:
                convertedTemp = celsiusToFahrenheit(inputTemp);
                printf("%.2f Celsius = %.2f Fahrenheit\n", inputTemp, convertedTemp);
                break;
            case 2:
                convertedTemp = celsiusToKelvin(inputTemp);
                printf("%.2f Celsius = %.2f Kelvin\n", inputTemp, convertedTemp);
                break;
            case 3:
                convertedTemp = fahrenheitToCelsius(inputTemp);
                printf("%.2f Fahrenheit = %.2f Celsius\n", inputTemp, convertedTemp);
                break;
            case 4:
                convertedTemp = fahrenheitToKelvin(inputTemp);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", inputTemp, convertedTemp);
                break;
            case 5:
                convertedTemp = kelvinToCelsius(inputTemp);
                printf("%.2f Kelvin = %.2f Celsius\n", inputTemp, convertedTemp);
                break;
        }
    } while (1);

    return 0;
}

void displayMenu() {
    printf("\n*** Temperature Converter Menu ***\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("0. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float fahrenheitToKelvin(float fahrenheit) {
    return fahrenheitToCelsius(fahrenheit) + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}