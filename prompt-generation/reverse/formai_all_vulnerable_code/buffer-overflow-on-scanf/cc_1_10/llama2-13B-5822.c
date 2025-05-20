//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_UNITS 5
#define MAX_VALUES 5

// Structure to hold unit and value
typedef struct {
    char unit[20];
    double value;
} unit_t;

// Array to store units and values
unit_t units[MAX_UNITS][MAX_VALUES];

// Function to get user input
void get_input(unit_t *unit, double *value) {
    printf("Enter a value for unit %s: ", unit->unit);
    scanf("%lf", value);
}

// Function to convert between units
void convert(unit_t *from, unit_t *to) {
    double value = from->value;

    // Convert between units
    if (strcmp(from->unit, "ft") == 0) {
        if (strcmp(to->unit, "in") == 0) {
            value *= 12;
        } else if (strcmp(to->unit, "yd") == 0) {
            value *= 3;
        }
    } else if (strcmp(from->unit, "in") == 0) {
        if (strcmp(to->unit, "ft") == 0) {
            value /= 12;
        } else if (strcmp(to->unit, "yd") == 0) {
            value /= 3;
        }
    } else if (strcmp(from->unit, "yd") == 0) {
        if (strcmp(to->unit, "ft") == 0) {
            value *= 3;
        } else if (strcmp(to->unit, "in") == 0) {
            value /= 3;
        }
    }

    to->value = value;
}

// Function to print the converted value
void print_result(unit_t *unit) {
    printf("%.2f %s = %c\n", unit->value, unit->unit, unit->unit[0] == 'i' ? 'i' : 'f');
}

int main() {
    // Initialize units and values
    for (int i = 0; i < MAX_UNITS; i++) {
        for (int j = 0; j < MAX_VALUES; j++) {
            units[i][j].unit[0] = '\0';
            units[i][j].value = 0;
        }
    }

    // Ask user for input
    unit_t unit;
    double value;
    get_input(&unit, &value);

    // Convert between units
    for (int i = 0; i < MAX_UNITS; i++) {
        convert(&units[i][0], &units[i][1]);
    }

    // Print the converted value
    for (int i = 0; i < MAX_UNITS; i++) {
        print_result(&units[i][1]);
    }

    return 0;
}