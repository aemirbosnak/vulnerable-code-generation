//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int choice, num_units;
    double value, result;
    char unit_name[MAX_UNITS][10];
    Unit units[MAX_UNITS];

    printf("Welcome to the Unit Converter!\n");
    printf("Please select a category:\n");
    printf("1. Length\n2. Weight\n3. Volume\n4. Temperature\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Select up to %d units (enter 'done' when finished):\n", MAX_UNITS);
            num_units = 0;
            while (num_units < MAX_UNITS && scanf("%s", unit_name[num_units])!= EOF) {
                if (strcmp(unit_name[num_units], "done") == 0) {
                    break;
                }
                num_units++;
            }
            break;
        case 2:
            strcpy(unit_name[0], "kg");
            strcpy(unit_name[1], "g");
            strcpy(unit_name[2], "lb");
            strcpy(unit_name[3], "oz");
            num_units = 4;
            break;
        case 3:
            strcpy(unit_name[0], "L");
            strcpy(unit_name[1], "ml");
            strcpy(unit_name[2], "gal");
            strcpy(unit_name[3], "fl oz");
            num_units = 4;
            break;
        case 4:
            strcpy(unit_name[0], "C");
            strcpy(unit_name[1], "F");
            num_units = 2;
            break;
        default:
            printf("Invalid category.\n");
            return 1;
    }

    printf("Enter a value:\n");
    scanf("%lf", &value);

    printf("Enter the input unit:\n");
    scanf("%s", unit_name[0]);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(unit_name[i], unit_name[0]) == 0) {
            result = value;
        } else {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(unit_name[j], unit_name[i]) == 0) {
                    result = value * units[j].factor;
                    break;
                }
            }
        }
        printf("%s = %.2lf %s\n", unit_name[i], result, unit_name[0]);
    }

    return 0;
}