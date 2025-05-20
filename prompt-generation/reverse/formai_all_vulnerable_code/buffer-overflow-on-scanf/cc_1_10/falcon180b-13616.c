//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    char input[MAX_LENGTH];
    double celsius, fahrenheit;

    // Prompt the user to enter a temperature in Celsius
    printf("Enter a temperature in Celsius: ");

    // Read the input from the user
    fgets(input, MAX_LENGTH, stdin);

    // Convert the input string to a double
    celsius = strtod(input, NULL);

    // Convert Celsius to Fahrenheit
    fahrenheit = celsius_to_fahrenheit(celsius);

    // Print the results
    printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

    // Prompt the user to convert another temperature
    char choice;
    do {
        printf("Do you want to convert another temperature? (y/n): ");
        scanf(" %c", &choice);
    } while (choice!= 'y' && choice!= 'n');

    // If the user wants to continue, prompt for another temperature
    if (choice == 'y') {
        main();
    }

    return 0;
}