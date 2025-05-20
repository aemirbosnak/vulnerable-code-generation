//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_TOKEN_LENGTH 20

// Function prototypes
int is_valid_temperature_unit(char *unit);
int is_valid_number(char *str);
double string_to_double(char *str);

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char token_buffer[MAX_TOKEN_LENGTH];
    char *token;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please enter a temperature value and its unit (e.g. 25 C or 77 F)\n");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    // Remove the newline character from the end of the input buffer
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    // Tokenize the input buffer
    token = strtok(input_buffer, " ");
    strcpy(token_buffer, token);

    if (!is_valid_temperature_unit(token_buffer)) {
        printf("Invalid temperature unit.\n");
        return 1;
    }

    token = strtok(NULL, " ");
    if (!is_valid_number(token)) {
        printf("Invalid temperature value.\n");
        return 1;
    }

    double temperature = string_to_double(token);
    double result;

    if (strcmp(token_buffer, "C") == 0) {
        result = (temperature * 9.0 / 5.0) + 32.0;
        printf("%.2f C = %.2f F\n", temperature, result);
    } else if (strcmp(token_buffer, "F") == 0) {
        result = (temperature - 32.0) * 5.0 / 9.0;
        printf("%.2f F = %.2f C\n", temperature, result);
    } else {
        printf("Invalid temperature unit.\n");
        return 1;
    }

    return 0;
}

// Function to check if a string represents a valid temperature unit
int is_valid_temperature_unit(char *unit) {
    if (strcmp(unit, "C") == 0 || strcmp(unit, "F") == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a string represents a valid number
int is_valid_number(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i]) && str[i]!= '.') {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string to a double
double string_to_double(char *str) {
    return atof(str);
}