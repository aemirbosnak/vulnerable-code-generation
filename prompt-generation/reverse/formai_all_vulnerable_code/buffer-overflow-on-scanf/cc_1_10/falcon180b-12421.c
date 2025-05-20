//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

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

// Main function
int main() {
    float celsius, fahrenheit;
    char choice;

    // Get input from user
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = celsius_to_fahrenheit(celsius);

    // Display converted temperature
    printf("Temperature in Fahrenheit: %f\n", fahrenheit);

    // Ask user if they want to convert to Celsius
    printf("Do you want to convert to Celsius? (y/n): ");
    scanf(" %c", &choice);

    // Convert Fahrenheit to Celsius
    if (choice == 'y' || choice == 'Y') {
        celsius = fahrenheit_to_celsius(fahrenheit);

        // Display converted temperature
        printf("Temperature in Celsius: %f\n", celsius);
    }

    return 0;
}

/*
Sample Input/Output:
Enter temperature in Celsius: 25
Temperature in Fahrenheit: 77.000000
Do you want to convert to Celsius? (y/n): y
Temperature in Celsius: 25.000000
*/