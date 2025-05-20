//FormAI DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printMenu();
double convertMetricToImperial(char unit, double value);
double convertImperialToMetric(char unit, double value);

int main() {
    char choice;
    double value;

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printMenu();

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'q') {
            printf("Goodbye!\n");
            break;
        }

        printf("Enter the value to convert: ");
        scanf(" %lf", &value);

        double result = 0.0;

        if (choice == '1') {
            printf("Enter the unit to convert to (in, ft, yd, mi): ");
            char unit;
            scanf(" %c", &unit);
            result = convertMetricToImperial(unit, value);
            printf("%.2lf meters is equal to %.2lf %c\n", value, result, unit);
        }
        else if (choice == '2') {
            printf("Enter the unit to convert to (mm, cm, m, km): ");
            char unit;
            scanf(" %c", &unit);
            result = convertImperialToMetric(unit, value);
            printf("%.2lf feet is equal to %.2lf %c\n", value, result, unit);
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void printMenu() {
    printf("\n1. Convert metric to imperial\n2. Convert imperial to metric\n");
    printf("q. Quit\n");
}

double convertMetricToImperial(char unit, double value) {
    double result = 0.0;

    switch (unit) {
        case 'in':
            result = value * 39.37;
            break;
        case 'ft':
            result = value * 3.281;
            break;
        case 'yd':
            result = value * 1.094;
            break;
        case 'mi':
            result = value * 0.00062;
            break;
        default:
            printf("Invalid unit. Please try again.\n");
            break;
    }

    return result;
}

double convertImperialToMetric(char unit, double value) {
    double result = 0.0;

    switch (unit) {
        case 'mm':
            result = value * 304.8;
            break;
        case 'cm':
            result = value * 30.48;
            break;
        case 'm':
            result = value * 0.3048;
            break;
        case 'km':
            result = value * 0.0003048;
            break;
        default:
            printf("Invalid unit. Please try again.\n");
            break;
    }

    return result;
}