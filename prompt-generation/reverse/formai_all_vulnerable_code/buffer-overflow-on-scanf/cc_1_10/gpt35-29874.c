//FormAI DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    float celsius = fahrenheit_to_celsius(fahrenheit);
    return celsius_to_kelvin(celsius);
}

float kelvin_to_fahrenheit(float kelvin) {
    float celsius = kelvin_to_celsius(kelvin);
    return celsius_to_fahrenheit(celsius);
}

int main() {
    float temperature;
    int choice;

    printf("Welcome to the temperature converter!\n");
    printf("What would you like to convert?\n"
           "1. Celsius to Fahrenheit\n"
           "2. Fahrenheit to Celsius\n"
           "3. Celsius to Kelvin\n"
           "4. Kelvin to Celsius\n"
           "5. Fahrenheit to Kelvin\n"
           "6. Kelvin to Fahrenheit\n"
           "Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    switch (choice) {
        case 1:
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        case 3:
            printf("%.2f Celsius is equal to %.2f Kelvin\n", temperature, celsius_to_kelvin(temperature));
            break;
        case 4:
            printf("%.2f Kelvin is equal to %.2f Celsius\n", temperature, kelvin_to_celsius(temperature));
            break;
        case 5:
            printf("%.2f Fahrenheit is equal to %.2f Kelvin\n", temperature, fahrenheit_to_kelvin(temperature));
            break;
        case 6:
            printf("%.2f Kelvin is equal to %.2f Fahrenheit\n", temperature, kelvin_to_fahrenheit(temperature));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}