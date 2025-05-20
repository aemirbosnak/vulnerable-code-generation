//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to generate a random temperature in Celsius
float generate_random_celsius() {
    return rand() % 100;
}

// Function to generate a random temperature in Fahrenheit
float generate_random_fahrenheit() {
    return rand() % 200 - 32;
}

int main() {
    srand(time(NULL));

    int choice;
    float temperature_celsius, temperature_fahrenheit;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Enter 1 to convert Celsius to Fahrenheit\n");
    printf("Enter 2 to convert Fahrenheit to Celsius\n");
    printf("Enter 3 to generate a random temperature in Celsius\n");
    printf("Enter 4 to generate a random temperature in Fahrenheit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &temperature_celsius);
            temperature_fahrenheit = celsius_to_fahrenheit(temperature_celsius);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature_celsius, temperature_fahrenheit);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &temperature_fahrenheit);
            temperature_celsius = fahrenheit_to_celsius(temperature_fahrenheit);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature_fahrenheit, temperature_celsius);
            break;
        case 3:
            temperature_celsius = generate_random_celsius();
            printf("A random temperature in Celsius: %.2f\n", temperature_celsius);
            break;
        case 4:
            temperature_fahrenheit = generate_random_fahrenheit();
            printf("A random temperature in Fahrenheit: %.2f\n", temperature_fahrenheit);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}