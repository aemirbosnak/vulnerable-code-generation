//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayMenu();
void performConversion(int choice);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        performConversion(choice);
    } while (choice != 3);

    printf("Exiting the temperature converter. Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\n--- Temperature Converter ---\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("----------------------------\n");
}

void performConversion(int choice) {
    float temperature, convertedTemperature;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, convertedTemperature);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, convertedTemperature);
            break;

        case 3:
            // Exit the program
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}