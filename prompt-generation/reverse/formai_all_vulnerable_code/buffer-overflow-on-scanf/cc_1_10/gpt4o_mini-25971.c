//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>

void displayMenu() {
    printf("\n--- Temperature Converter ---\n");
    printf("Select conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float fahrenheitToKelvin(float fahrenheit) {
    float celsius = fahrenheitToCelsius(fahrenheit);
    return celsiusToKelvin(celsius);
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    float celsius = kelvinToCelsius(kelvin);
    return celsiusToFahrenheit(celsius);
}

int main() {
    int choice;
    float inputTemp, convertedTemp;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter a number.\n");
            while(getchar() != '\n'); // Clear buffer
            continue;
        }

        if (choice == 0) {
            printf("Exiting the Temperature Converter. Have a nice day!\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Please select a valid option from the menu.\n");
            continue;
        }

        printf("Enter the temperature to convert: ");
        if (scanf("%f", &inputTemp) != 1) {
            printf("Invalid input for temperature. Please try again.\n");
            while(getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                convertedTemp = celsiusToFahrenheit(inputTemp);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", inputTemp, convertedTemp);
                break;
            case 2:
                convertedTemp = celsiusToKelvin(inputTemp);
                printf("%.2f Celsius is %.2f Kelvin.\n", inputTemp, convertedTemp);
                break;
            case 3:
                convertedTemp = fahrenheitToCelsius(inputTemp);
                printf("%.2f Fahrenheit is %.2f Celsius.\n", inputTemp, convertedTemp);
                break;
            case 4:
                convertedTemp = fahrenheitToKelvin(inputTemp);
                printf("%.2f Fahrenheit is %.2f Kelvin.\n", inputTemp, convertedTemp);
                break;
            case 5:
                convertedTemp = kelvinToCelsius(inputTemp);
                printf("%.2f Kelvin is %.2f Celsius.\n", inputTemp, convertedTemp);
                break;
            case 6:
                convertedTemp = kelvinToFahrenheit(inputTemp);
                printf("%.2f Kelvin is %.2f Fahrenheit.\n", inputTemp, convertedTemp);
                break;
        }
    }

    return 0;
}