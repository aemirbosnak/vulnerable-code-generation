//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// function to convert Celsius to Fahrenheit
float convertCtoF(float celsius) {
    return (celsius * 1.8) + 32;
}

// function to convert Fahrenheit to Celsius
float convertFtoC(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// function to convert Celsius to Kelvin
float convertCtoK(float celsius) {
    return celsius + 273.15;
}

// function to convert Kelvin to Celsius
float convertKtoC(float kelvin) {
    return kelvin - 273.15;
}

// function to convert Fahrenheit to Kelvin
float convertFtoK(float fahrenheit) {
    return (5.0 / 9.0 * (fahrenheit - 32) + 273.15);
}

//function to convert Kelvin to Fahrenheit
float convertKtoF(float kelvin) {
    return (9.0 / 5.0 * (kelvin - 273.15) + 32);
}

// Main function
int main() {
    int choice;
    float temp, converted_temp;
    do {
        printf("\nWelcome to the Temperature Unit Converter\n");
        printf("Options:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Fahrenheit to Kelvin\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temp);
                converted_temp = convertCtoF(temp);
                printf("%.2f°C = %.2f°F\n", temp, converted_temp);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temp);
                converted_temp = convertFtoC(temp);
                printf("%.2f°F = %.2f°C\n", temp, converted_temp);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temp);
                converted_temp = convertCtoK(temp);
                printf("%.2f°C = %.2fK\n", temp, converted_temp);
                break;
            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temp);
                converted_temp = convertKtoC(temp);
                printf("%.2fK = %.2f°C\n", temp, converted_temp);
                break;
            case 5:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temp);
                converted_temp = convertFtoK(temp);
                printf("%.2f°F = %.2fK\n", temp, converted_temp);
                break;
            case 6:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temp);
                converted_temp = convertKtoF(temp);
                printf("%.2fK = %.2f°F\n", temp, converted_temp);
                break;
            case 0:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.");
        }
    } while (choice != 0);

    return 0;
}