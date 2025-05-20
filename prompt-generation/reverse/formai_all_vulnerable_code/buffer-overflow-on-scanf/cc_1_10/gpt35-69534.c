//FormAI DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>

// Functions for converting temperature units
float celsius_to_fahrenheit(float celsius) {
    return (1.8 * celsius) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Functions for converting distance units
float meters_to_feet(float meters) {
    return meters * 3.281;
}

float feet_to_meters(float feet) {
    return feet / 3.281;
}

int main() {
    int option;
    float value;

    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter a temperature in degrees Celsius: ");
            scanf("%f", &value);
            printf("%.2f°C is %.2f°F\n", value, celsius_to_fahrenheit(value));
            break;
        case 2:
            printf("Enter a temperature in degrees Fahrenheit: ");
            scanf("%f", &value);
            printf("%.2f°F is %.2f°C\n", value, fahrenheit_to_celsius(value));
            break;
        case 3:
            printf("Enter a distance in meters: ");
            scanf("%f", &value);
            printf("%.2f meters is %.2f feet\n", value, meters_to_feet(value));
            break;
        case 4:
            printf("Enter a distance in feet: ");
            scanf("%f", &value);
            printf("%.2f feet is %.2f meters\n", value, feet_to_meters(value));
            break;
        default:
            printf("Invalid option selected\n");
            return 1;
    }

    return 0;
}