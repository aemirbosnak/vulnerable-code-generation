//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 100

typedef struct {
    char from_unit[20];
    char to_unit[20];
    double conversion_factor;
} conversion_t;

conversion_t conversions[MAX_CONVERSIONS];
int num_conversions = 0;

void add_conversion(char* from_unit, char* to_unit, double factor) {
    if (num_conversions >= MAX_CONVERSIONS) {
        printf("Error: Maximum number of conversions reached.\n");
        return;
    }

    strcpy(conversions[num_conversions].from_unit, from_unit);
    strcpy(conversions[num_conversions].to_unit, to_unit);
    conversions[num_conversions].conversion_factor = factor;

    num_conversions++;
}

int main() {
    add_conversion("meters", "feet", 3.28084);
    add_conversion("meters", "inches", 39.3701);
    add_conversion("meters", "yards", 1.09361);
    add_conversion("meters", "miles", 0.000621371);

    add_conversion("kilograms", "pounds", 2.20462);
    add_conversion("kilograms", "ounces", 35.274);

    int choice;
    char from_unit[20];
    char to_unit[20];

    printf("Welcome to the Unit Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert length\n");
    printf("2. Convert weight\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    if (choice == 1) {
        printf("Please enter the unit you want to convert from:\n");
        scanf("%s", from_unit);

        printf("Please enter the unit you want to convert to:\n");
        scanf("%s", to_unit);

        int i;
        for (i = 0; i < num_conversions; i++) {
            if (strcmp(conversions[i].from_unit, from_unit) == 0 && strcmp(conversions[i].to_unit, to_unit) == 0) {
                printf("%.2f %s = %.2f %s\n", 1, from_unit, 1, to_unit);
                break;
            }
        }
    } else if (choice == 2) {
        printf("Please enter the unit you want to convert from:\n");
        scanf("%s", from_unit);

        printf("Please enter the unit you want to convert to:\n");
        scanf("%s", to_unit);

        int i;
        for (i = 0; i < num_conversions; i++) {
            if (strcmp(conversions[i].from_unit, from_unit) == 0 && strcmp(conversions[i].to_unit, to_unit) == 0) {
                printf("%.2f %s = %.2f %s\n", 1, from_unit, 1, to_unit);
                break;
            }
        }
    } else {
        printf("Exiting...\n");
    }

    return 0;
}