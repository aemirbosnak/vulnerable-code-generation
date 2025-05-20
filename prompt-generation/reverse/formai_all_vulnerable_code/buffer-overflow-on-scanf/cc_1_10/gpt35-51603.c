//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

// function to convert temperature from Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// function to convert temperature from Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// function to convert length from meters to feet
float meters_to_feet(float meters) {
    return meters * 3.2808;
}

// function to convert length from feet to meters
float feet_to_meters(float feet) {
    return feet / 3.2808;
}

// function to convert weight from kilograms to pounds
float kilograms_to_pounds(float kilograms) {
    return kilograms * 2.20462;
}

// function to convert weight from pounds to kilograms
float pounds_to_kilograms(float pounds) {
    return pounds / 2.20462;
}

int main() {
    int choice;
    float temp, length, weight;
    printf("Select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Kilograms to Pounds\n");
    printf("6. Pounds to Kilograms\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            printf("%.2f Celsius = %.2f Fahrenheit\n", temp, celsius_to_fahrenheit(temp));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            printf("%.2f Fahrenheit = %.2f Celsius\n", temp, fahrenheit_to_celsius(temp));
            break;
        case 3:
            printf("Enter length in meters: ");
            scanf("%f", &length);
            printf("%.2f meters = %.2f feet\n", length, meters_to_feet(length));
            break;
        case 4:
            printf("Enter length in feet: ");
            scanf("%f", &length);
            printf("%.2f feet = %.2f meters\n", length, feet_to_meters(length));
            break;
        case 5:
            printf("Enter weight in kilograms: ");
            scanf("%f", &weight);
            printf("%.2f kilograms = %.2f pounds\n", weight, kilograms_to_pounds(weight));
            break;
        case 6:
            printf("Enter weight in pounds: ");
            scanf("%f", &weight);
            printf("%.2f pounds = %.2f kilograms\n", weight, pounds_to_kilograms(weight));
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}