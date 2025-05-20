//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char input_unit[10];
    double input_temp, output_temp;
    char output_unit[10];
    int choice;

    // Prompt user for input temperature and unit
    printf("Enter temperature in Celsius, Fahrenheit, or Kelvin: ");
    scanf("%lf %s", &input_temp, input_unit);

    // Convert input unit to uppercase
    for (int i = 0; i < strlen(input_unit); i++) {
        input_unit[i] = toupper(input_unit[i]);
    }

    // Prompt user for output unit
    printf("Enter output unit (Celsius, Fahrenheit, or Kelvin): ");
    scanf("%s", output_unit);

    // Convert output unit to uppercase
    for (int i = 0; i < strlen(output_unit); i++) {
        output_unit[i] = toupper(output_unit[i]);
    }

    // Convert input temperature to Celsius
    if (strcmp(input_unit, "F") == 0) {
        input_temp = (input_temp - 32) * 5/9;
    } else if (strcmp(input_unit, "K") == 0) {
        input_temp = input_temp - 273.15;
    }

    // Convert input temperature to Fahrenheit
    if (strcmp(output_unit, "C") == 0) {
        output_temp = (input_temp * 9/5) + 32;
    } else if (strcmp(output_unit, "K") == 0) {
        output_temp = input_temp + 273.15;
    }

    // Convert input temperature to Kelvin
    if (strcmp(input_unit, "C") == 0) {
        input_temp = input_temp + 273.15;
    } else if (strcmp(input_unit, "F") == 0) {
        input_temp = (input_temp * 5/9) + 273.15;
    }

    // Convert output temperature to Celsius
    if (strcmp(output_unit, "F") == 0) {
        output_temp = (output_temp - 32) * 5/9;
    } else if (strcmp(output_unit, "K") == 0) {
        output_temp = output_temp - 273.15;
    }

    // Convert output temperature to Fahrenheit
    if (strcmp(input_unit, "F") == 0) {
        output_temp = (output_temp * 9/5) + 32;
    } else if (strcmp(input_unit, "K") == 0) {
        output_temp = output_temp + 273.15;
    }

    // Convert output temperature to Kelvin
    if (strcmp(output_unit, "C") == 0) {
        output_temp = output_temp + 273.15;
    } else if (strcmp(output_unit, "F") == 0) {
        output_temp = (output_temp * 5/9) + 273.15;
    }

    // Display result
    printf("%.2lf %s = %.2lf %s\n", input_temp, input_unit, output_temp, output_unit);

    return 0;
}