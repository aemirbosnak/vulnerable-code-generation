//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 20
#define MAX_CONVERSIONS 50

typedef struct {
    char name[50];
    double value;
    char from_unit[10];
    char to_unit[10];
} conversion;

conversion conversions[MAX_CONVERSIONS];
int num_conversions;

void add_conversion() {
    if (num_conversions >= MAX_CONVERSIONS) {
        printf("Error: Maximum number of conversions reached!\n");
        return;
    }

    printf("Enter the name of the conversion: ");
    scanf("%s", conversions[num_conversions].name);

    printf("Enter the value of the conversion: ");
    scanf("%lf", &conversions[num_conversions].value);

    printf("Enter the unit to convert from: ");
    scanf("%s", conversions[num_conversions].from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", conversions[num_conversions].to_unit);

    num_conversions++;
}

void print_conversions() {
    printf("\nList of conversions:\n");
    for (int i = 0; i < num_conversions; i++) {
        printf("%s - %s = %.2lf %s\n", conversions[i].name, conversions[i].from_unit, conversions[i].value, conversions[i].to_unit);
    }
}

void convert_unit() {
    printf("\nEnter the unit to convert from: ");
    char from_unit[10];
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    char to_unit[10];
    scanf("%s", to_unit);

    for (int i = 0; i < num_conversions; i++) {
        if (strcmp(from_unit, conversions[i].from_unit) == 0 && strcmp(to_unit, conversions[i].to_unit) == 0) {
            printf("%.2lf %s = %.2lf %s\n", conversions[i].value, from_unit, conversions[i].value, to_unit);
            return;
        }
    }

    printf("No conversion found.\n");
}

int main() {
    printf("\n\nWelcome to the Unit Converter!\n");

    printf("\nEnter 1 to add a conversion.\nEnter 2 to print the list of conversions.\nEnter 3 to convert a unit.\nEnter 0 to exit.\n");

    int choice;
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_conversion();
                break;
            case 2:
                print_conversions();
                break;
            case 3:
                convert_unit();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}