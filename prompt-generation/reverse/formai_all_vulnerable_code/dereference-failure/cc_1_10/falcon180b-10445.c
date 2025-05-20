//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 100

struct unit {
    char name[20];
    double factor;
};

struct unit units[] = {
    {"Celsius", 1},
    {"Fahrenheit", 1.8},
    {"Kelvin", 1}
};

int main() {
    char input[SIZE];
    char choice;
    int i;
    double num, result;
    struct unit *unit;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a temperature value: ");
    fgets(input, SIZE, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    // Check if input is a number
    for (i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            printf("Invalid input. Please enter a numeric value.\n");
            return 0;
        }
    }

    // Convert input to number
    num = atof(input);

    // Ask user for desired unit of measurement
    printf("Please enter the unit you want to convert to (Celsius, Fahrenheit, or Kelvin): ");
    scanf("%c", &choice);

    // Find corresponding unit in array
    for (i = 0; i < sizeof(units)/sizeof(units[0]); i++) {
        if (strcmp(choice, units[i].name) == 0) {
            unit = &units[i];
            break;
        }
    }

    // Convert temperature to desired unit
    result = num * unit->factor;

    // Display result
    printf("%.2f %s is equal to %.2f %s.\n", num, units[0].name, result, unit->name);

    return 0;
}