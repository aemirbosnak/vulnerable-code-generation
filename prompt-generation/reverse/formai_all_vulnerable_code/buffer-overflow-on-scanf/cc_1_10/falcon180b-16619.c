//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 20
#define MAX_CONVERSIONS 100
#define MAX_CONVERSION_LENGTH 50
#define UNIT_NAME_LENGTH 50
#define CONVERSION_NAME_LENGTH 50

typedef struct {
    char name[UNIT_NAME_LENGTH];
    double conversion;
} Unit;

typedef struct {
    char from[UNIT_NAME_LENGTH];
    char to[UNIT_NAME_LENGTH];
    double conversion;
} Conversion;

int main() {
    Unit units[MAX_UNITS];
    Conversion conversions[MAX_CONVERSIONS];
    int numUnits = 0, numConversions = 0;
    char input[100];
    int choice;
    double value;

    printf("Welcome to the Unit Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Add a unit\n");
    printf("2. Add a conversion\n");
    printf("3. Convert units\n");
    printf("4. Exit\n");

    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the name of the unit: ");
                scanf("%s", units[numUnits].name);
                printf("Enter the conversion factor (e.g. 1.0 for meters): ");
                scanf("%lf", &units[numUnits].conversion);
                numUnits++;
                break;
            case 2:
                printf("Enter the name of the unit to convert from: ");
                scanf("%s", conversions[numConversions].from);
                printf("Enter the name of the unit to convert to: ");
                scanf("%s", conversions[numConversions].to);
                printf("Enter the conversion factor (e.g. 1.0 for meters): ");
                scanf("%lf", &conversions[numConversions].conversion);
                numConversions++;
                break;
            case 3:
                printf("Enter the name of the unit to convert from: ");
                scanf("%s", input);
                printf("Enter the value to convert: ");
                scanf("%lf", &value);
                for (int i = 0; i < numConversions; i++) {
                    if (strcmp(input, conversions[i].from) == 0) {
                        printf("The converted value is: %lf\n", value * conversions[i].conversion);
                        break;
                    }
                }
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}