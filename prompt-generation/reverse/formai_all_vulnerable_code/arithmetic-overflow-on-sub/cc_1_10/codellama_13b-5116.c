//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: safe
// Temperature Converter Example Program in a Safe Style
#include <stdio.h>

// Struct for temperature in different scales
typedef struct {
    int celsius;
    int fahrenheit;
    int kelvin;
} temperature;

// Function to convert temperature from Celsius to Fahrenheit
void convert_celsius_to_fahrenheit(temperature *temp) {
    temp->fahrenheit = (temp->celsius * 1.8) + 32;
}

// Function to convert temperature from Celsius to Kelvin
void convert_celsius_to_kelvin(temperature *temp) {
    temp->kelvin = temp->celsius + 273;
}

// Function to convert temperature from Fahrenheit to Celsius
void convert_fahrenheit_to_celsius(temperature *temp) {
    temp->celsius = (temp->fahrenheit - 32) / 1.8;
}

// Function to convert temperature from Fahrenheit to Kelvin
void convert_fahrenheit_to_kelvin(temperature *temp) {
    temp->kelvin = (temp->fahrenheit + 459.67) * 5 / 9;
}

// Function to convert temperature from Kelvin to Celsius
void convert_kelvin_to_celsius(temperature *temp) {
    temp->celsius = temp->kelvin - 273;
}

// Function to convert temperature from Kelvin to Fahrenheit
void convert_kelvin_to_fahrenheit(temperature *temp) {
    temp->fahrenheit = temp->kelvin * 9 / 5 - 459.67;
}

int main() {
    temperature temp;
    int choice;

    // Get temperature from user
    printf("Enter temperature in Celsius: ");
    scanf("%d", &temp.celsius);

    // Get conversion type from user
    printf("Enter conversion type (1 for Celsius to Fahrenheit, 2 for Celsius to Kelvin, 3 for Fahrenheit to Celsius, 4 for Fahrenheit to Kelvin, 5 for Kelvin to Celsius, or 6 for Kelvin to Fahrenheit): ");
    scanf("%d", &choice);

    // Convert temperature based on choice
    switch (choice) {
        case 1:
            convert_celsius_to_fahrenheit(&temp);
            break;
        case 2:
            convert_celsius_to_kelvin(&temp);
            break;
        case 3:
            convert_fahrenheit_to_celsius(&temp);
            break;
        case 4:
            convert_fahrenheit_to_kelvin(&temp);
            break;
        case 5:
            convert_kelvin_to_celsius(&temp);
            break;
        case 6:
            convert_kelvin_to_fahrenheit(&temp);
            break;
        default:
            printf("Invalid conversion type\n");
            return 1;
    }

    // Print converted temperature
    printf("Temperature in %s: %d\n", (choice == 1 || choice == 3) ? "Fahrenheit" : "Kelvin", (choice == 1 || choice == 3) ? temp.fahrenheit : temp.kelvin);

    return 0;
}