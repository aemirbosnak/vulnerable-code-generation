//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function to check if input is a valid number
int isNumber(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

int main() {
    double celsius, fahrenheit;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter C to convert Celsius to Fahrenheit, or F to convert Fahrenheit to Celsius: ");
    scanf("%c", &choice);

    while (choice!= 'C' && choice!= 'F') {
        printf("Invalid input. Please enter C or F: ");
        scanf("%c", &choice);
    }

    if (choice == 'C') {
        printf("Enter the temperature in Celsius: ");
        if (!isNumber(scanf("%lf", &celsius))) {
            printf("Invalid input. Please enter a valid number: ");
            scanf("%lf", &celsius);
        }

        printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, celsiusToFahrenheit(celsius));
    } else {
        printf("Enter the temperature in Fahrenheit: ");
        if (!isNumber(scanf("%lf", &fahrenheit))) {
            printf("Invalid input. Please enter a valid number: ");
            scanf("%lf", &fahrenheit);
        }

        printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
    }

    return 0;
}