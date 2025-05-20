//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>

// Declare the function prototypes
void print_usage(void);
double convert_to_fahrenheit(double celsius);
double convert_to_celsius(double fahrenheit);

int main(void) {
    // Declare the variables
    char input[100];
    double temperature;
    int choice;

    // Print the welcome message
    printf("Welcome to the Temperature Converter!\n");

    // Get the user's choice
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        // Validate the user's choice
        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
            continue;
        }

        // Get the temperature
        printf("Enter the temperature to convert:\n");
        scanf("%lf", &temperature);

        // Convert the temperature
        if (choice == 1) {
            temperature = convert_to_fahrenheit(temperature);
        } else if (choice == 2) {
            temperature = convert_to_celsius(temperature);
        }

        // Print the converted temperature
        printf("The converted temperature is: %.2f\n", temperature);

        // Check if the user wants to quit
        if (choice == 3) {
            break;
        }
    }

    // Print the goodbye message
    printf("Goodbye!\n");

    return 0;
}

// Define the function to print the usage
void print_usage(void) {
    printf("Usage:\n");
    printf("temperature_converter [options] [arguments]\n");
    printf("\nOptions:\n");
    printf("-h, --help\t\tPrint this help message and exit\n");
    printf("-c, --celsius\t\tConvert Fahrenheit to Celsius\n");
    printf("-f, --fahrenheit\tConvert Celsius to Fahrenheit\n");
    printf("\nArguments:\n");
    printf("temperature\t\tThe temperature to convert\n");
}

// Define the function to convert Celsius to Fahrenheit
double convert_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Define the function to convert Fahrenheit to Celsius
double convert_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}