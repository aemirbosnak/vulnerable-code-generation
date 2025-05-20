//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float c) {
    return (c * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float f) {
    return (f - 32) / 1.8;
}

// Function to get user input
float getInput(char *prompt) {
    float input;
    char buffer[50];

    printf("%s", prompt);
    fgets(buffer, 50, stdin);

    if (sscanf(buffer, "%f", &input)!= 1) {
        printf("Invalid input. Please enter a valid number.\n");
        exit(1);
    }

    return input;
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");

    int choice = getInput("Enter your choice: ");

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            float celsius = getInput("");
            float fahrenheit = celsiusToFahrenheit(celsius);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            float fahrenheit_in = getInput("");
            float celsius_out = fahrenheitToCelsius(fahrenheit_in);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit_in, celsius_out);
            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}