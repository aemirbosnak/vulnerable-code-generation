//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {

    // Define variables
    char choice;
    float temperature, converted_temperature;

    // Initialize variables
    temperature = 0;
    converted_temperature = 0;

    // Welcome message
    printf("Welcome to the Temperature Converter 3000!\n");

    // Main loop
    do {

        // Clear screen
        system("clear");

        // Print instructions
        printf("Please select a temperature unit:\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");
        printf("4. Rankine\n");
        printf("5. Quit\n");

        // Get user choice
        scanf("%c", &choice);

        // Convert temperature
        switch(choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                converted_temperature = (temperature * 9/5) + 32;
                printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temperature, converted_temperature);
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted_temperature = (temperature - 32) * 5/9;
                printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temperature, converted_temperature);
                break;
            case '3':
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                converted_temperature = temperature - 273.15;
                printf("%.2f Kelvin is %.2f degrees Celsius.\n", temperature, converted_temperature);
                break;
            case '4':
                printf("Enter temperature in Rankine: ");
                scanf("%f", &temperature);
                converted_temperature = temperature - 459.67;
                printf("%.2f Rankine is %.2f degrees Celsius.\n", temperature, converted_temperature);
                break;
            case '5':
                printf("Thank you for using the Temperature Converter 3000!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= '5');

    return 0;
}