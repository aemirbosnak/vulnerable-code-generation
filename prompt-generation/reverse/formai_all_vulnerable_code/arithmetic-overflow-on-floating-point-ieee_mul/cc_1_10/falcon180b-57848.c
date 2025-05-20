//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    // Variables declaration
    char input[50];
    int choice;
    float temperature, converted;

    // Program introduction
    printf("Welcome to the Temperature Converter!\n\n");

    // User input for temperature and unit of measurement
    printf("Enter a temperature followed by its unit of measurement (e.g. 20 C): ");
    scanf("%s %c", input, &input[strcspn(input, " C F K")]);

    // User input for conversion choice
    printf("Enter 1 to convert from Celsius to Fahrenheit, 2 to convert from Celsius to Kelvin, 3 to convert from Fahrenheit to Celsius, 4 to convert from Fahrenheit to Kelvin, 5 to convert from Kelvin to Celsius, or 6 to convert from Kelvin to Fahrenheit: ");
    scanf("%d", &choice);

    // Conversion based on user input
    switch (choice) {
        case 1: // Celsius to Fahrenheit
            temperature = atof(input) * 9/5 + 32;
            converted = temperature;
            printf("%.2f C is equal to %.2f F.\n", temperature, converted);
            break;
        case 2: // Celsius to Kelvin
            temperature = atof(input) + 273.15;
            converted = temperature;
            printf("%.2f C is equal to %.2f K.\n", temperature, converted);
            break;
        case 3: // Fahrenheit to Celsius
            temperature = (atof(input) - 32) * 5/9;
            converted = temperature;
            printf("%.2f F is equal to %.2f C.\n", temperature, converted);
            break;
        case 4: // Fahrenheit to Kelvin
            temperature = (atof(input) + 459.67) * 5/9;
            converted = temperature;
            printf("%.2f F is equal to %.2f K.\n", temperature, converted);
            break;
        case 5: // Kelvin to Celsius
            temperature = atof(input) - 273.15;
            converted = temperature;
            printf("%.2f K is equal to %.2f C.\n", temperature, converted);
            break;
        case 6: // Kelvin to Fahrenheit
            temperature = (atof(input) * 9/5) - 459.67;
            converted = temperature;
            printf("%.2f K is equal to %.2f F.\n", temperature, converted);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}