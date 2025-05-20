//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_TO_UNITS 10
#define MAX_FROM_UNITS 10

typedef struct {
    char *name;
    float factor;
} Unit;

Unit units[MAX_UNITS];
int num_units;

void add_unit(char *name, float factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Too many units.\n");
        exit(1);
    }
    units[num_units] = (Unit) {name, factor};
    num_units++;
}

void print_units() {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%s\n", units[i].name);
    }
}

int find_unit(char *name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

float convert(float value, int from_unit, int to_unit) {
    float result = value * units[from_unit].factor;
    for (int i = 0; i < num_units; i++) {
        if (i!= from_unit && i!= to_unit) {
            result /= units[i].factor;
        }
    }
    return result * units[to_unit].factor;
}

int main() {
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("centimeter", 0.01);
    add_unit("millimeter", 0.001);
    add_unit("inch", 0.0254);
    add_unit("foot", 0.3048);
    add_unit("yard", 0.9144);
    add_unit("mile", 160934.4);

    int choice;
    do {
        printf("Enter choice:\n");
        printf("1. Add unit\n");
        printf("2. Convert\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_UNITS];
                float factor;
                printf("Enter unit name: ");
                scanf("%s", name);
                printf("Enter unit factor: ");
                scanf("%f", &factor);
                add_unit(name, factor);
                break;
            }
            case 2: {
                int from_unit, to_unit;
                float value;
                printf("Enter from unit: ");
                scanf("%d", &from_unit);
                printf("Enter to unit: ");
                scanf("%d", &to_unit);
                printf("Enter value: ");
                scanf("%f", &value);
                float result = convert(value, from_unit, to_unit);
                printf("Result: %f\n", result);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while (choice!= 3);

    return 0;
}