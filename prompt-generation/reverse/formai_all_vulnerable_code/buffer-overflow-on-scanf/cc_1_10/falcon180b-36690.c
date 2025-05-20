//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 20
#define MAX_CONVERSION_NAME_LENGTH 50
#define MAX_CONVERSION_FACTOR_LENGTH 20

typedef struct {
    char name[MAX_CONVERSION_NAME_LENGTH];
    char from_unit[MAX_CONVERSION_NAME_LENGTH];
    char to_unit[MAX_CONVERSION_NAME_LENGTH];
    double factor;
} Conversion;

int main() {
    Conversion conversions[MAX_CONVERSIONS];
    int num_conversions = 0;
    int choice;
    char input[MAX_CONVERSION_NAME_LENGTH];
    double value;

    printf("Welcome to the Romantic Unit Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert a unit\n");
    printf("2. Add a conversion\n");
    printf("3. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the unit to convert:\n");
                scanf("%s", input);

                for (int i = 0; i < num_conversions; i++) {
                    if (strcmp(input, conversions[i].from_unit) == 0) {
                        printf("Enter the value to convert:\n");
                        scanf("%lf", &value);
                        printf("The converted value is %.2lf %s\n", value * conversions[i].factor, conversions[i].to_unit);
                    }
                }

                if (num_conversions == 0) {
                    printf("No conversions found.\n");
                }

                break;

            case 2:
                printf("Enter the name of the conversion:\n");
                scanf("%s", input);

                if (num_conversions >= MAX_CONVERSIONS) {
                    printf("Maximum number of conversions reached.\n");
                } else {
                    printf("Enter the units to convert from and to:\n");
                    scanf("%s %s", conversions[num_conversions].from_unit, conversions[num_conversions].to_unit);
                    printf("Enter the conversion factor:\n");
                    scanf("%lf", &conversions[num_conversions].factor);
                    strcpy(conversions[num_conversions].name, input);
                    num_conversions++;
                }

                break;

            case 3:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}