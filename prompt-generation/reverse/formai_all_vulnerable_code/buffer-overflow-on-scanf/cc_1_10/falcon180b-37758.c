//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float factor;
} unit;

unit units[] = {
    {"meters", 1.0},
    {"kilometers", 0.001},
    {"centimeters", 100.0},
    {"inches", 0.254},
    {"feet", 0.3048},
    {"yards", 0.9144},
    {"miles", 0.000621371},
    {"pounds", 0.453592},
    {"ounces", 0.0283495},
    {"grams", 1.0},
    {"kilograms", 0.001},
    {"milliliters", 1.0},
    {"liters", 0.001},
    {"gallons", 0.00378541},
    {"celsius", 1.0},
    {"fahrenheit", 0.555555},
};

int main() {
    int num_units = sizeof(units) / sizeof(units[0]);
    int choice;
    char input[50];
    float value, result;

    printf("Unit Converter\n\n");
    printf("Enter a value to convert: ");
    scanf("%f", &value);

    printf("\nSelect a unit to convert to:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("\nEnter the unit you want to convert from:\n");
    scanf("%s", input);

    int index = 0;
    while (strcmp(input, units[index].name)!= 0) {
        index++;
        if (index == num_units) {
            printf("Invalid unit\n");
            return 0;
        }
    }

    result = value * units[choice].factor;

    printf("\n%f %s = %f %s\n", value, input, result, units[choice].name);

    return 0;
}