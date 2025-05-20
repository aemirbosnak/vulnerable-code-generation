//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
void display_menu();
int get_choice();
float get_temperature();

int main() {
    // Introduction message
    printf("Welcome to the Temperature Converter!\n");
    
    int choice;
    float temperature, converted_temperature;

    while (1) {
        display_menu();
        choice = get_choice();

        // Exit condition
        if (choice == 3) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }
        
        // Getting temperature to convert
        temperature = get_temperature();

        // Converting temperature based on user's choice
        if (choice == 1) {
            converted_temperature = celsius_to_fahrenheit(temperature);
            printf("%.2f °C is equal to %.2f °F\n", temperature, converted_temperature);
        } else if (choice == 2) {
            converted_temperature = fahrenheit_to_celsius(temperature);
            printf("%.2f °F is equal to %.2f °C\n", temperature, converted_temperature);
        }
    }

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

// Function to display the menu
void display_menu() {
    printf("\nChoose a conversion option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to get user's choice
int get_choice() {
    int choice;
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    return choice;
}

// Function to get temperature input from the user
float get_temperature() {
    float temp;
    printf("Enter the temperature to convert: ");
    scanf("%f", &temp);
    return temp;
}