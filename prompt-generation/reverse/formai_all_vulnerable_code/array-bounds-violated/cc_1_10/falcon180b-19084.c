//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int choice;
    char input[100], output[100];
    Unit units[MAX_UNITS] = {{"meters", 1.0}, {"centimeters", 0.01}, {"millimeters", 0.001}, {"kilometers", 1000.0}, {"inches", 0.0254}, {"feet", 0.3048}, {"yards", 0.9144}, {"miles", 160934.4}, {"pounds", 0.453592}, {"kilograms", 2.20462}};

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("\nSelect a unit to convert from:\n");
        for (int i = 0; i < MAX_UNITS; i++) {
            printf("%d. %s\n", i+1, units[i].name);
        }

        scanf("%d", &choice);

        printf("\nEnter the value to convert: ");
        scanf("%s", input);

        if (strlen(input) == 0) {
            printf("Error: Input cannot be empty.\n");
            continue;
        }

        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                printf("Error: Input must be a number.\n");
                break;
            }
        }

        double value = atof(input);

        printf("\nSelect a unit to convert to:\n");
        for (int i = 0; i < MAX_UNITS; i++) {
            printf("%d. %s\n", i+1, units[i].name);
        }

        scanf("%d", &choice);

        double result = value * units[choice-1].factor;

        printf("\n%s %s is equal to %.2lf %s.\n", input, units[0].name, result, units[choice-1].name);

        printf("\nDo you want to convert another value? (y/n): ");
        char choice2;
        scanf(" %c", &choice2);

        if (choice2 == 'n') {
            break;
        }
    }

    return 0;
}