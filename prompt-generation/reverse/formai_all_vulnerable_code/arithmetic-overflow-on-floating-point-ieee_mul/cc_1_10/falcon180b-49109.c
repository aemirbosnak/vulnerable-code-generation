//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    double temperature;
    char unit;
    struct tm *timeinfo;
    time_t now;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please choose the unit of measurement:\n");
    printf("1. Celsius\n2. Fahrenheit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        unit = 'C';
    } else if (choice == 2) {
        unit = 'F';
    } else {
        printf("Invalid choice. Exiting program.\n");
        return 0;
    }

    while (1) {
        now = time(NULL);
        timeinfo = localtime(&now);
        printf("Current date and time: %s\n", asctime(timeinfo));

        printf("Enter the current temperature (in %c): ", unit);
        scanf("%lf", &temperature);

        if (unit == 'C') {
            printf("The temperature is %.2lf degrees Celsius.\n", temperature);
        } else if (unit == 'F') {
            temperature = (temperature * 9.0 / 5.0) + 32.0;
            printf("The temperature is %.2lf degrees Fahrenheit.\n", temperature);
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            printf("Exiting program.\n");
            return 0;
        }
    }

    return 0;
}