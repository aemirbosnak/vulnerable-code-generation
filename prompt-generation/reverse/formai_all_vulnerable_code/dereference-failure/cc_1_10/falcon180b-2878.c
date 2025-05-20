//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_SIZE 80
#define MAX_TOKENS 10

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to split input string into tokens
char** split_input(char* input) {
    int num_tokens = 0;
    char* token = strtok(input, " ");
    while (token!= NULL) {
        num_tokens++;
        token = strtok(NULL, " ");
    }
    char** tokens = malloc(sizeof(char*) * num_tokens);
    int i = 0;
    token = strtok(input, " ");
    while (token!= NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, " ");
    }
    return tokens;
}

// Function to convert temperature
double convert_temperature(double temperature, char unit) {
    double result = 0;
    switch (unit) {
        case 'C':
        case 'c':
            result = celsius_to_fahrenheit(temperature);
            break;
        case 'F':
        case 'f':
            result = fahrenheit_to_celsius(temperature);
            break;
        default:
            printf("Invalid temperature unit.\n");
            exit(1);
    }
    return result;
}

// Function to print usage instructions
void print_usage() {
    printf("Usage:./temperature_converter [temperature] [unit]\n");
    printf("Where:\n");
    printf("  [temperature] is the temperature value to convert\n");
    printf("  [unit] is the unit of the temperature value (C for Celsius, F for Fahrenheit)\n");
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        print_usage();
        exit(1);
    }
    double temperature = atof(argv[1]);
    char unit = argv[2][0];
    double converted_temperature = convert_temperature(temperature, unit);
    printf("%.2f %c = %.2f %c\n", temperature, unit, converted_temperature, (unit == 'C' || unit == 'c')? 'F' : 'C');
    return 0;
}