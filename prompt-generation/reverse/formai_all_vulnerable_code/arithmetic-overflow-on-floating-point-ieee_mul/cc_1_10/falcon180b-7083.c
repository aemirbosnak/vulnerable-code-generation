//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double temperature, converted;
    char unit;

    printf("Welcome to the Happy Temperature Converter!\n");
    printf("Please choose a temperature unit:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    scanf("%d", &choice);

    printf("Please enter the temperature: ");
    scanf("%lf", &temperature);

    switch (choice) {
        case 1:
            printf("The temperature in Celsius is %.2lf degrees.\n", temperature);
            break;
        case 2:
            temperature = (temperature * 9/5) + 32;
            printf("The temperature in Fahrenheit is %.2lf degrees.\n", temperature);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            return 0;
    }

    printf("Would you like to convert to another unit? (y/n): ");
    scanf(" %c", &unit);

    while (unit == 'y' || unit == 'Y') {
        printf("Please choose a temperature unit:\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        scanf("%d", &choice);

        printf("Please enter the temperature: ");
        scanf("%lf", &temperature);

        switch (choice) {
            case 1:
                printf("The temperature in Celsius is %.2lf degrees.\n", temperature);
                break;
            case 2:
                temperature = (temperature - 32) * 5/9;
                printf("The temperature in Celsius is %.2lf degrees.\n", temperature);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                return 0;
        }

        printf("Would you like to convert to another unit? (y/n): ");
        scanf(" %c", &unit);
    }

    printf("Thank you for using the Happy Temperature Converter! Have a nice day!\n");

    return 0;
}