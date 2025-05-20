//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to print the menu
void print_menu() {
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Quit\n");
}

// Function to get the user's choice
int get_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get the temperature
float get_temperature() {
    float temperature;
    printf("Enter the temperature: ");
    scanf("%f", &temperature);
    return temperature;
}

// Function to convert the temperature
void convert_temperature(int choice, float temperature) {
    switch (choice) {
        case 1:
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        default:
            printf("Invalid choice\n");
    }
}

// Main function
int main() {
    int choice;
    float temperature;

    // Print the menu
    print_menu();

    // Get the user's choice
    choice = get_choice();

    // Get the temperature
    temperature = get_temperature();

    // Convert the temperature
    convert_temperature(choice, temperature);

    return 0;
}