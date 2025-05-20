//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_NUM_TEMP_UNITS 3

typedef struct {
    char *unit;
    double (*convert)(double);
} TempUnit;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

void printTempUnits() {
    printf("Supported temperature units:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
}

int getTempUnitChoice() {
    int choice;
    printf("Enter the number of the temperature unit you want to convert to:\n");
    scanf("%d", &choice);
    return choice;
}

int getNumTempUnits() {
    int numUnits;
    printf("How many temperatures do you want to convert? ");
    scanf("%d", &numUnits);
    return numUnits;
}

int main() {
    int numUnits, i;
    double temp, convertedTemp;
    TempUnit tempUnits[MAX_NUM_TEMP_UNITS];
    char unitChoice;

    printTempUnits();

    do {
        unitChoice = getchar();
        if (unitChoice == '1' || unitChoice == '2' || unitChoice == '3') {
            break;
        }
        printf("Invalid choice. Please enter 1, 2, or 3.\n");
    } while (TRUE);

    numUnits = getNumTempUnits();

    for (i = 0; i < numUnits; i++) {
        tempUnits[i].unit = (char *)malloc(10 * sizeof(char));
        if (unitChoice == '1') {
            strcpy(tempUnits[i].unit, "Celsius");
            tempUnits[i].convert = &celsiusToFahrenheit;
        } else if (unitChoice == '2') {
            strcpy(tempUnits[i].unit, "Fahrenheit");
            tempUnits[i].convert = &fahrenheitToCelsius;
        } else if (unitChoice == '3') {
            strcpy(tempUnits[i].unit, "Kelvin");
            tempUnits[i].convert = &celsiusToKelvin;
        }

        printf("Enter temperature %d: ", i + 1);
        scanf("%lf", &temp);

        convertedTemp = (*tempUnits[i].convert)(temp);

        printf("%.2lf %s = %.2lf %s\n", temp, tempUnits[i].unit, convertedTemp, getTempUnitChoice());
    }

    return 0;
}