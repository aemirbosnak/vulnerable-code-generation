//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    char input[50];
    char unit[10];
    double temperature;
    bool valid_input = false;
    int choice;

    printf("Welcome to Temperature Converter!\n");
    printf("Please enter a temperature followed by its unit (e.g. 100 C):\n");
    scanf("%s %s", input, unit);

    // Check if input is valid
    if (isdigit(input[0])) {
        temperature = atof(input);
        valid_input = true;
    } else {
        printf("Invalid input. Please enter a valid temperature.\n");
        return 0;
    }

    // Convert temperature to Celsius
    temperature = (temperature - 32) / 9 * 5;

    // Convert temperature to Fahrenheit
    temperature = (temperature * 9 / 5) + 32;

    // Convert temperature to Kelvin
    temperature += 273.15;

    // Display converted temperatures
    printf("The temperature in Celsius is: %.2lf C\n", temperature);
    printf("The temperature in Fahrenheit is: %.2lf F\n", temperature);
    printf("The temperature in Kelvin is: %.2lf K\n", temperature);

    // Ask user if they want to convert another temperature
    printf("Do you want to convert another temperature? (Y/N):\n");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        main();
    } else {
        printf("Thank you for using Temperature Converter!\n");
        return 0;
    }

    return 0;
}