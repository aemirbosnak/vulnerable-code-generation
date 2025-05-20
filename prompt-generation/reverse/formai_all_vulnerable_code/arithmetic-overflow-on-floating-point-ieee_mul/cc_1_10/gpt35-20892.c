//FormAI DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// function to convert Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// main function
int main() {
    int choice;
    float input, output;

    // prompt user for the conversion type
    printf("Select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    scanf("%d", &choice);

    // prompt user for input value
    printf("Enter the value to convert: ");
    scanf("%f", &input);

    // perform the conversion based on the user's choice
    switch(choice) {
        case 1:
            output = celsius_to_fahrenheit(input);
            printf("%.2f C = %.2f F\n", input, output);
            break;
        case 2:
            output = fahrenheit_to_celsius(input);
            printf("%.2f F = %.2f C\n", input, output);
            break;
        case 3:
            output = celsius_to_kelvin(input);
            printf("%.2f C = %.2f K\n", input, output);
            break;
        case 4:
            output = kelvin_to_celsius(input);
            printf("%.2f K = %.2f C\n", input, output);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}