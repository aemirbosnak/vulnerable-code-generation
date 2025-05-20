//FormAI DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

/* Function declarations */

double convertTemperature(double temp, char fromUnit, char toUnit);
double convertLength(double length, char fromUnit, char toUnit);
double convertVolume(double volume, char fromUnit, char toUnit);
double convertWeight(double weight, char fromUnit, char toUnit);

int main() {
    int choice;
    double value, result;
    char fromUnit, toUnit;

    printf("Welcome to the Unit Converter!\n\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Temperature\n");
        printf("2. Length\n");
        printf("3. Volume\n");
        printf("4. Weight\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        if (choice == 5) {
            printf("\nThank you for using the Unit Converter.\n");
            break;
        }

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        printf("Enter the unit to convert from (e.g. C, F, K for Temperature): ");
        scanf(" %c", &fromUnit);

        printf("Enter the unit to convert to (e.g. C, F, K for Temperature): ");
        scanf(" %c", &toUnit);

        switch (choice) {
            case 1:
                result = convertTemperature(value, fromUnit, toUnit);
                printf("%.2lf%c = %.2lf%c\n\n", value, fromUnit, result, toUnit);
                break;
            case 2:
                result = convertLength(value, fromUnit, toUnit);
                printf("%.2lf%c = %.2lf%c\n\n", value, fromUnit, result, toUnit);
                break;
            case 3:
                result = convertVolume(value, fromUnit, toUnit);
                printf("%.2lf%c = %.2lf%c\n\n", value, fromUnit, result, toUnit);
                break;
            case 4:
                result = convertWeight(value, fromUnit, toUnit);
                printf("%.2lf%c = %.2lf%c\n\n", value, fromUnit, result, toUnit);
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}

/* Temperature conversion function */

double convertTemperature(double temp, char fromUnit, char toUnit) {
    double result;

    if (fromUnit == 'C' && toUnit == 'F') {
        result = (temp * 9 / 5) + 32;
    } else if (fromUnit == 'F' && toUnit == 'C') {
        result = (temp - 32) * 5 / 9;
    } else if (fromUnit == 'C' && toUnit == 'K') {
        result = temp + 273.15;
    } else if (fromUnit == 'K' && toUnit == 'C') {
        result = temp - 273.15;
    } else if (fromUnit == 'F' && toUnit == 'K') {
        result = (temp + 459.67) * 5 / 9;
    } else if (fromUnit == 'K' && toUnit == 'F') {
        result = (temp * 9 / 5) - 459.67;
    } else {
        result = temp;
    }

    return result;
}

/* Length conversion function */

double convertLength(double length, char fromUnit, char toUnit) {
    double result;

    if (fromUnit == 'm' && toUnit == 'ft') {
        result = length * 3.28084;
    } else if (fromUnit == 'ft' && toUnit == 'm') {
        result = length / 3.28084;
    } else if (fromUnit == 'm' && toUnit == 'in') {
        result = length * 39.3701;
    } else if (fromUnit == 'in' && toUnit == 'm') {
        result = length / 39.3701;
    } else if (fromUnit == 'ft' && toUnit == 'in') {
        result = length * 12;
    } else if (fromUnit == 'in' && toUnit == 'ft') {
        result = length / 12;
    } else {
        result = length;
    }

    return result;
}

/* Volume conversion function */

double convertVolume(double volume, char fromUnit, char toUnit) {
    double result;

    if (fromUnit == 'l' && toUnit == 'gal') {
        result = volume * 0.264172;
    } else if (fromUnit == 'gal' && toUnit == 'l') {
        result = volume / 0.264172;
    } else if (fromUnit == 'ml' && toUnit == 'oz') {
        result = volume * 0.033814;
    } else if (fromUnit == 'oz' && toUnit == 'ml') {
        result = volume / 0.033814;
    } else if (fromUnit == 'ml' && toUnit == 'tsp') {
        result = volume * 0.202884;
    } else if (fromUnit == 'tsp' && toUnit == 'ml') {
        result = volume / 0.202884;
    } else {
        result = volume;
    }

    return result;
}

/* Weight conversion function */

double convertWeight(double weight, char fromUnit, char toUnit) {
    double result;

    if (fromUnit == 'kg' && toUnit == 'lb') {
        result = weight * 2.20462;
    } else if (fromUnit == 'lb' && toUnit == 'kg') {
        result = weight / 2.20462;
    } else if (fromUnit == 'g' && toUnit == 'oz') {
        result = weight * 0.035274;
    } else if (fromUnit == 'oz' && toUnit == 'g') {
        result = weight / 0.035274;
    } else if (fromUnit == 'g' && toUnit == 'mg') {
        result = weight * 1000;
    } else if (fromUnit == 'mg' && toUnit == 'g') {
        result = weight / 1000;
    } else {
        result = weight;
    }

    return result;
}