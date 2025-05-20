//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    double conversion_factor;
} Unit;

Unit units[] = {
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"meter", 1.0},
    {"kilometer", 1000.0}
};

int main() {
    int i, j;
    double input, result;
    char from_unit[20], to_unit[20];

    printf("Hello, I am Dr. Watson, Sherlock Holmes' trusted companion.\n");
    printf("Today, I have the pleasure of helping you with a simple unit conversion problem.\n");
    printf("Please input the value you wish to convert and the unit it is currently in.\n");
    printf("Value: ");
    scanf("%lf", &input);
    printf("From unit: ");
    scanf("%s", from_unit);

    for (i = 0; i < 5; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            break;
        }
    }

    printf("From unit %s found. Converting to:\n", from_unit);
    printf("To unit: ");
    scanf("%s", to_unit);

    for (j = 0; j < 5; j++) {
        if (strcmp(to_unit, units[j].name) == 0) {
            result = input * units[i].conversion_factor * units[j].conversion_factor;
            printf("The result is: %.2f %s\n", result, to_unit);
            return 0;
        }
    }

    printf("Invalid to unit %s. Please try again.\n", to_unit);

    return 1;
}