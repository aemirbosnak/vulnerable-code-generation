//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void display_menu();
void fahrenheit_to_celsius();
void celsius_to_fahrenheit();
void celsius_to_kelvin();
void kelvin_to_celsius();
void fahrenheit_to_kelvin();
void kelvin_to_fahrenheit();
void display_error();

int main() {
    int choice;

    while (1) {
        display_menu();
        
        printf("Select an option (1-7, or 0 to exit): ");
        if (scanf("%d", &choice) != 1) {
            display_error();
            // Clear the input buffer if the input was invalid
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                fahrenheit_to_celsius();
                break;
            case 2:
                celsius_to_fahrenheit();
                break;
            case 3:
                celsius_to_kelvin();
                break;
            case 4:
                kelvin_to_celsius();
                break;
            case 5:
                fahrenheit_to_kelvin();
                break;
            case 6:
                kelvin_to_fahrenheit();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                display_error();
                break;
        }
    }
    return 0;
}

void display_menu() {
    printf("\n=== Temperature Converter ===\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

void fahrenheit_to_celsius() {
    double fahrenheit, celsius;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("%.2lf °F is equivalent to %.2lf °C.\n", fahrenheit, celsius);
}

void celsius_to_fahrenheit() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0 / 5.0) + 32;
    printf("%.2lf °C is equivalent to %.2lf °F.\n", celsius, fahrenheit);
}

void celsius_to_kelvin() {
    double celsius, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    kelvin = celsius + 273.15;
    printf("%.2lf °C is equivalent to %.2lf K.\n", celsius, kelvin);
}

void kelvin_to_celsius() {
    double kelvin, celsius;
    printf("Enter temperature in Kelvin: ");
    scanf("%lf", &kelvin);
    celsius = kelvin - 273.15;
    printf("%.2lf K is equivalent to %.2lf °C.\n", kelvin, celsius);
}

void fahrenheit_to_kelvin() {
    double fahrenheit, kelvin;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    kelvin = (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
    printf("%.2lf °F is equivalent to %.2lf K.\n", fahrenheit, kelvin);
}

void kelvin_to_fahrenheit() {
    double kelvin, fahrenheit;
    printf("Enter temperature in Kelvin: ");
    scanf("%lf", &kelvin);
    fahrenheit = (kelvin - 273.15) * 9.0 / 5.0 + 32;
    printf("%.2lf K is equivalent to %.2lf °F.\n", kelvin, fahrenheit);
}

void display_error() {
    printf("Invalid input. Please select a valid option (0-6).\n");
}