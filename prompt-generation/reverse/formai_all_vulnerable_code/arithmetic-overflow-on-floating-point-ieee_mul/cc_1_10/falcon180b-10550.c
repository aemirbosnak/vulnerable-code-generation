//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    double factor;
} unit;

unit units[] = {{"meters", 1},
               {"kilometers", 1000},
               {"centimeters", 0.01},
               {"millimeters", 0.001},
               {"inches", 0.0254},
               {"feet", 0.3048},
               {"yards", 0.9144},
               {"miles", 160934.4},
               {"pounds", 0.453592},
               {"kilograms", 2.20462},
               {"ounces", 0.0283495},
               {"tons", 907.185},
               {"liters", 1},
               {"gallons", 3.78541},
               {"quarts", 4},
               {"pints", 8}};

int main() {
    int choice, i;

    printf("Enter the unit to convert from: ");
    scanf("%s", units[0].name);

    printf("Enter the unit to convert to: ");
    scanf("%s", units[0].name);

    for (i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(units[i].name, units[0].name) == 0) {
            printf("Enter the value to convert: ");
            scanf("%lf", &units[i].factor);
            break;
        }
    }

    printf("Enter the value to convert: ");
    scanf("%lf", &units[0].factor);

    printf("%.2lf %s = %.2lf %s\n", units[0].factor, units[0].name, units[0].factor * units[i].factor, units[i].name);

    return 0;
}