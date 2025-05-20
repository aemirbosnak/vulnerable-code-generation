//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: authentic
#include <stdio.h>
#include <stdbool.h>

void printMenu() {
    printf("\n=== Temperature Converter ===\n");
    printf("Select the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
    printf("=============================\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

int main() {
    int choice;
    float inputTemp, outputTemp;

    while (true) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }

        printf("Enter the temperature value: ");
        if (scanf("%f", &inputTemp) != 1) {
            printf("Invalid input! Please enter a numeric value.\n");
            while(getchar() != '\n'); // Clear the invalid input
            continue;
        }

        switch (choice) {
            case 1:
                outputTemp = celsiusToFahrenheit(inputTemp);
                printf("%.2f Celsius is %.2f Fahrenheit\n", inputTemp, outputTemp);
                break;
            case 2:
                outputTemp = celsiusToKelvin(inputTemp);
                printf("%.2f Celsius is %.2f Kelvin\n", inputTemp, outputTemp);
                break;
            case 3:
                outputTemp = fahrenheitToCelsius(inputTemp);
                printf("%.2f Fahrenheit is %.2f Celsius\n", inputTemp, outputTemp);
                break;
            case 4:
                outputTemp = fahrenheitToKelvin(inputTemp);
                printf("%.2f Fahrenheit is %.2f Kelvin\n", inputTemp, outputTemp);
                break;
            case 5:
                outputTemp = kelvinToCelsius(inputTemp);
                printf("%.2f Kelvin is %.2f Celsius\n", inputTemp, outputTemp);
                break;
            case 6:
                outputTemp = kelvinToFahrenheit(inputTemp);
                printf("%.2f Kelvin is %.2f Fahrenheit\n", inputTemp, outputTemp);
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }
    
    return 0;
}