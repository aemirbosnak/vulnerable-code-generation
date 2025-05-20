//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: light-weight
#include <stdio.h>

void displayMenu() {
    printf("\n====== Temperature Converter ======\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("===================================\n");
    printf("Please select an option (1-3): ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

void convertTemperature() {
    int choice;
    float temperature, convertedTemperature;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, convertedTemperature);
        } else if (choice == 2) {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, convertedTemperature);
        } else if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }
}

void suggestPurpose() {
    printf("\n====== Temperature Conversion Utilities ======\n");
    printf("Did you know? Temperature conversions can help you in cooking, weather reports, and scientific research!\n");
    printf("This simple program is useful when you need to convert measurements quickly without a calculator.\n");
    printf("Temperature conversions are also handy while traveling to different countries where Celsius and Fahrenheit are used.\n");
    printf("Make sure to check your measurements before jumping into activities like cooking or experimenting!\n");
    printf("===============================================\n");
}

int main() {
    printf("Welcome to the Temperature Converter!\n");
    suggestPurpose();
    convertTemperature();
    
    return 0;
}