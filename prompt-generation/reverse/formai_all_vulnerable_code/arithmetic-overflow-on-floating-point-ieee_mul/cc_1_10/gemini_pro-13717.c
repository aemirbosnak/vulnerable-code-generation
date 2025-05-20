//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to print the temperature conversion table
void print_temperature_conversion_table() {
    printf("Celsius | Fahrenheit\n");
    printf("--------------------\n");
    for (float celsius = 0; celsius <= 100; celsius += 10) {
        float fahrenheit = celsius_to_fahrenheit(celsius);
        printf("%6.1f | %7.1f\n", celsius, fahrenheit);
    }
}

int main() {
    // Print a welcome message
    printf("Welcome to the temperature converter!\n\n");

    // Get the user's input
    printf("Enter the temperature you want to convert: ");
    float temperature;
    scanf("%f", &temperature);

    // Get the user's choice of conversion type
    printf("Enter the conversion type (C/F): ");
    char conversion_type;
    scanf(" %c", &conversion_type);

    // Convert the temperature based on the user's choice
    float converted_temperature;
    switch (conversion_type) {
        case 'C':
            converted_temperature = celsius_to_fahrenheit(temperature);
            printf("%.1f Celsius is %.1f Fahrenheit.\n", temperature, converted_temperature);
            break;
        case 'F':
            converted_temperature = fahrenheit_to_celsius(temperature);
            printf("%.1f Fahrenheit is %.1f Celsius.\n", temperature, converted_temperature);
            break;
        default:
            printf("Invalid conversion type. Please enter 'C' for Celsius to Fahrenheit or 'F' for Fahrenheit to Celsius.\n");
    }

    // Print the temperature conversion table
    printf("\nTemperature Conversion Table:\n");
    print_temperature_conversion_table();

    return 0;
}