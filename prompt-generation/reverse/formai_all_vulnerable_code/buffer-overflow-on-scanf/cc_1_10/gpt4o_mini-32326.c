//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>

void displayMenu() {
    printf("Temperature Converter\n");
    printf("=====================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("=====================\n");
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
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

void convertTemperature() {
    int choice;
    float temperature, result;

    while (1) {
        displayMenu();
        printf("Choose an option (1-7): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 7.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        if (choice == 7) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Invalid choice! Please select a valid option.\n");
            continue;
        }

        printf("Enter the temperature: ");
        if (scanf("%f", &temperature) != 1) {
            printf("Invalid input! Please enter a valid temperature.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                result = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, result);
                break;
            case 2:
                result = celsiusToKelvin(temperature);
                printf("%.2f Celsius is %.2f Kelvin.\n", temperature, result);
                break;
            case 3:
                result = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius.\n", temperature, result);
                break;
            case 4:
                result = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit is %.2f Kelvin.\n", temperature, result);
                break;
            case 5:
                result = kelvinToCelsius(temperature);
                printf("%.2f Kelvin is %.2f Celsius.\n", temperature, result);
                break;
            case 6:
                result = kelvinToFahrenheit(temperature);
                printf("%.2f Kelvin is %.2f Fahrenheit.\n", temperature, result);
                break;
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Temperature Converter Program!\n");
    convertTemperature();
    return 0;
}