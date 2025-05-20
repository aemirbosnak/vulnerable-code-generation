//FormAI DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>

// Function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

// Function to convert Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

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

// Function to convert Miles to Kilometers
float miles_to_kilometers(float miles) {
    float kilometers = miles * 1.60934;
    return kilometers;
}

// Function to convert Kilometers to Miles
float kilometers_to_miles(float kilometers) {
    float miles = kilometers/1.60934;
    return miles;
}

int main() {
    int option;
    float value, result;

    while (1) {
        printf("Select an option from the following:\n");
        printf("1. Celsius to Kelvin\n");
        printf("2. Kelvin to Celsius\n");
        printf("3. Celsius to Fahrenheit\n");
        printf("4. Fahrenheit to Celsius\n");
        printf("5. Miles to Kilometers\n");
        printf("6. Kilometers to Miles\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 7) {
            printf("Exiting program...\n");
            break;
        }

        printf("Enter value to convert: ");
        scanf("%f", &value);

        switch (option) {
            case 1:
                result = celsius_to_kelvin(value);
                printf("%.2f Celsius = %.2f Kelvin\n", value, result);
                break;
            case 2:
                result = kelvin_to_celsius(value);
                printf("%.2f Kelvin = %.2f Celsius\n", value, result);
                break;
            case 3:
                result = celsius_to_fahrenheit(value);
                printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
                break;
            case 4:
                result = fahrenheit_to_celsius(value);
                printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
                break;
            case 5:
                result = miles_to_kilometers(value);
                printf("%.2f Miles = %.2f Kilometers\n", value, result);
                break;
            case 6:
                result = kilometers_to_miles(value);
                printf("%.2f Kilometers = %.2f Miles\n", value, result);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}