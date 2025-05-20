//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to display the temperature in both Celsius and Fahrenheit
void display_temperature(float temperature, int unit) {
    if (unit == 1) {
        printf("The temperature is %.2f degrees Celsius.\n", temperature);
    } else {
        printf("The temperature is %.2f degrees Fahrenheit.\n", temperature);
    }
}

int main() {
    char choice;
    float temperature;
    int unit;

    // Display the menu
    printf("Welcome to the Medieval Temperature Monitor!\n\n");
    printf("Please choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Display temperature in both Celsius and Fahrenheit\n");

    // Get the user's choice
    scanf("%c", &choice);

    // Convert Celsius to Fahrenheit
    if (choice == '1') {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temperature);
        printf("The temperature in Fahrenheit is %.2f.\n", celsius_to_fahrenheit(temperature));
    }
    // Convert Fahrenheit to Celsius
    else if (choice == '2') {
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        printf("The temperature in Celsius is %.2f.\n", fahrenheit_to_celsius(temperature));
    }
    // Display temperature in both Celsius and Fahrenheit
    else if (choice == '3') {
        printf("Enter the temperature: ");
        scanf("%f", &temperature);
        printf("Choose the unit of measurement:\n1. Celsius\n2. Fahrenheit\n");
        scanf("%d", &unit);
        display_temperature(temperature, unit);
    }
    // Invalid choice
    else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}