//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

// Function to check if the input string is a valid number
int is_number(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    char input_buffer[MAX_LINE_SIZE];
    double celsius, fahrenheit;
    int input_type;
    char *input_str;

    // Prompt user for input
    printf("Enter temperature in Celsius or Fahrenheit: ");
    fgets(input_buffer, MAX_LINE_SIZE, stdin);

    // Check if input is a valid number
    input_str = strtok(input_buffer, " ");
    if (is_number(input_str)) {
        celsius = atof(input_str);
        input_type = 1; // Celsius
    } else if (input_str[0] == 'F' || input_str[0] == 'f') {
        celsius = atof(strtok(NULL, " "));
        input_type = 2; // Fahrenheit
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert temperature
    if (input_type == 1) {
        fahrenheit = celsius_to_fahrenheit(celsius);
        printf("%.2f Celsius is %.2f Fahrenheit.\n", celsius, fahrenheit);
    } else {
        celsius = fahrenheit_to_celsius(celsius);
        printf("%.2f Fahrenheit is %.2f Celsius.\n", celsius, fahrenheit);
    }

    return 0;
}