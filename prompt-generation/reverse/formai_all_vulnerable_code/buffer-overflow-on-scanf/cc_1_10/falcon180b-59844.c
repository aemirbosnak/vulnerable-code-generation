//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double celsius, fahrenheit, kelvin;
    int choice;

    printf("Enter 1 to convert Celsius to Fahrenheit.\n");
    printf("Enter 2 to convert Fahrenheit to Celsius.\n");
    printf("Enter 3 to convert Celsius to Kelvin.\n");
    printf("Enter 4 to convert Kelvin to Celsius.\n");
    printf("Enter 5 to exit.\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2lf Celsius is %.2lf Fahrenheit.\n", celsius, fahrenheit);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2lf Fahrenheit is %.2lf Celsius.\n", fahrenheit, celsius);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);
            kelvin = celsius + 273.15;
            printf("%.2lf Celsius is %.2lf Kelvin.\n", celsius, kelvin);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &kelvin);
            celsius = kelvin - 273.15;
            printf("%.2lf Kelvin is %.2lf Celsius.\n", kelvin, celsius);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}