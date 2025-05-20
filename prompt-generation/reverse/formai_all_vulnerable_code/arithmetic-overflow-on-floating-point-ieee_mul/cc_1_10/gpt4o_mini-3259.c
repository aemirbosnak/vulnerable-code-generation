//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Alan Turing
#include <stdio.h>

void displayMenu() {
    printf("*********************\n");
    printf("* Temperature Converter *\n");
    printf("*********************\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void celsiusToFahrenheitConverter() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2lf °C = %.2lf °F\n", celsius, fahrenheit);
}

void fahrenheitToCelsiusConverter() {
    double fahrenheit, celsius;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    celsius = fahrenheitToCelsius(fahrenheit);
    printf("%.2lf °F = %.2lf °C\n", fahrenheit, celsius);
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                celsiusToFahrenheitConverter();
                break;
            case 2:
                fahrenheitToCelsiusConverter();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }

        printf("\n");

    } while (choice != 3);

    return 0;
}