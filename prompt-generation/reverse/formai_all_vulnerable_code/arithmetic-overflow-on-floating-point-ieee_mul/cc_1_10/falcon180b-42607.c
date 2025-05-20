//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    char input_line[MAX_LINE_LENGTH];
    char *input_ptr;
    char *end_ptr;
    double fahrenheit, celsius;
    int is_fahrenheit = 1;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter a temperature in Fahrenheit or Celsius, followed by 'F' or 'C':\n");
    fgets(input_line, MAX_LINE_LENGTH, stdin);

    // Remove newline character from input
    input_ptr = strchr(input_line, '\n');
    if (input_ptr!= NULL) {
        *input_ptr = '\0';
    }

    // Convert input to uppercase
    for (int i = 0; input_line[i]!= '\0'; i++) {
        input_line[i] = toupper(input_line[i]);
    }

    // Check if input is in Fahrenheit or Celsius
    if (strstr(input_line, "F")!= NULL) {
        is_fahrenheit = 1;
    } else if (strstr(input_line, "C")!= NULL) {
        is_fahrenheit = 0;
    } else {
        printf("Invalid input. Please enter a temperature in Fahrenheit or Celsius.\n");
        return 1;
    }

    // Extract temperature value from input
    input_ptr = strtok(input_line, " ");
    if (input_ptr == NULL) {
        printf("Invalid input. Please enter a temperature in Fahrenheit or Celsius.\n");
        return 1;
    }
    fahrenheit = strtod(input_ptr, &end_ptr);
    if (end_ptr == input_ptr) {
        printf("Invalid input. Please enter a temperature in Fahrenheit or Celsius.\n");
        return 1;
    }

    // Convert temperature
    if (is_fahrenheit) {
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("%g degrees Fahrenheit is %g degrees Celsius.\n", fahrenheit, celsius);
    } else {
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("%g degrees Celsius is %g degrees Fahrenheit.\n", celsius, fahrenheit);
    }

    return 0;
}