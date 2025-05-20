//FormAI DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);

int main() {
    float temperature;
    int choice;

    printf("Welcome to Temperature Converter\n\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Please enter a temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
                break;
            case 2:
                printf("Please enter a temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("%.2f Fahrenheit is %.2f Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
        printf("\n");
    }

    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}