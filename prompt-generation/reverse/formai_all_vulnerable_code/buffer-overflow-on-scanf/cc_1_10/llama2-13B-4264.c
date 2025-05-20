//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct {
    char *name;
    double value;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"cm", 10},
    {"m", 100},
    {"km", 100000},
    {"g", 100},
    {"kg", 100000},
    {"°C", 0},
    {"°F", 0},
    {"h", 0},
    {"min", 0},
    {"s", 0}
};

unit_t *get_unit(char *name) {
    int i;
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(name, units[i].name) == 0) {
            return &units[i];
        }
    }
    return NULL;
}

double convert(unit_t *from, unit_t *to) {
    double factor;
    if (from == NULL || to == NULL) {
        return 0;
    }
    factor = from->value / to->value;
    return factor;
}

void print_convertions(unit_t *from, unit_t *to) {
    if (from == NULL || to == NULL) {
        return;
    }
    printf("%s (%s) = %f %s\n", from->name, to->name, convert(from, to), to->name);
}

int main() {
    int choice;
    double value;
    unit_t *from, *to;

    do {
        printf("Select a unit to convert: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value in centimeters: ");
                scanf("%lf", &value);
                from = get_unit("cm");
                to = get_unit("m");
                print_convertions(from, to);
                break;

            case 2:
                printf("Enter a value in meters: ");
                scanf("%lf", &value);
                from = get_unit("m");
                to = get_unit("km");
                print_convertions(from, to);
                break;

            case 3:
                printf("Enter a value in kilometers: ");
                scanf("%lf", &value);
                from = get_unit("km");
                to = get_unit("cm");
                print_convertions(from, to);
                break;

            case 4:
                printf("Enter a value in grams: ");
                scanf("%lf", &value);
                from = get_unit("g");
                to = get_unit("kg");
                print_convertions(from, to);
                break;

            case 5:
                printf("Enter a value in degrees Celsius: ");
                scanf("%lf", &value);
                from = get_unit("°C");
                to = get_unit("°F");
                print_convertions(from, to);
                break;

            case 6:
                printf("Enter a value in hours: ");
                scanf("%lf", &value);
                from = get_unit("h");
                to = get_unit("min");
                print_convertions(from, to);
                break;

            case 7:
                printf("Enter a value in minutes: ");
                scanf("%lf", &value);
                from = get_unit("min");
                to = get_unit("s");
                print_convertions(from, to);
                break;

            case 8:
                printf("Enter a value in seconds: ");
                scanf("%lf", &value);
                from = get_unit("s");
                to = get_unit("");
                print_convertions(from, to);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    } while (1);

    return 0;
}