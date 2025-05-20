//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ada Lovelace
/*
 * A temperature conversion program in Ada Lovelace style
 * by [Your Name]
 */

// Importing necessary header files
#include <stdio.h>

// Main function
int main(void) {
    // Initializing necessary variables
    int choice;
    float temperature, converted_temperature;

    // Printing a warm welcome message
    printf("Welcome to the Temperature Converter!\n");

    // Printing a menu for temperature conversion options
    printf("\nPlease select a conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    // Reading the user's option choice
    printf("\nYour choice: ");
    scanf("%d", &choice);

    // Handling the user's input, converting temperature accordingly, and printing results
    switch(choice) {
        case 1:
            // Reading the temperature in Celsius
            printf("\nEnter temperature in Celsius: ");
            scanf("%f", &temperature);

            // Converting Celsius to Fahrenheit
            converted_temperature = (temperature * 9/5) + 32;

            // Printing the converted temperature in Fahrenheit
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, converted_temperature);
            break;

        case 2:
            // Reading the temperature in Fahrenheit
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%f", &temperature);

            // Converting Fahrenheit to Celsius
            converted_temperature = (temperature - 32) * 5/9;

            // Printing the converted temperature in Celsius
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, converted_temperature);
            break;

        default:
            // Printing an error message for invalid option choice
            printf("\nInvalid option choice. Please try again.\n");
            break;
    }

    // A farewell message to thank the user for using the program
    printf("\nThank you for using the Temperature Converter!\n");

    // End of program
    return 0;
}