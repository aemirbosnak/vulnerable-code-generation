//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the temperature conversion formulas
#define C_TO_F(c) ((c * 9.0 / 5) + 32)
#define F_TO_C(f) ((f - 32) * 5.0 / 9)

// Define the main function
int main(void) {
    int choice;
    double temperature;

    // Print the menu
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the temperature conversion based on the user's choice
    switch (choice) {
        case 1:
            // Celsius to Fahrenheit
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, C_TO_F(temperature));
            break;
        case 2:
            // Fahrenheit to Celsius
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, F_TO_C(temperature));
            break;
        case 3:
            // Exit the program
            printf("Exiting...\n");
            break;
        default:
            // Invalid choice
            printf("Invalid choice. Please try again.\n");
            break;
    }

    // Return 0 to indicate successful termination
    return 0;
}