//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265359

int main(void) {
    double temperature;
    char input[100];
    int choice;

    srand(time(NULL));

    while (1) {
        printf("Welcome to the Temperature Monitor!\n");
        printf("Please choose an option:\n");
        printf("1. Enter temperature in Celsius\n");
        printf("2. Enter temperature in Fahrenheit\n");
        printf("3. Convert temperature from Celsius to Fahrenheit\n");
        printf("4. Convert temperature from Fahrenheit to Celsius\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2lf degrees Celsius is equivalent to %.2lf degrees Fahrenheit.\n", temperature, (temperature * 9/5) + 32);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("%.2lf degrees Fahrenheit is equivalent to %.2lf degrees Celsius.\n", temperature, (temperature - 32) * 5/9);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2lf degrees Celsius is equivalent to %.2lf degrees Fahrenheit.\n", temperature, (temperature * 9/5) + 32);
                break;
            case 4:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("%.2lf degrees Fahrenheit is equivalent to %.2lf degrees Celsius.\n", temperature, (temperature - 32) * 5/9);
                break;
            case 5:
                printf("Thank you for using the Temperature Monitor!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}