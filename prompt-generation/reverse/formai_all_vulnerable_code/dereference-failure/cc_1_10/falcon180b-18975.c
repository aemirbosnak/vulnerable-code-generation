//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERTIBLE_UNITS 10

typedef struct {
    char *name;
    double factor;
    int index;
} ConvertibleUnit;

ConvertibleUnit units[MAX_CONVERTIBLE_UNITS];

int main() {
    int choice, i;
    char input[50];

    printf("Welcome to the Unit Converter!\n\n");
    printf("Please enter the base unit you want to convert from: ");
    scanf("%s", input);

    strcpy(units[0].name, input);
    units[0].factor = 1.0;
    units[0].index = 0;

    for (i = 1; i < MAX_CONVERTIBLE_UNITS; i++) {
        printf("Enter a convertible unit (leave blank to stop): ");
        scanf("%s", input);

        if (strcmp(input, "") == 0) {
            break;
        }

        strcpy(units[i].name, input);
        printf("Enter the conversion factor for %s: ", units[i].name);
        scanf("%lf", &units[i].factor);
        units[i].index = i;
    }

    while (1) {
        printf("\nPlease enter the value you want to convert: ");
        scanf("%lf", &choice);

        printf("\nPlease enter the unit you want to convert to: ");
        scanf("%s", input);

        int index = -1;
        for (i = 0; i < MAX_CONVERTIBLE_UNITS; i++) {
            if (strcmp(units[i].name, input) == 0) {
                index = units[i].index;
                break;
            }
        }

        if (index == -1) {
            printf("Invalid unit.\n");
        } else {
            double result = choice * units[index].factor;
            printf("%.2lf %s = %.2lf %s\n", choice, units[0].name, result, input);
        }

        printf("\nDo you want to convert again? (y/n): ");
        char again;
        scanf(" %c", &again);

        if (again!= 'y') {
            break;
        }
    }

    return 0;
}