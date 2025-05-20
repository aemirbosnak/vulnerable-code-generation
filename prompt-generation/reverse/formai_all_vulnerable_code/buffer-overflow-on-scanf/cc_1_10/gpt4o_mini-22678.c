//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
#include <stdio.h>

// Function prototypes
void display_menu();
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
void convert_temperature();

int main() {
    // Begin the noble task of temperature conversion
    printf("Welcome to the Temperature Converter Program!\n");
    convert_temperature();
    return 0;
}

// Function definitions

void display_menu() {
    printf("\nTemperature Conversion Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Please enter your choice: ");
}

float celsius_to_fahrenheit(float celsius) {
    // Applying the transformation of Celsius to Fahrenheit
    float fahrenheit = (celsius * 9.0 / 5.0) + 32;
    return fahrenheit;
}

float fahrenheit_to_celsius(float fahrenheit) {
    // Applying the transformation of Fahrenheit to Celsius
    float celsius = (fahrenheit - 32) * 5.0 / 9.0;
    return celsius;
}

void convert_temperature() {
    int choice;
    float temperature, converted_temperature;

    while (1) {
        // Displaying the options for conversion
        display_menu();
        scanf("%d", &choice);

        // Handling the user's choice with a grand sense of purpose
        switch (choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &temperature);
                converted_temperature = celsius_to_fahrenheit(temperature);
                printf("Temperature in Fahrenheit: %.2f\n", converted_temperature);
                break;

            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted_temperature = fahrenheit_to_celsius(temperature);
                printf("Temperature in Celsius: %.2f\n", converted_temperature);
                break;

            case 3:
                printf("Exiting the Temperature Converter. Goodbye!\n");
                return;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}