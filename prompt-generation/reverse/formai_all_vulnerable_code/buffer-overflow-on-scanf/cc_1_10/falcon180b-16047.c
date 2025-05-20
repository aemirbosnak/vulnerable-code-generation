//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERSIONS 10

typedef struct {
    char *name;
    double factor;
} Conversion;

int main() {
    char input[100];
    char unit[10];
    int num_conversions = 0;
    Conversion conversions[MAX_CONVERSIONS] = {{0}};

    printf("Welcome to the Unit Converter!\n");

    while (num_conversions < MAX_CONVERSIONS) {
        printf("Enter a conversion name (e.g. meters to feet): ");
        scanf("%s", input);

        if (strlen(input) == 0) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        printf("Enter the conversion factor (e.g. 0.3048): ");
        scanf("%lf", &conversions[num_conversions].factor);

        printf("Enter the unit of measurement (e.g. meters): ");
        scanf("%s", unit);

        strcpy(conversions[num_conversions].name, input);
        num_conversions++;

        printf("Conversion added: %s = %s * %lf\n", conversions[num_conversions - 1].name, unit, conversions[num_conversions - 1].factor);
    }

    printf("\nSelect a conversion:\n");
    for (int i = 0; i < num_conversions; i++) {
        printf("%d. %s\n", i + 1, conversions[i].name);
    }

    int conversion_choice;
    scanf("%d", &conversion_choice);

    printf("Enter the value to convert: ");
    scanf("%lf", &conversions[conversion_choice - 1].factor);

    printf("Enter the unit of measurement: ");
    scanf("%s", unit);

    double result = conversions[conversion_choice - 1].factor * atof(unit);

    printf("\nResult: %.2lf %s = %.2lf %s\n", conversions[conversion_choice - 1].factor, conversions[conversion_choice - 1].name, result, unit);

    return 0;
}