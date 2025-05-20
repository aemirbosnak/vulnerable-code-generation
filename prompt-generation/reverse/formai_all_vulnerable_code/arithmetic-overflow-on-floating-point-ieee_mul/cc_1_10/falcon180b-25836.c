//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to get user input
double getInput() {
    double input;
    printf("Enter temperature: ");
    scanf("%lf", &input);
    return input;
}

// Function to display menu
void displayMenu() {
    printf("\nTemperature Converter Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    int choice;
    double input;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                input = getInput();
                printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", input, celsiusToFahrenheit(input));
                break;
            case 2:
                input = getInput();
                printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", input, fahrenheitToCelsius(input));
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 3);
    
    return 0;
}