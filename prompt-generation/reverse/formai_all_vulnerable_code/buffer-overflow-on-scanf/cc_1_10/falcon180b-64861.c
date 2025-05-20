//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input[100];
    char *endptr;
    double temperature, converted;
    int choice;

    // Prompt user to enter temperature and unit
    printf("Enter temperature in degrees (C/F): ");
    scanf("%s", input);

    // Validate input
    if (strlen(input) <= 2 ||!isdigit(input[0]) ||!isdigit(input[1])) {
        printf("Invalid input. Please enter a valid temperature in degrees.\n");
        return 1;
    }

    // Convert input to double
    temperature = strtod(input, &endptr);

    // Validate input
    if (endptr == input || *endptr!= '\0') {
        printf("Invalid input. Please enter a valid temperature in degrees.\n");
        return 1;
    }

    // Prompt user to choose unit of conversion
    printf("Choose unit of conversion:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    // Convert temperature
    switch (choice) {
        case 1:
            // Celsius to Fahrenheit
            converted = (temperature * 9.0 / 5.0) + 32.0;
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temperature, converted);
            break;
        case 2:
            // Fahrenheit to Celsius
            converted = (temperature - 32.0) * 5.0 / 9.0;
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temperature, converted);
            break;
        default:
            // Invalid choice
            printf("Invalid choice. Please enter 1 or 2.\n");
            return 1;
    }

    return 0;
}