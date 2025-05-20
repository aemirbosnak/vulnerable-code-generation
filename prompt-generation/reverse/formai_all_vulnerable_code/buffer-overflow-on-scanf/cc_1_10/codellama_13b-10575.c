//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: dynamic
/*
* Temperature Converter
*
* This program converts a temperature from one scale to another.
*
*/

#include <stdio.h>

// Declare a structure to store the temperature values
struct temperature {
    float celsius;
    float fahrenheit;
};

// Function to convert a temperature from Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert a temperature from Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Main function
int main() {
    // Declare a temperature structure
    struct temperature temp;

    // Ask the user to enter the temperature in Celsius
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temp.celsius);

    // Convert the temperature to Fahrenheit
    temp.fahrenheit = celsius_to_fahrenheit(temp.celsius);

    // Print the temperature in Fahrenheit
    printf("The temperature in Fahrenheit is: %.2f\n", temp.fahrenheit);

    // Ask the user to enter the temperature in Fahrenheit
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &temp.fahrenheit);

    // Convert the temperature to Celsius
    temp.celsius = fahrenheit_to_celsius(temp.fahrenheit);

    // Print the temperature in Celsius
    printf("The temperature in Celsius is: %.2f\n", temp.celsius);

    return 0;
}