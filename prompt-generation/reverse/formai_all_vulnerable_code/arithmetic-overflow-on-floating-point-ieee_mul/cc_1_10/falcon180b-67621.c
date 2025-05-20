//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_ARGUMENTS 100

int main(int argc, char *argv[]) {
    char input_buffer[MAX_LINE_LENGTH];
    char *arguments[MAX_NUM_ARGUMENTS];
    int num_arguments;
    double temperature;
    char input_unit[MAX_LINE_LENGTH];
    char output_unit[MAX_LINE_LENGTH];
    int unit_conversion;
    int input_unit_index;
    int output_unit_index;
    int i;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a temperature value and its unit of measurement, followed by the desired output unit:\n");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    // Parse input arguments
    num_arguments = 0;
    arguments[num_arguments] = strtok(input_buffer, " ");
    while (arguments[num_arguments]!= NULL && num_arguments < MAX_NUM_ARGUMENTS) {
        num_arguments++;
        arguments[num_arguments] = strtok(NULL, " ");
    }

    // Check if input arguments are valid
    if (num_arguments < 3) {
        printf("Error: Invalid input. Please enter a temperature value, its unit of measurement, and the desired output unit.\n");
        return 1;
    }

    // Convert input temperature to Celsius
    temperature = atof(arguments[1]);
    if (tolower(arguments[2]) == 'f') {
        temperature -= 32;
        temperature *= 5.0/9.0;
    }

    // Convert output temperature to Celsius
    if (tolower(arguments[3]) == 'f') {
        output_unit_index = 0;
        input_unit_index = 1;
    } else {
        output_unit_index = 1;
        input_unit_index = 0;
    }

    // Convert temperature to desired output unit
    if (tolower(arguments[3]) == 'c') {
        unit_conversion = 1;
    } else if (tolower(arguments[3]) == 'f') {
        unit_conversion = 9.0/5.0;
    } else {
        printf("Error: Invalid output unit. Please enter 'C' or 'F'.\n");
        return 1;
    }

    temperature *= unit_conversion;

    // Round temperature to two decimal places
    temperature = round(temperature * 100) / 100;

    // Print result
    printf("%.2f %s is %.2f %s.\n", temperature, output_unit, temperature, input_unit);

    return 0;
}