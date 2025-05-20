//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct unit {
    char *name;
    double factor;
};

struct unit *get_unit(const char *name) {
    static struct unit units[] = {
        { "m", 1.0 },
        { "km", 1000.0 },
        { "cm", 0.01 },
        { "mm", 0.001 },
        { "in", 0.0254 },
        { "ft", 0.3048 },
        { "yd", 0.9144 },
        { "mi", 160934.4 },
        { "kg", 1.0 },
        { "g", 0.001 },
        { "lb", 0.453592 },
        { "oz", 0.0283495 },
        { "l", 1.0 },
        { "ml", 0.001 },
        { "gal", 3.78541 },
        { "floz", 0.00378541 },
        { NULL, 0.0 }
    };

    for (int i = 0; units[i].name!= NULL; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return &units[i];
        }
    }
    return NULL;
}

int main() {
    struct unit *from = NULL, *to = NULL;
    double value, result;

    printf("Enter the unit to convert from: ");
    scanf("%s", from->name);

    printf("Enter the unit to convert to: ");
    scanf("%s", to->name);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    result = value * from->factor / to->factor;

    printf("%.2lf %s = %.2lf %s\n", value, from->name, result, to->name);

    return 0;
}