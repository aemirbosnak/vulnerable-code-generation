//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void) {
    float celsius, fahrenheit, kelvin;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please select a temperature scale:\n");
    printf("1. Celsius to Fahrenheit\n2. Celsius to Kelvin\n3. Fahrenheit to Celsius\n4. Fahrenheit to Kelvin\n5. Kelvin to Celsius\n6. Kelvin to Fahrenheit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = celsius * (9.0/5.0) + 32.0;
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
            break;
        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &celsius);
            kelvin = celsius + 273.15;
            printf("%.2f Celsius is equal to %.2f Kelvin.\n", celsius, kelvin);
            break;
        case 3:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32.0) * (5.0/9.0);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);
            break;
        case 4:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            kelvin = (fahrenheit + 459.67) * (5.0/9.0);
            printf("%.2f Fahrenheit is equal to %.2f Kelvin.\n", fahrenheit, kelvin);
            break;
        case 5:
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &kelvin);
            celsius = kelvin - 273.15;
            printf("%.2f Kelvin is equal to %.2f Celsius.\n", kelvin, celsius);
            break;
        case 6:
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &kelvin);
            fahrenheit = (kelvin * 9.0/5.0) - 459.67;
            printf("%.2f Kelvin is equal to %.2f Fahrenheit.\n", kelvin, fahrenheit);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}