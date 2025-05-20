//FormAI DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>

// Function to convert kilometers to miles
float kmToMiles(float kilometers) {
    float miles = kilometers / 1.609;
    return miles;
}

// Function to convert miles to kilometers
float milesToKm(float miles) {
    float kilometers = miles * 1.609;
    return kilometers;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Main function
int main() {
    float input, result;
    int choice;

    printf("Enter the value to be converted: ");
    scanf("%f", &input);

    printf("\nSelect the type of conversion:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Kilometers to Miles
            result = kmToMiles(input);
            printf("\n%.2f kilometers = %.2f miles\n", input, result);
            break;
        case 2: // Miles to Kilometers
            result = milesToKm(input);
            printf("\n%.2f miles = %.2f kilometers\n", input, result);
            break;
        case 3: // Celsius to Fahrenheit
            result = celsiusToFahrenheit(input);
            printf("\n%.2f degrees Celsius = %.2f degrees Fahrenheit\n", input, result);
            break;
        case 4: // Fahrenheit to Celsius
            result = fahrenheitToCelsius(input);
            printf("\n%.2f degrees Fahrenheit = %.2f degrees Celsius\n", input, result);
            break;
        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}