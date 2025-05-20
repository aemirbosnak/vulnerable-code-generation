//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double (*convert)(double);
} unit;

double inch_to_cm(double inch) {
    return inch * 2.54;
}

double cm_to_inch(double cm) {
    return cm / 2.54;
}

double pound_to_kg(double pound) {
    return pound * 0.453592;
}

double kg_to_pound(double kg) {
    return kg / 0.453592;
}

unit units[] = {
    {"inch", inch_to_cm},
    {"cm", cm_to_inch},
    {"pound", pound_to_kg},
    {"kg", kg_to_pound},
};

int main() {
    int i;
    double value;
    char unit_name[20];

    printf("Enter value: ");
    scanf("%lf", &value);

    printf("Enter unit: ");
    scanf("%s", unit_name);

    for (i = 0; i < sizeof(units) / sizeof(unit); i++) {
        if (strcmp(units[i].name, unit_name) == 0) {
            printf("%lf %s = %lf %s\n", value, units[i].name, units[i].convert(value), "inch");
            break;
        }
    }

    if (i == sizeof(units) / sizeof(unit)) {
        printf("Invalid unit\n");
    }

    return 0;
}