//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);

void display_menu();
void handle_conversion(int choice);

int main() {
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("-----------------------------------------------------\n");

    do {
        display_menu();
        printf("Enter your choice (1-6) or 0 to exit: ");
        scanf("%d", &choice);
        if (choice < 0 || choice > 6) {
            printf("Invalid choice, please try again.\n");
        } else if (choice != 0) {
            handle_conversion(choice);
        }
    } while (choice != 0);

    printf("Thank you for using the Temperature Converter. Goodbye!\n");
    return 0;
}

void display_menu() {
    printf("\nTemperature Conversion Options:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
}

void handle_conversion(int choice) {
    float temperature, result;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            result = celsius_to_fahrenheit(temperature);
            printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            result = fahrenheit_to_celsius(temperature);
            printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, result);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            result = celsius_to_kelvin(temperature);
            printf("%.2f Celsius = %.2f Kelvin\n", temperature, result);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &temperature);
            result = kelvin_to_celsius(temperature);
            printf("%.2f Kelvin = %.2f Celsius\n", temperature, result);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            result = fahrenheit_to_kelvin(temperature);
            printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, result);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &temperature);
            result = kelvin_to_fahrenheit(temperature);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, result);
            break;
        default:
            printf("Something went wrong!\n");
            break;
    }
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}