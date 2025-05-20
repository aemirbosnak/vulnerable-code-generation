//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256

int main() {
    char line[MAX_LINE_LEN];
    char *input;
    int choice;
    double temperature, result;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter your choice:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("5. Kelvin to Fahrenheit\n");
    printf("6. Fahrenheit to Kelvin\n");
    scanf("%d", &choice);

    printf("Please enter the temperature: ");
    fgets(line, MAX_LINE_LEN, stdin);
    input = strtok(line, "\n");

    switch (choice) {
        case 1: // Celsius to Fahrenheit
            temperature = atof(input);
            result = (temperature * 9.0 / 5.0) + 32.0;
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temperature, result);
            break;
        case 2: // Fahrenheit to Celsius
            temperature = atof(input);
            result = (temperature - 32.0) * 5.0 / 9.0;
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temperature, result);
            break;
        case 3: // Kelvin to Celsius
            temperature = atof(input);
            result = temperature - 273.15;
            printf("%.2f Kelvin is %.2f degrees Celsius.\n", temperature, result);
            break;
        case 4: // Celsius to Kelvin
            temperature = atof(input);
            result = temperature + 273.15;
            printf("%.2f degrees Celsius is %.2f Kelvin.\n", temperature, result);
            break;
        case 5: // Kelvin to Fahrenheit
            temperature = atof(input);
            result = (temperature * 9.0 / 5.0) - 459.67;
            printf("%.2f Kelvin is %.2f degrees Fahrenheit.\n", temperature, result);
            break;
        case 6: // Fahrenheit to Kelvin
            temperature = atof(input);
            result = (temperature + 459.67) * 5.0 / 9.0;
            printf("%.2f degrees Fahrenheit is %.2f Kelvin.\n", temperature, result);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}