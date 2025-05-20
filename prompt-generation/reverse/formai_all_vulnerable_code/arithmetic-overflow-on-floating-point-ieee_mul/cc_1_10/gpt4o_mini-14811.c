//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: light-weight
#include <stdio.h>

void displayMenu() {
    printf("\n--- Temperature Converter ---\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Celsius to Kelvin\n");
    printf("4. Convert Kelvin to Celsius\n");
    printf("5. Convert Fahrenheit to Kelvin\n");
    printf("6. Convert Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("----------------------------\n");
    printf("Please enter your choice (1-7): ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

int main() {
    int choice;
    float temperature;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Thank you for using the Temperature Converter! Stay warm!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("%.2f Celsius = %.2f Kelvin\n", temperature, celsiusToKelvin(temperature));
                break;
            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                printf("%.2f Kelvin = %.2f Celsius\n", temperature, kelvinToCelsius(temperature));
                break;
            case 5:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, fahrenheitToKelvin(temperature));
                break;
            case 6:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, kelvinToFahrenheit(temperature));
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}