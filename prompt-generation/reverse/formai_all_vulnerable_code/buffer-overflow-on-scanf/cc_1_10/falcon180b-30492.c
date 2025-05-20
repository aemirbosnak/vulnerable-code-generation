//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main() {
    char input[100];
    double value;
    int choice;
    char unit[10];
    char result[50];

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter the temperature value you want to convert: ");
    scanf("%s", input);

    printf("Enter the unit of the temperature: ");
    scanf("%s", unit);

    // Convert input to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Convert input to double
    value = atof(input);

    // Convert Celsius to Fahrenheit
    if (strcmp(unit, "C") == 0) {
        value = (value * 9/5) + 32;
        strcpy(result, "F");
    }

    // Convert Fahrenheit to Celsius
    else if (strcmp(unit, "F") == 0) {
        value = (value - 32) * 5/9;
        strcpy(result, "C");
    }

    // Convert Kelvin to Celsius
    else if (strcmp(unit, "K") == 0) {
        value = value - 273.15;
        strcpy(result, "C");
    }

    // Convert Celsius to Kelvin
    else if (strcmp(unit, "C") == 0) {
        value = value + 273.15;
        strcpy(result, "K");
    }

    // Convert Fahrenheit to Kelvin
    else if (strcmp(unit, "F") == 0) {
        value = (value - 32) * 5/9 + 273.15;
        strcpy(result, "K");
    }

    // Convert Kelvin to Fahrenheit
    else if (strcmp(unit, "K") == 0) {
        value = (value * 9/5) - 459.67;
        strcpy(result, "F");
    }

    // Invalid input
    else {
        printf("Invalid input. Please enter a valid temperature unit.\n");
        return 0;
    }

    printf("The converted temperature is %.2lf %s.\n", value, result);

    return 0;
}