//FormAI DATASET v1.0 Category: Temperature Converter ; Style: visionary
// This program is a C Temperature Converter that is designed to convert temperature measurements between Celsius (°C), Fahrenheit (°F) and Kelvin (K).

#include <stdio.h>
#include <stdlib.h>

int main() {
    float celsius = 0, fahrenheit = 0, kelvin = 0; // Initializing variables
    int choice; // Initializing variable for menu choice

    printf("Welcome to C Temperature Converter!\n");

    while (1) // Infinite loop for menu
    {
        printf("\nChoose an option:\n");
        printf("1. Celsius to Fahrenheit and Kelvin\n");
        printf("2. Fahrenheit to Celsius and Kelvin\n");
        printf("3. Kelvin to Celsius and Fahrenheit\n");
        printf("4. Exit\n");

        scanf("%d", &choice); // Reading menu choice

        switch (choice)
        {
        case 1: // Celsius to Fahrenheit and Kelvin conversion
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9 / 5) + 32; // Formula for Fahrenheit
            kelvin = celsius + 273.15; // Formula for Kelvin
            printf("%.2f°C is %.2f°F and %.2fK.\n", celsius, fahrenheit, kelvin);
            break;

        case 2: // Fahrenheit to Celsius and Kelvin conversion
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5 / 9; // Formula for Celsius
            kelvin = (fahrenheit + 459.67) * 5 / 9; // Formula for Kelvin
            printf("%.2f°F is %.2f°C and %.2fK.\n", fahrenheit, celsius, kelvin);
            break;

        case 3: // Kelvin to Celsius and Fahrenheit conversion
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &kelvin);
            celsius = kelvin - 273.15; // Formula for Celsius
            fahrenheit = (kelvin * 9 / 5) - 459.67; // Formula for Fahrenheit
            printf("%.2fK is %.2f°C and %.2f°F.\n", kelvin, celsius, fahrenheit);
            break;

        case 4: // Exit the program
            printf("Thank you for using C Temperature Converter. Goodbye!");
            exit(0);

        default: // Error handling for invalid menu choice
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
    return 0;
}