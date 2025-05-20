//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float miles_to_kilometers(float miles) {
    return miles * 1.60934;
}

float kilometers_to_miles(float kilometers) {
    return kilometers / 1.60934;
}

float pounds_to_kilograms(float pounds) {
    return pounds * 0.453592;
}

float kilograms_to_pounds(float kilograms) {
    return kilograms / 0.453592;
}

void display_menu() {
    printf("\nWelcome to the Unit Converter!\n");
    printf("Choose an option below:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void process_choice(int choice) {
    float input_value;
    switch (choice) {
        case 1:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input_value);
            printf("%.2f Fahrenheit = %.2f Celsius\n", input_value, fahrenheit_to_celsius(input_value));
            break;
        case 2:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input_value);
            printf("%.2f Celsius = %.2f Fahrenheit\n", input_value, celsius_to_fahrenheit(input_value));
            break;
        case 3:
            printf("Enter distance in Miles: ");
            scanf("%f", &input_value);
            printf("%.2f Miles = %.2f Kilometers\n", input_value, miles_to_kilometers(input_value));
            break;
        case 4:
            printf("Enter distance in Kilometers: ");
            scanf("%f", &input_value);
            printf("%.2f Kilometers = %.2f Miles\n", input_value, kilometers_to_miles(input_value));
            break;
        case 5:
            printf("Enter weight in Pounds: ");
            scanf("%f", &input_value);
            printf("%.2f Pounds = %.2f Kilograms\n", input_value, pounds_to_kilograms(input_value));
            break;
        case 6:
            printf("Enter weight in Kilograms: ");
            scanf("%f", &input_value);
            printf("%.2f Kilograms = %.2f Pounds\n", input_value, kilograms_to_pounds(input_value));
            break;
        case 7:
            printf("Exiting the unit converter. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        process_choice(choice);
    }

    return 0;
}