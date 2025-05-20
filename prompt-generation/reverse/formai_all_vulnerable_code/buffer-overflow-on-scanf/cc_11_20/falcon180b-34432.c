//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    char choice;
    float temp;
    int length;
    char *ptr;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter the temperature you want to convert: ");
    fgets(input, 100, stdin);

    // Remove newline character
    if ((ptr = strchr(input, '\n'))) {
        *ptr = '\0';
    }

    // Convert input to float
    temp = strtof(input, &ptr);

    // Check for invalid input
    if (ptr == input) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert to Celsius
    temp -= 32;
    temp *= 5/9;

    // Convert to Fahrenheit
    temp += 32;
    temp *= 9/5;

    // Convert to Kelvin
    temp += 273.15;

    // Display the result
    printf("The temperature in Celsius is: %.2f\n", temp);
    printf("The temperature in Fahrenheit is: %.2f\n", (temp - 273.15) * 9/5 + 32);
    printf("The temperature in Kelvin is: %.2f\n", temp);

    // Ask user if they want to convert another temperature
    printf("Do you want to convert another temperature? (y/n): ");
    scanf(" %c", &choice);

    // Check for invalid input
    if (choice!= 'y' && choice!= 'n') {
        printf("Invalid input.\n");
        return 1;
    }

    // Loop until user wants to quit
    while (choice == 'y' || choice == 'Y') {
        printf("\nEnter the temperature you want to convert: ");
        fgets(input, 100, stdin);

        // Remove newline character
        if ((ptr = strchr(input, '\n'))) {
            *ptr = '\0';
        }

        // Convert input to float
        temp = strtof(input, &ptr);

        // Check for invalid input
        if (ptr == input) {
            printf("Invalid input.\n");
            continue;
        }

        // Convert to Celsius
        temp -= 32;
        temp *= 5/9;

        // Convert to Fahrenheit
        temp += 32;
        temp *= 9/5;

        // Convert to Kelvin
        temp += 273.15;

        // Display the result
        printf("The temperature in Celsius is: %.2f\n", temp);
        printf("The temperature in Fahrenheit is: %.2f\n", (temp - 273.15) * 9/5 + 32);
        printf("The temperature in Kelvin is: %.2f\n", temp);

        // Ask user if they want to convert another temperature
        printf("Do you want to convert another temperature? (y/n): ");
        scanf(" %c", &choice);

        // Check for invalid input
        if (choice!= 'y' && choice!= 'n') {
            printf("Invalid input.\n");
            continue;
        }
    }

    return 0;
}