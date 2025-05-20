//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    char input[100];
    char output_unit[10];
    double value;
    int choice;

    Unit units[MAX_UNITS] = {{"meters", 1}, {"centimeters", 0.01}, {"millimeters", 0.001},
                            {"kilometers", 1000}, {"inches", 0.0254}, {"feet", 0.3048},
                            {"yards", 0.9144}, {"miles", 160934.4}, {"pounds", 0.453592},
                            {"ounces", 0.0283495}};

    printf("Welcome to the Unit Converter!\n");
    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf("%s", input);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", output_unit);

    choice = -1;
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input) == 0) {
            choice = i;
            break;
        }
    }

    if (choice == -1) {
        printf("Invalid input unit.\n");
        return 1;
    }

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, output_unit) == 0) {
            printf("%.2lf %s = %.2lf %s\n", value, input, value * units[i].factor, output_unit);
            return 0;
        }
    }

    printf("Invalid output unit.\n");
    return 1;
}