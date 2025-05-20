//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("\n=============================\n");
    printf(" Temperature Converter\n");
    printf("=============================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("=============================\n");
    printf("Choose an option (1-3): ");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

void convert_temperature() {
    int option;
    float input_temp, converted_temp;

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input_temp);
                converted_temp = celsius_to_fahrenheit(input_temp);
                printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", input_temp, converted_temp);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &input_temp);
                converted_temp = fahrenheit_to_celsius(input_temp);
                printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", input_temp, converted_temp);
                break;

            case 3:
                printf("Exiting the Temperature Converter.\n");
                return;

            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

int main() {
    printf("\nWelcome to the Temperature Converter!\n");
    convert_temperature();
    printf("Thank you for using the Temperature Converter. Goodbye!\n");
    return 0;
}