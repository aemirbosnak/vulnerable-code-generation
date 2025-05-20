//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Custom data type for temperature
typedef struct {
    float celsius;
    float fahrenheit;
} Temperature;

// Function to convert Celsius to Fahrenheit
Temperature celsius_to_fahrenheit(float celsius) {
    Temperature temp;
    temp.fahrenheit = (celsius * 9 / 5) + 32;
    temp.celsius = celsius;
    return temp;
}

// Function to convert Fahrenheit to Celsius
Temperature fahrenheit_to_celsius(float fahrenheit) {
    Temperature temp;
    temp.celsius = (fahrenheit - 32) * 5 / 9;
    temp.fahrenheit = fahrenheit;
    return temp;
}

// Function to print the temperature
void print_temperature(Temperature temp, char *unit) {
    printf("Temperature: %.2f %s\n", temp.celsius, unit);
}

// Main function
int main() {
    // Initialize variables
    float temp_value;
    char temp_unit;
    char choice;

    // Get the temperature value and unit
    printf("Enter temperature value: ");
    scanf("%f", &temp_value);
    printf("Enter temperature unit (C/F): ");
    scanf(" %c", &temp_unit);

    // Convert temperature based on the unit
    Temperature converted_temp;
    if (temp_unit == 'C' || temp_unit == 'c') {
        converted_temp = celsius_to_fahrenheit(temp_value);
        print_temperature(converted_temp, "Fahrenheit");
    } else if (temp_unit == 'F' || temp_unit == 'f') {
        converted_temp = fahrenheit_to_celsius(temp_value);
        print_temperature(converted_temp, "Celsius");
    } else {
        printf("Invalid temperature unit. Please enter 'C' for Celsius or 'F' for Fahrenheit.\n");
    }

    // Ask the user if they want to convert another temperature
    printf("Do you want to convert another temperature (Y/N): ");
    scanf(" %c", &choice);

    // Loop until the user enters 'N'
    while (choice == 'Y' || choice == 'y') {
        // Get the temperature value and unit
        printf("Enter temperature value: ");
        scanf("%f", &temp_value);
        printf("Enter temperature unit (C/F): ");
        scanf(" %c", &temp_unit);

        // Convert temperature based on the unit
        if (temp_unit == 'C' || temp_unit == 'c') {
            converted_temp = celsius_to_fahrenheit(temp_value);
            print_temperature(converted_temp, "Fahrenheit");
        } else if (temp_unit == 'F' || temp_unit == 'f') {
            converted_temp = fahrenheit_to_celsius(temp_value);
            print_temperature(converted_temp, "Celsius");
        } else {
            printf("Invalid temperature unit. Please enter 'C' for Celsius or 'F' for Fahrenheit.\n");
        }

        // Ask the user if they want to convert another temperature
        printf("Do you want to convert another temperature (Y/N): ");
        scanf(" %c", &choice);
    }

    return 0;
}