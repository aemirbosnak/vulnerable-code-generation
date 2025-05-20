//FormAI DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float meters_to_feet(float meters);
float feet_to_meters(float feet);

int main() {
    int choice;
    float value;

    printf("Welcome to the Unit Converter!\n\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("Please select an option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter Celsius value: ");
            scanf("%f", &value);
            printf("%f Celsius is %f Fahrenheit", value, celsius_to_fahrenheit(value));
            break;
        case 2:
            printf("Enter Fahrenheit value: ");
            scanf("%f", &value);
            printf("%f Fahrenheit is %f Celsius", value, fahrenheit_to_celsius(value));
            break;
        case 3:
            printf("Enter Meters value: ");
            scanf("%f", &value);
            printf("%f Meters is %f Feet", value, meters_to_feet(value));
            break;
        case 4:
            printf("Enter Feet value: ");
            scanf("%f", &value);
            printf("%f Feet is %f Meters", value, feet_to_meters(value));
            break;
        default:
            printf("Invalid option! Please select a valid option.");
    }

    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

float meters_to_feet(float meters) {
    return meters * 3.28084;
}

float feet_to_meters(float feet) {
    return feet / 3.28084;
}