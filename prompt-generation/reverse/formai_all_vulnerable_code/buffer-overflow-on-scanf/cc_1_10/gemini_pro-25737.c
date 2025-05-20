//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    RADS,
    REM,
    SIEVERTS,
    MICROSV,
} RadioactiveUnit;

static const char *labels[] = {
    "rads",
    "rem",
    "sieverts",
    "μSv",
};

double convert_radioactive(double value, RadioactiveUnit from, RadioactiveUnit to) {
    const double factors[] = {
        1.0,
        0.01,
        0.01,
        1000.0,
    };
    return value * factors[from] / factors[to];
}

int main(void) {
    printf("Welcome to the Post-Apocalyptic Unit Converter 666\n");
    printf("----------------------------------------------------\n");
    printf("Available radioactive units:\n");
    for (int i = 0; i < 4; i++) {
        printf("    %d: %s\n", i, labels[i]);
    }

    int from, to;
    double value;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf("%d", &from);

    printf("Enter the unit to convert to: ");
    scanf("%d", &to);

    double result = convert_radioactive(value, from, to);
    printf("Converted value: %f %s\n", result, labels[to]);

    return 0;
}