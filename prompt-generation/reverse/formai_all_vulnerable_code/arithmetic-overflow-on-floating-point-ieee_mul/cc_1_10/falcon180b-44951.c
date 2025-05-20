//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float temperature, converted_temperature;
    int choice;

    // Display menu
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    // Get input temperature
    printf("Enter temperature: ");
    scanf("%f", &temperature);

    // Convert temperature
    switch(choice) {
        case 1: // Celsius to Fahrenheit
            converted_temperature = (temperature * 9/5) + 32;
            printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, converted_temperature);
            break;
        case 2: // Fahrenheit to Celsius
            converted_temperature = (temperature - 32) * 5/9;
            printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, converted_temperature);
            break;
        case 3: // Kelvin to Celsius
            converted_temperature = temperature - 273.15;
            printf("%.2f Kelvin is %.2f Celsius\n", temperature, converted_temperature);
            break;
        case 4: // Celsius to Kelvin
            converted_temperature = temperature + 273.15;
            printf("%.2f Celsius is %.2f Kelvin\n", temperature, converted_temperature);
            break;
        case 5: // Exit
            printf("Exiting program...\n");
            exit(0);
        default: // Invalid choice
            printf("Invalid choice. Exiting program...\n");
            exit(0);
    }

    return 0;
}