//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>
#include <stdbool.h>

void display_menu() {
    printf("=====================================\n");
    printf("       Temperature Converter         \n");
    printf("=====================================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
    printf("=====================================\n");
    printf("Please select an option: ");
}

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
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

void convert_temperature(int option) {
    float input_temp, output_temp;

    switch (option) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input_temp);
            output_temp = celsius_to_fahrenheit(input_temp);
            printf("Temperature in Fahrenheit: %.2f\n", output_temp);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input_temp);
            output_temp = fahrenheit_to_celsius(input_temp);
            printf("Temperature in Celsius: %.2f\n", output_temp);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input_temp);
            output_temp = celsius_to_kelvin(input_temp);
            printf("Temperature in Kelvin: %.2f\n", output_temp);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &input_temp);
            output_temp = kelvin_to_celsius(input_temp);
            printf("Temperature in Celsius: %.2f\n", output_temp);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input_temp);
            output_temp = fahrenheit_to_kelvin(input_temp);
            printf("Temperature in Kelvin: %.2f\n", output_temp);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &input_temp);
            output_temp = kelvin_to_fahrenheit(input_temp);
            printf("Temperature in Fahrenheit: %.2f\n", output_temp);
            break;
        default:
            printf("Invalid option.\n");
    }
}

int main() {
    int option;
    bool running = true;

    while (running) {
        display_menu();
        scanf("%d", &option);

        if (option == 0) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            running = false;
        } else {
            convert_temperature(option);
        }
        printf("\n");
    }

    return 0;
}