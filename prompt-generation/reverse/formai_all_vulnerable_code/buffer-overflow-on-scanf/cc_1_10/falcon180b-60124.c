//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    float factor;
} Unit;

Unit units[] = {
    {"meters", 1.0},
    {"feet", 0.3048},
    {"inches", 0.0254},
    {"yards", 0.9144},
    {"miles", 160934.4},
    {"kilograms", 1.0},
    {"pounds", 2.20462},
    {"ounces", 0.035274},
    {"gallons", 3.78541},
    {"liters", 1.0},
    {"celsius", 1.0},
    {"fahrenheit", 1.8}
};

int main() {
    char input[50];
    char unit1[20], unit2[20];
    float value, result;
    int i, j;

    printf("Welcome to the Unit Converter!\n\n");
    printf("Enter the value you want to convert: ");
    scanf("%s", input);
    printf("Enter the unit of the value: ");
    scanf("%s", unit1);

    result = 0;
    for (i = 0; i < sizeof(units)/sizeof(units[0]); i++) {
        if (strcmp(units[i].name, unit1) == 0) {
            result = value;
            break;
        }
    }

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit2);

    for (j = 0; j < sizeof(units)/sizeof(units[0]); j++) {
        if (strcmp(units[j].name, unit2) == 0) {
            if (strcmp(unit1, unit2) == 0) {
                printf("The value is already in the desired unit.\n");
            } else {
                printf("The converted value is: %f %s\n", result*units[j].factor, units[j].name);
            }
            break;
        }
    }

    return 0;
}