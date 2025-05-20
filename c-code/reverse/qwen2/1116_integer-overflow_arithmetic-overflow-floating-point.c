#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

double celsiusToGalactic(double celsius) {
    if (celsius > INT_MAX || celsius < INT_MIN) {
        return -1;
    }
    double galactic = celsius * 2.5 + 30;
    return galactic;
}

int main() {
    int choice;
    double temp;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Celsius to Galactic\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &temp);

    switch (choice) {
        case 1:
            printf("%.2f Celsius is %.2f Fahrenheit\n", temp, (temp * 9 / 5) + 32);
            break;
        case 2:
            printf("%.2f Celsius is %.2f Kelvin\n", temp, temp + 273.15);
            break;
        case 3:
            double result = celsiusToGalactic(temp);
            if (result == -1) {
                printf("Error: Temperature out of range.\n");
            } else {
                printf("%.2f Celsius is %.2f Galactic\n", temp, result);
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
