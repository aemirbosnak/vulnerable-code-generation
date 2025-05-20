//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    double conversion_factor;
} Unit;

const double FEET_IN_METER = 0.3048;
const double INCH_IN_METER = 0.0254;
const double POUNDS_IN_KG = 0.453592;
const double OUNCES_IN_KG = 0.002248;
const double GALLONS_IN_LITER = 3.78541;
const double QUARTS_IN_LITER = 0.946353;

Unit units[] = {
    {"Feet", FEET_IN_METER},
    {"Inches", INCH_IN_METER},
    {"Pounds", POUNDS_IN_KG},
    {"Ounces", OUNCES_IN_KG},
    {"Gallons", GALLONS_IN_LITER},
    {"Quarts", QUARTS_IN_LITER},
};

int main() {
    int choice1, choice2, i;
    double value, result;

    printf("Welcome to the Unit Converter!\n");
    printf("Select the first unit of measurement:\n");
    for (i = 0; i < 6; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    scanf("%d", &choice1);

    double input_value;
    printf("Enter the value to be converted: ");
    scanf("%lf", &input_value);

    printf("Select the second unit of measurement:\n");
    for (i = 0; i < 6; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    scanf("%d", &choice2);

    result = input_value * units[choice1 - 1].conversion_factor / units[choice2 - 1].conversion_factor;

    printf("%.2lf %s is equal to %.2lf %s\n", input_value, units[choice1 - 1].name, result, units[choice2 - 1].name);

    return 0;
}