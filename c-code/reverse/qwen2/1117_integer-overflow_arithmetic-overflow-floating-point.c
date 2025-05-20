#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

double celsius_to_galactic(double celsius) {
    return (celsius * 1.5) + 32;
}

double galactic_to_celsius(double galactic) {
    return (galactic - 32) / 1.5;
}

int main() {
    double temp, result;
    int choice;

    printf("Temperature Converter\n");
    printf("1. Celsius to Galactic\n");
    printf("2. Galactic to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &temp);
        if (temp > INT_MAX || temp < INT_MIN) {
            printf("Error: Temperature out of range.\n");
            return 1;
        }
        result = celsius_to_galactic(temp);
        printf("%.2f Celsius is %.2f Galactic.\n", temp, result);
    } else if (choice == 2) {
        printf("Enter temperature in Galactic: ");
        scanf("%lf", &temp);
        if (temp > INT_MAX || temp < INT_MIN) {
            printf("Error: Temperature out of range.\n");
            return 1;
        }
        result = galactic_to_celsius(temp);
        printf("%.2f Galactic is %.2f Celsius.\n", temp, result);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}
