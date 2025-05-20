#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void displayMenu() {
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    float temp;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 3) {
            break;
        }

        printf("Enter temperature: ");
        scanf("%f", &temp);

        switch (choice) {
            case 1:
                printf("%.2f Celsius is %.2f Fahrenheit\n", temp, celsiusToFahrenheit(temp));
                break;
            case 2:
                printf("%.2f Fahrenheit is %.2f Celsius\n", temp, fahrenheitToCelsius(temp));
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
