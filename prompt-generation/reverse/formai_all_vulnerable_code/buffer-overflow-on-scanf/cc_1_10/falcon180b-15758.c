//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

int main() {
    int choice;
    float temperature;

    // Displaying the menu
    printf("Welcome to the Temperature Converter!\n");
    printf("Enter 1 to convert Celsius to Fahrenheit\n");
    printf("Enter 2 to convert Fahrenheit to Celsius\n");
    printf("Enter 3 to exit\n");

    // Reading the user's choice
    scanf("%d", &choice);

    // Reading the temperature
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    // Converting the temperature based on user's choice
    switch(choice) {
        case 1:
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        case 3:
            printf("Thank you for using the Temperature Converter!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}