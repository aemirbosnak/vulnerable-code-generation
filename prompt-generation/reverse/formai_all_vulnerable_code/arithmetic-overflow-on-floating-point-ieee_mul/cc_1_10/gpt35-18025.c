//FormAI DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>

float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);
void printMenu();
void clearInputBuffer();

int main() {
    float celsiusTemp, fahrenheitTemp, kelvinTemp;
    int option;

    do {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsiusTemp);

                fahrenheitTemp = celsiusToFahrenheit(celsiusTemp);
                printf("Temperature in Fahrenheit: %.2f\n", fahrenheitTemp);

                kelvinTemp = celsiusToKelvin(celsiusTemp);
                printf("Temperature in Kelvin: %.2f\n", kelvinTemp);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheitTemp);

                celsiusTemp = (fahrenheitTemp - 32) * 5 / 9;
                printf("Temperature in Celsius: %.2f\n", celsiusTemp);

                kelvinTemp = celsiusToKelvin(celsiusTemp);
                printf("Temperature in Kelvin: %.2f\n", kelvinTemp);
                break;

            case 3:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &kelvinTemp);

                celsiusTemp = kelvinTemp - 273.15;
                printf("Temperature in Celsius: %.2f\n", celsiusTemp);

                fahrenheitTemp = celsiusToFahrenheit(celsiusTemp);
                printf("Temperature in Fahrenheit: %.2f\n", fahrenheitTemp);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                clearInputBuffer();
        }

        printf("\n");
    } while (option != 4);

    return 0;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

void printMenu() {
    printf("Please select an option:\n");
    printf("1. Convert Celsius to Fahrenheit and Kelvin\n");
    printf("2. Convert Fahrenheit to Celsius and Kelvin\n");
    printf("3. Convert Kelvin to Celsius and Fahrenheit\n");
    printf("4. Exit program\n");
    printf("Enter your option: ");
}

void clearInputBuffer() {
    while (getchar() != '\n');
}