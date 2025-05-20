//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: imaginative
// Imaginative C Temperature Monitor Program

#include <stdio.h>
#include <stdlib.h>

// Define temperature struct
struct temperature {
    int degrees;
    char unit;
};

// Define function to read temperature from user
struct temperature get_temperature() {
    struct temperature temp;
    printf("Enter temperature: ");
    scanf("%d", &temp.degrees);
    printf("Enter temperature unit (C or F): ");
    scanf(" %c", &temp.unit);
    return temp;
}

// Define function to convert temperature from Celsius to Fahrenheit
struct temperature celsius_to_fahrenheit(struct temperature temp) {
    struct temperature fahrenheit;
    fahrenheit.degrees = (temp.degrees * 9 / 5) + 32;
    fahrenheit.unit = 'F';
    return fahrenheit;
}

// Define function to convert temperature from Fahrenheit to Celsius
struct temperature fahrenheit_to_celsius(struct temperature temp) {
    struct temperature celsius;
    celsius.degrees = (temp.degrees - 32) * 5 / 9;
    celsius.unit = 'C';
    return celsius;
}

// Define function to display temperature in a specific unit
void display_temperature(struct temperature temp, char unit) {
    if (unit == 'C') {
        printf("Temperature in Celsius: %d\n", temp.degrees);
    } else if (unit == 'F') {
        printf("Temperature in Fahrenheit: %d\n", temp.degrees);
    }
}

int main() {
    // Get temperature from user
    struct temperature temp = get_temperature();

    // Convert temperature to Fahrenheit
    struct temperature fahrenheit = celsius_to_fahrenheit(temp);

    // Display temperature in Fahrenheit
    display_temperature(fahrenheit, 'F');

    // Convert temperature to Celsius
    struct temperature celsius = fahrenheit_to_celsius(fahrenheit);

    // Display temperature in Celsius
    display_temperature(celsius, 'C');

    return 0;
}