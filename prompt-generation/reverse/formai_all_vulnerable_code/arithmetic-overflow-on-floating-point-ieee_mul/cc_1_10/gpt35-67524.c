//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Artistic C Unit Converter
 * This program converts various units of measurement to each other.
 * It is designed to be intuitive, user-friendly, and aesthetically pleasing.
 * The program supports the conversion of:
 * - Kilometers to Miles
 * - Celsius to Fahrenheit
 * - Pounds to Kilograms
 * - Feet to Meters
 * - Gallons to Liters
 */

//Function prototypes
void menu();
float km_to_miles(float km);
float c_to_f(float c);
float lbs_to_kgs(float lbs);
float feet_to_meters(float feet);
float gallons_to_litres(float gallons);

int main()
{
    int choice;
    float input, result;

    do {
        // Display menu
        menu();

        // Get user choice
        printf("Enter your choice from 1 to 5 (0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Thanks for using Artistic Unit Converter. Goodbye!\n");
                break;
            case 1:
                printf("Enter kilometers: ");
                scanf("%f", &input);
                result = km_to_miles(input);
                printf("%.2f kilometers is equivalent to %.2f miles\n", input, result);
                break;
            case 2:
                printf("Enter degrees Celsius: ");
                scanf("%f", &input);
                result = c_to_f(input);
                printf("%.2f degrees Celsius is equivalent to %.2f degrees Fahrenheit\n", input, result);
                break;
            case 3:
                printf("Enter pounds: ");
                scanf("%f", &input);
                result = lbs_to_kgs(input);
                printf("%.2f pounds is equivalent to %.2f kilograms\n", input, result);
                break;
            case 4:
                printf("Enter feet: ");
                scanf("%f", &input);
                result = feet_to_meters(input);
                printf("%.2f feet is equivalent to %.2f meters\n", input, result);
                break;
            case 5:
                printf("Enter gallons: ");
                scanf("%f", &input);
                result = gallons_to_litres(input);
                printf("%.2f gallons is equivalent to %.2f liters\n", input, result);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

/**
 * Displays the main menu for the program.
 */
void menu() {
    printf("\n");
    printf("=============================================================\n");
    printf("|              Welcome to Artistic Unit Converter            |\n");
    printf("|                                                           |\n");
    printf("|   Please choose from the following options:               |\n");
    printf("|                                                           |\n");
    printf("|   1. Convert Kilometers to Miles                          |\n");
    printf("|   2. Convert Celsius to Fahrenheit                        |\n");
    printf("|   3. Convert Pounds to Kilograms                          |\n");
    printf("|   4. Convert Feet to Meters                               |\n");
    printf("|   5. Convert Gallons to Liters                             |\n");
    printf("|                                                           |\n");
    printf("|   0. Exit Artistic Unit Converter                         |\n");
    printf("=============================================================\n");
}

/**
 * Converts kilometers to miles.
 */
float km_to_miles(float km) {
    return km * 0.6213712;
}

/**
 * Converts Celsius to Fahrenheit.
 */
float c_to_f(float c) {
    return (c * 9/5) + 32;
}

/**
 * Converts pounds to kilograms.
 */
float lbs_to_kgs(float lbs) {
    return lbs * 0.45359237;
}

/**
 * Converts feet to meters.
 */
float feet_to_meters(float feet) {
    return feet * 0.3048;
}

/**
 * Converts gallons to liters.
 */
float gallons_to_litres(float gallons) {
    return gallons * 3.78541;
}