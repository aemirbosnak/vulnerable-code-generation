//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[] = {
    {"Miles", 1609.34},
    {"Kilometers", 0.000621371},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Degrees Fahrenheit", 0.555555555555},
    {"Degrees Celsius", 0.555555555555},
    {"Inches", 0.0254},
    {"Centimeters", 2.54},
    {"Ounces", 0.0352737},
    {"Grams", 35.2737}
};

int main() {
    char inputUnitName[50], outputUnitName[50];
    double inputValue, outputValue;
    int i;

    printf("Welcome to the C Unit Converter!\n");
    printf("Enter the value and unit you want to convert from:\n");
    printf("Value: ");
    scanf("%lf", &inputValue);
    printf("Unit: ");
    scanf("%s", inputUnitName);

    for (i = 0; i < 10; i++) {
        if (strcmp(inputUnitName, units[i].name) == 0) {
            inputValue *= units[i].factor;
            break;
        }
    }

    printf("Enter the unit you want to convert to:\n");
    printf("Unit: ");
    scanf("%s", outputUnitName);

    for (i = 0; i < 10; i++) {
        if (strcmp(outputUnitName, units[i].name) == 0) {
            outputValue = inputValue / units[i].factor;
            break;
        }
    }

    printf("The value %lf %s is equal to %lf %s.\n", inputValue, inputUnitName, outputValue, outputUnitName);

    return 0;
}