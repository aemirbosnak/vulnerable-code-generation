//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to display the menu
void display_menu() {
    printf("Welcome to the Temperature Converter\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Please enter your choice: ");
}

// Function to handle the conversion process
void convert_temperature() {
    int choice;
    float temperature, converted_temp;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                converted_temp = celsius_to_fahrenheit(temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, converted_temp);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted_temp = fahrenheit_to_celsius(temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, converted_temp);
                break;
            case 3:
                printf("Thank you for using the Temperature Converter. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n"); // Add a newline for better readability
    }
}

// Main function
int main() {
    convert_temperature();
    return 0;
}