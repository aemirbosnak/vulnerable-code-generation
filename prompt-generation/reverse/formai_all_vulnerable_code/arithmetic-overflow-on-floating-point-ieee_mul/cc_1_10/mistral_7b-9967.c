//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char unit[10];
    double conversion_factor;
} UnitConversionFactor;

UnitConversionFactor units[] = {
    {"Miles", 0.000621371},
    {"Kilometers", 1.60934},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Degrees Fahrenheit", 1.8},
    {"Degrees Celsius", 0.555556},
    {"Liters", 0.264172},
    {"Gallons", 3.78541},
    {"Degrees Angle", 0.0174533},
    {"Degrees Arc", 0.0174533}
};

int main() {
    int i, j, choice1, choice2, conversion_type;
    double value, result;

    printf("Welcome to the C Unit Converter!\n");
    printf("Please choose the first unit from the list below:\n");

    for (i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, units[i].unit);
    }

    scanf("%d", &choice1);

    printf("Now, please choose the second unit from the list below:\n");

    for (i = 0; i < 10; i++) {
        if (i == choice1 - 1) {
            continue;
        }
        printf("%d. %s\n", i + 1, units[i].unit);
    }

    scanf("%d", &choice2);

    conversion_type = choice1 - 1;

    printf("Please enter the value in %s:\n", units[conversion_type].unit);
    scanf("%lf", &value);

    result = value * units[conversion_type].conversion_factor / units[choice2 - 1].conversion_factor;

    printf("%.2lf %s is equal to %.2lf %s\n", value, units[conversion_type].unit, result, units[choice2 - 1].unit);

    return 0;
}