//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_SIZE 1024

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    char line[MAX_LINE_SIZE];
    char *input;
    double celsius, fahrenheit;
    int choice;

    // Prompt the user for a choice
    printf("Enter your choice:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    // Read the input temperature from the user
    printf("Enter the temperature: ");
    fgets(line, MAX_LINE_SIZE, stdin);
    input = line;

    // Convert the input temperature from a string to a double
    if (choice == 1) {
        celsius = strtod(input, NULL);
        fahrenheit = celsius_to_fahrenheit(celsius);
        printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    } else if (choice == 2) {
        fahrenheit = strtod(input, NULL);
        celsius = fahrenheit_to_celsius(fahrenheit);
        printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}