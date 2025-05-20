//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: genius
#include <stdio.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void displayMenu() {
    printf("\n=== Temperature Converter ===\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("=============================\n");
    printf("Choose your option (1-3): ");
}

int main() {
    int choice;
    float temperature, result;

    printf("Welcome to the Temperature Converter!\n");
    printf("Now you can effortlessly convert temperatures between Celsius and Fahrenheit.\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You chose: Convert Celsius to Fahrenheit\n");
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                result = celsiusToFahrenheit(temperature);
                printf("Temperature %.2f°C is equivalent to %.2f°F\n", temperature, result);
                break;

            case 2:
                printf("You chose: Convert Fahrenheit to Celsius\n");
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                result = fahrenheitToCelsius(temperature);
                printf("Temperature %.2f°F is equivalent to %.2f°C\n", temperature, result);
                break;

            case 3:
                printf("Thank you for using the Temperature Converter. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please select 1, 2, or 3.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}