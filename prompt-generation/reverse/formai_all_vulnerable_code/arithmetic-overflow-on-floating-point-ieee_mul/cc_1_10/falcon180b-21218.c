//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 100

int main() {
    char input_line[MAX_LINE_LENGTH];
    char *token;
    double temperature;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a temperature value followed by the unit of measurement (C, F or K):\n");

    // Read input line
    if (fgets(input_line, MAX_LINE_LENGTH, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character from input
    input_line[strcspn(input_line, "\n")] = '\0';

    // Tokenize input line
    token = strtok(input_line, " ");
    if (token == NULL) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert temperature value to double
    temperature = strtod(token, NULL);

    // Get unit of measurement
    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert unit of measurement to uppercase
    for (int i = 0; i < strlen(token); i++) {
        token[i] = toupper(token[i]);
    }

    // Convert temperature to Celsius
    if (strcmp(token, "C") == 0) {
        printf("%.2f C = %.2f K\n", temperature, temperature + 273.15);
    }
    // Convert temperature to Fahrenheit
    else if (strcmp(token, "F") == 0) {
        printf("%.2f F = %.2f C\n", temperature, (temperature - 32) * 5.0 / 9.0);
    }
    // Convert temperature to Kelvin
    else if (strcmp(token, "K") == 0) {
        printf("%.2f K = %.2f C\n", temperature, temperature - 273.15);
    }
    // Invalid unit of measurement
    else {
        printf("Invalid unit of measurement.\n");
    }

    return 0;
}