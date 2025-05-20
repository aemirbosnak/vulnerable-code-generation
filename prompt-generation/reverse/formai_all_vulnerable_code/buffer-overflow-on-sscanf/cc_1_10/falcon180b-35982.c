//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char unit[MAX_LENGTH];
    double temperature;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a temperature followed by its unit (e.g. 20 C): ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Extract temperature value and unit
    sscanf(input, "%lf %s", &temperature, unit);

    // Convert temperature to Celsius
    temperature -= 32;
    temperature *= 5.0 / 9.0;

    // Convert temperature to Fahrenheit
    temperature *= 9.0 / 5.0;
    temperature += 32;

    // Convert temperature to Kelvin
    temperature += 273.15;

    printf("The temperature %.2lf %s is:\n", temperature, unit);
    printf("%.2lf C\n", temperature);
    printf("%.2lf F\n", temperature);
    printf("%.2lf K\n", temperature);

    printf("\nDo you want to convert another temperature? (y/n): ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Check if user wants to convert another temperature
    if (tolower(input[0]) == 'y') {
        main();
    } else {
        printf("Thank you for using the Temperature Converter!\n");
        return 0;
    }
}