//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Function prototypes
double celsius_to_fahrenheit(double);
double fahrenheit_to_celsius(double);

int main() {
    double celsius, fahrenheit;
    int choice, input;

    printf("\n--- Temperature Converter ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &input);

        if (input == 1) {
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);
            fahrenheit = celsius_to_fahrenheit(celsius);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
        } else if (input == 2) {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);
            celsius = fahrenheit_to_celsius(fahrenheit);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
        } else if (input == 3) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 0.55555555555556;
}