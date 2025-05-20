//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
#include <stdio.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
void display_conversion_options();
void get_temperature_input(float *temperature);

int main() {
    int choice;
    float temperature;

    // Displaying the options for conversion
    display_conversion_options();

    // Getting user choice
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Getting the temperature based on user choice
    get_temperature_input(&temperature);

    // Performing the conversion based on user choice
    if (choice == 1) {
        float fahrenheit = celsius_to_fahrenheit(temperature);
        printf("%.2f °C is equivalent to %.2f °F\n", temperature, fahrenheit);
    } else if (choice == 2) {
        float celsius = fahrenheit_to_celsius(temperature);
        printf("%.2f °F is equivalent to %.2f °C\n", temperature, celsius);
    } else {
        printf("Invalid choice! Please run the program again and select either 1 or 2.\n");
    }
    
    return 0;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to display conversion options
void display_conversion_options() {
    printf("Temperature Converter\n");
    printf("---------------------\n");
    printf("1: Convert Celsius to Fahrenheit\n");
    printf("2: Convert Fahrenheit to Celsius\n");
    printf("---------------------\n");
}

// Function to get temperature input from the user
void get_temperature_input(float *temperature) {
    printf("Enter the temperature you wish to convert: ");
    scanf("%f", temperature);
}

// A delightful touch: adding a farewell message
void farewell_message() {
    printf("Thank you for using the Temperature Converter! Stay warm and cool!\n");
}