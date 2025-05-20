//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int main() {
    int choice;
    float temperature;
    char unit;

    do {
        printf("Temperature Monitor\n");
        printf("--------------------\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, (temperature * 9.0 / 5.0) + 32.0);
            printf("%.2f Celsius is %.2f Kelvin\n", temperature, temperature + 273.15);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, (temperature - 32.0) * 5.0 / 9.0);
            printf("%.2f Fahrenheit is %.2f Kelvin\n", temperature, temperature + 459.67);
            break;
        case 3:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &temperature);
            printf("%.2f Kelvin is %.2f Celsius\n", temperature, temperature - 273.15);
            printf("%.2f Kelvin is %.2f Fahrenheit\n", temperature, (temperature * 9.0 / 5.0) - 459.67);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &unit);
    } while (unit == 'y' || unit == 'Y');

    return 0;
}