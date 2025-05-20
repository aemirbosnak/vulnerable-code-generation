//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    float celsius, fahrenheit;
    char choice;

    // Initialize the temperature in Celsius
    celsius = 0;

    // Prompt the user to choose the temperature scale
    printf("Choose the temperature scale: \n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    scanf("%c", &choice);

    // Convert the user input to uppercase
    choice = toupper(choice);

    // Check if the input is valid
    if (choice!= '1' && choice!= '2') {
        printf("Invalid choice!\n");
        return 0;
    }

    // Convert the input temperature to Celsius
    if (choice == '2') {
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = fahrenheit_to_celsius(fahrenheit);
    }

    // Display the current temperature in Celsius
    printf("The current temperature is %.2f degrees Celsius.\n", celsius);

    // Convert the temperature to Fahrenheit
    fahrenheit = celsius_to_fahrenheit(celsius);

    // Display the temperature in Fahrenheit
    printf("The current temperature is %.2f degrees Fahrenheit.\n", fahrenheit);

    // Wait for a key press before exiting the program
    printf("Press any key to exit...\n");
    getchar();

    return 0;
}