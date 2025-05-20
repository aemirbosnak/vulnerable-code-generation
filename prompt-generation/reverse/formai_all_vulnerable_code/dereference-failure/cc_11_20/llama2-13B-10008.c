//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

struct unit {
    char *name;
    double factor;
};

struct conversion {
    char *from_unit;
    char *to_unit;
    double factor;
};

int main(int argc, char *argv[]) {
    // Initialize unit list
    struct unit units[MAX_UNITS] = {
        {"meter", 1.0},
        {"kilometer", 1000.0},
        {"foot", 0.3048},
        {"yard", 0.9144},
        {"mile", 1609.344}
    };

    // Initialize conversion list
    struct conversion conversions[MAX_CONVERTIONS] = {
        {"meter", "foot", 0.3048},
        {"kilometer", "mile", 1.609344},
        {"foot", "yard", 0.9144},
        {"yard", "mile", 0.9144}
    };

    // Handle command-line arguments
    if (argc < 2) {
        printf("Usage: %s <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }

    // Get from unit and to unit from command-line arguments
    char *from_unit = argv[1];
    char *to_unit = argv[2];

    // Find the corresponding unit factors
    struct unit *from_unit_struct = NULL;
    struct unit *to_unit_struct = NULL;
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_unit_struct = &units[i];
            break;
        }
    }
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, to_unit) == 0) {
            to_unit_struct = &units[i];
            break;
        }
    }

    // Check if from unit and to unit are valid
    if (from_unit_struct == NULL || to_unit_struct == NULL) {
        printf("Invalid unit(s)\n");
        return 2;
    }

    // Calculate the conversion factor
    double conversion_factor = from_unit_struct->factor / to_unit_struct->factor;

    // Print the conversion factor
    printf("%.2f\n", conversion_factor);

    // Handle additional conversions
    for (int i = 0; i < MAX_CONVERTIONS; i++) {
        if (strcmp(conversions[i].from_unit, from_unit) == 0 &&
            strcmp(conversions[i].to_unit, to_unit) == 0) {
            conversion_factor = conversions[i].factor;
            break;
        }
    }

    // Print the conversion factor
    printf("%.2f\n", conversion_factor);

    return 0;
}