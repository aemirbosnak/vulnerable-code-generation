#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    int choice;
    double temp;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Enter the temperature: ");
    scanf("%lf", &temp);

    if ((choice == 1 && temp > INT_MAX) || (choice == 2 && temp > INT_MAX)) {
        printf("Error: Input too large!\n");
        return 1;
    } else if ((choice == 1 && temp < INT_MIN) || (choice == 2 && temp < INT_MIN)) {
        printf("Error: Input too small!\n");
        return 1;
    }

    if (choice == 1) {
        printf("%.2f Celsius is %.2f Fahrenheit\n", temp, celsius_to_fahrenheit(temp));
    } else {
        printf("%.2f Fahrenheit is %.2f Celsius\n", temp, fahrenheit_to_celsius(temp));
    }

    return 0;
}
