//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main() {
    int choice;
    float temperature, converted;

    // Display menu options
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("5. Exit\n");

    // Get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Validate user choice
    while (choice < 1 || choice > 5) {
        printf("Invalid choice. Please enter a valid choice: ");
        scanf("%d", &choice);
    }

    // Convert temperature
    switch (choice) {
        case 1: // Celsius to Fahrenheit
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            converted = (temperature * 9 / 5) + 32;
            printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, converted);
            break;
        case 2: // Fahrenheit to Celsius
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            converted = (temperature - 32) * 5 / 9;
            printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, converted);
            break;
        case 3: // Kelvin to Celsius
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &temperature);
            converted = temperature - 273.15;
            printf("%.2f Kelvin is %.2f Celsius\n", temperature, converted);
            break;
        case 4: // Celsius to Kelvin
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            converted = temperature + 273.15;
            printf("%.2f Celsius is %.2f Kelvin\n", temperature, converted);
            break;
        case 5: // Exit
            printf("Exiting program...\n");
            break;
        default: // Invalid choice
            printf("Invalid choice. Please enter a valid choice.\n");
            break;
    }

    return 0;
}