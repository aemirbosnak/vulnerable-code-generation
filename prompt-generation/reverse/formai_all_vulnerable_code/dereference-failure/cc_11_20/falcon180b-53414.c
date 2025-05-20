//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    char input_line[MAX_LINE_LENGTH];
    char *input_ptr;
    char *end_ptr;
    double celsius, fahrenheit;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter a temperature in Celsius or Fahrenheit and press Enter:\n");

    fgets(input_line, MAX_LINE_LENGTH, stdin);
    input_ptr = input_line;

    // Remove leading and trailing whitespace
    while (*input_ptr && isspace(*input_ptr)) {
        input_ptr++;
    }
    end_ptr = input_ptr + strlen(input_ptr) - 1;
    while (end_ptr > input_ptr && isspace(*end_ptr)) {
        end_ptr--;
        *end_ptr = '\0';
    }

    if (strcasecmp(input_ptr, "C") == 0) {
        celsius = strtod(input_ptr + 1, &end_ptr);
        if (end_ptr == input_ptr + 1) {
            printf("Invalid input. Please enter a temperature in Celsius or Fahrenheit.\n");
            return 1;
        }
        printf("You entered %.2f degrees Celsius.\n", celsius);
        printf("Enter 1 to convert to Fahrenheit or any other key to exit:\n");
        fgets(input_line, MAX_LINE_LENGTH, stdin);
        input_ptr = input_line;
        choice = strtol(input_ptr, NULL, 10);
        if (choice == 1) {
            fahrenheit = (celsius * 1.8) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
        }
    } else if (strcasecmp(input_ptr, "F") == 0) {
        fahrenheit = strtod(input_ptr + 1, &end_ptr);
        if (end_ptr == input_ptr + 1) {
            printf("Invalid input. Please enter a temperature in Celsius or Fahrenheit.\n");
            return 1;
        }
        printf("You entered %.2f degrees Fahrenheit.\n", fahrenheit);
        printf("Enter 1 to convert to Celsius or any other key to exit:\n");
        fgets(input_line, MAX_LINE_LENGTH, stdin);
        input_ptr = input_line;
        choice = strtol(input_ptr, NULL, 10);
        if (choice == 1) {
            celsius = (fahrenheit - 32) / 1.8;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
        }
    } else {
        printf("Invalid input. Please enter a temperature in Celsius or Fahrenheit.\n");
        return 1;
    }

    return 0;
}