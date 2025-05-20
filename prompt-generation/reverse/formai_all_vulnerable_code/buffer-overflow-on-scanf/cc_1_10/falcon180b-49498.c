//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to get user input
float getInput() {
    float input;
    printf("Enter temperature: ");
    scanf("%f", &input);
    return input;
}

// Function to print the result
void printResult(float result) {
    printf("Result: %.2f %s = %.2f %s\n", result, "Celsius", result, "Fahrenheit");
}

// Main function
int main() {
    float input;
    char choice;
    do {
        printf("Enter 'c' to convert Celsius to Fahrenheit or 'f' to convert Fahrenheit to Celsius: ");
        scanf("%c", &choice);
        input = getInput();
        switch(choice) {
            case 'c':
                printResult(celsiusToFahrenheit(input));
                break;
            case 'f':
                printResult(fahrenheitToCelsius(input));
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("Do you want to continue? (y/n): ");
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');
    return 0;
}