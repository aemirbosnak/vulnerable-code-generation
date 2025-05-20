//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 100

int main() {
    char input[MAX_LINE_LENGTH];
    double temperature, converted_temperature;
    char unit[3];
    int choice;

    printf("Welcome to the Happy Temperature Converter!\n");
    printf("Please enter a temperature followed by its unit (e.g. 32 F): ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    if (sscanf(input, "%lf %c", &temperature, &unit[0])!= 2 || tolower(unit[0])!= 'c' && tolower(unit[0])!= 'f') {
        printf("Invalid input. Please enter a temperature followed by its unit (e.g. 32 F): ");
        fgets(input, MAX_LINE_LENGTH, stdin);
    }

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Convert temperature\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (tolower(unit[0]) == 'c') {
                converted_temperature = (temperature * 9.0 / 5.0) + 32;
                printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, converted_temperature);
            } else {
                converted_temperature = (temperature - 32) * 5.0 / 9.0;
                printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, converted_temperature);
            }
            break;

        case 2:
            printf("Thank you for using the Happy Temperature Converter! Have a great day!\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}