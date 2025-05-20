//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define UNIT_TYPES \
    (UNIT_TYPE_LENGTH | UNIT_TYPE_MASS | UNIT_TYPE_TEMPERATURE | UNIT_TYPE_TIME | UNIT_TYPE_AREA | UNIT_TYPE_VOLUME)

typedef struct unit {
    char name[20];
    double conversion_factor;
} unit_t;

unit_t units[] = {
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"kilogram", 0.0625},
    {"gram", 0.001},
    {"ounce", 0.0283168},
    {"pound", 0.453592},
    {" Celsius", 0.01},
    {"Fahrenheit", 0.017274159},
    {"square mile", 0.0002590861136433},
    {"square foot", 0.09290304},
    {"square inch", 0.0006944444444444444},
    {"cubic mile", 0.000002590861136433},
    {"cubic foot", 0.0002831681136433},
    {"cubic inch", 0.0000069444444444444}
};

int main() {
    int choice;
    double value;
    char unit_input[20];

    printf("Welcome to Unitful Adventurer!\n");

    while (1) {
        printf("Choose a unit to convert: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Enter a value to convert: ");
            scanf("%lf", &value);

            printf("Enter the unit you want to convert to: ");
            fgets(unit_input, 20, stdin);

            for (int i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
                if (strcmp(unit_input, units[i].name) == 0) {
                    value *= units[i].conversion_factor;
                    break;
                }
            }

            printf("The value is now %lf %s\n", value, unit_input);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}