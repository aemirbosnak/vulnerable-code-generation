//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Brave Temperature Converter

int main() {
    // Declare variables
    char input[10];
    float temperature;
    int choice;

    // Welcome the user
    printf("\nBrave Temperature Converter\n");
    printf("--------------------------\n");

    // Get the user's input
    printf("Enter the temperature (in Fahrenheit or Celsius): ");
    scanf("%s", input);

    // Check if the user entered a valid temperature
    if (!strcmp(input, "exit")) {
        printf("Exiting the program...\n");
        return 0;
    } else if (!strcmp(input, "help")) {
        printf("Usage: ./temperature-converter [options]\n");
        printf("Options:\n");
        printf("    -c: Convert Fahrenheit to Celsius\n");
        printf("    -f: Convert Celsius to Fahrenheit\n");
        printf("    -h: Display this help message\n");
        return 0;
    } else {
        temperature = atof(input);
    }

    // Get the user's choice of conversion
    printf("Enter the conversion type (1 for Fahrenheit to Celsius, 2 for Celsius to Fahrenheit): ");
    scanf("%d", &choice);

    // Convert the temperature
    switch (choice) {
        case 1:
            temperature = (temperature - 32) * 5 / 9;
            printf("The converted temperature is %.2f Celsius.\n", temperature);
            break;
        case 2:
            temperature = (temperature * 9 / 5) + 32;
            printf("The converted temperature is %.2f Fahrenheit.\n", temperature);
            break;
        default:
            printf("Invalid choice. Enter 1 for Fahrenheit to Celsius or 2 for Celsius to Fahrenheit.\n");
            break;
    }

    // Thank the user
    printf("Thank you for using the Brave Temperature Converter!\n");

    return 0;
}