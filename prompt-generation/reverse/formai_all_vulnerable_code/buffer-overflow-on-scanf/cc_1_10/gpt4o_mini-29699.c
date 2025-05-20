//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
void display_conversion_menu();
void get_temperature_input(float *temperature, char scale);

int main() {
    char choice;
    float temperature;

    // Welcome message
    printf("Welcome to the Temperature Converter!\n");
    printf("This program allows you to convert between Celsius and Fahrenheit.\n");

    do {
        display_conversion_menu();
        printf("Enter your choice (C/F/Q): ");
        scanf(" %c", &choice);

        // Handle user choice
        switch (choice) {
            case 'C':
            case 'c':
                get_temperature_input(&temperature, 'C');
                float fahrenheit = celsius_to_fahrenheit(temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, fahrenheit);
                break;

            case 'F':
            case 'f':
                get_temperature_input(&temperature, 'F');
                float celsius = fahrenheit_to_celsius(temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, celsius);
                break;

            case 'Q':
            case 'q':
                printf("Thank you for using the Temperature Converter! Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 'Q' && choice != 'q');

    return 0;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to display conversion options
void display_conversion_menu() {
    printf("Please choose a conversion option:\n");
    printf("C - Convert Celsius to Fahrenheit\n");
    printf("F - Convert Fahrenheit to Celsius\n");
    printf("Q - Quit the program\n");
}

// Function to get temperature input based on the scale
void get_temperature_input(float *temperature, char scale) {
    if(scale == 'C' || scale == 'c') {
        printf("Enter temperature in Celsius: ");
    } else {
        printf("Enter temperature in Fahrenheit: ");
    }
    scanf("%f", temperature);
}