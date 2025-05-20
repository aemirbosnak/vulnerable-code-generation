//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to print a menu of options
void print_menu() {
    printf("\nTemperature Converter\n");
    printf("---------------------\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}

// Function to get the user's input
int get_input() {
    int input;
    scanf("%d", &input);
    return input;
}

// Function to get the temperature value
double get_temperature() {
    double temperature;
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);
    return temperature;
}

// Function to display the result
void display_result(double result) {
    printf("The converted temperature is: %.2f\n", result);
}

// Function to run the program
void run_program() {
    int choice;
    double temperature;
    double result;

    // Loop until the user quits
    while (1) {
        // Print the menu
        print_menu();

        // Get the user's input
        choice = get_input();

        // Convert the temperature based on the user's choice
        switch (choice) {
            case 1:
                temperature = get_temperature();
                result = celsius_to_fahrenheit(temperature);
                display_result(result);
                break;
            case 2:
                temperature = get_temperature();
                result = fahrenheit_to_celsius(temperature);
                display_result(result);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    }
}

int main() {
    // Run the program
    run_program();

    return 0;
}