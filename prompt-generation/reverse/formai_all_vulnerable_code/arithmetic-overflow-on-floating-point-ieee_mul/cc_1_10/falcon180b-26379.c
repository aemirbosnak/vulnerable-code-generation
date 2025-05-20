//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to validate input
int isValidInput(char *input) {
    int length = strlen(input);
    int i;

    for (i = 0; i < length; i++) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[100];
    double celsius, fahrenheit;
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("Enter a temperature value:\n");
            scanf("%s", input);

            if (isValidInput(input)) {
                if (choice == 1) {
                    celsius = atof(input);
                    printf("%.2f Celsius is %.2f Fahrenheit.\n", celsius, celsiusToFahrenheit(celsius));
                } else {
                    fahrenheit = atof(input);
                    printf("%.2f Fahrenheit is %.2f Celsius.\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
                }
            } else {
                printf("Invalid input.\n");
            }
        }

    } while (choice!= 3);

    return 0;
}