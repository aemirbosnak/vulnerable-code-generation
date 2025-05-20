//FormAI DATASET v1.0 Category: Temperature Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// function to convert Fahrenheit to Celsius recursively
double f2c(double f) {
    if (f <= -459.67) { // absolute zero
        printf("Invalid input, temperature cannot be below absolute zero.\n");
        exit(EXIT_FAILURE);
    } else if (f == -459.67) { // minimum Fahrenheit temperature
        return -273.15; // absolute zero in Celsius
    } else {
        return f2c(f-1) - 0.555555; // recursive call
    }
}

// function to convert Celsius to Fahrenheit recursively
double c2f(double c) {
    if (c <= -273.15) { // absolute zero in Celsius
        printf("Invalid input, temperature cannot be below absolute zero.\n");
        exit(EXIT_FAILURE);
    } else if (c == -273.15) { // minimum Celsius temperature
        return -459.67; // absolute zero in Fahrenheit
    } else {
        return c2f(c-1) + 1.8; // recursive call
    }
}

int main() {
    int choice; // user's choice of conversion
    double temperature; // temperature to be converted
    
    printf("Temperature Converter\n");
    printf("---------------------\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, f2c(temperature));
            break;
        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, c2f(temperature));
            break;
        default:
            printf("Error: Invalid choice.\n");
            break;
    }
    
    return 0;
}