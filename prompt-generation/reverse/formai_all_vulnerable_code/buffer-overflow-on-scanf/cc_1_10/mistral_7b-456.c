//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#define MAX_UNITS 10

typedef struct {
    char name[20];
    double factor;
} Unit;

Unit units[MAX_UNITS] = {
    {"Meter", 1.0},
    {"Kilometer", 1000.0},
    {"Millimeter", 0.001},
    {"Centimeter", 0.01},
    {"Micrometer", 0.000001},
    {"Gram", 1.0},
    {"Kilogram", 1000.0},
    {"Milligram", 0.001},
    {"Pound", 0.453592},
    {"Ounce", 0.035274}
};

void print_menu() {
    int i;
    printf("\nUnit Converter Menu\n");
    for (i = 0; i < MAX_UNITS; i++) {
        printf("%d. %-15s", i + 1, units[i].name);
    }
    printf("\n0. Exit\n");
}

void convert(Unit from, Unit to) {
    double result;
    if (from.factor == 0) {
        printf("Error: Cannot divide by zero\n");
        return;
    }
    result = from.factor * to.factor;
    printf("%.2f %s is equal to %.2f %s\n", from.factor, from.name, result, to.name);
}

int main() {
    int choice, choice1, choice2;
    Unit selected_unit1, selected_unit2;

    print_menu();
    while (1) {
        printf("\nEnter the number of the unit you want to convert from: ");
        scanf("%d", &choice1);
        if (choice1 <= 0 || choice1 > MAX_UNITS) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        selected_unit1 = units[choice1 - 1];

        print_menu();
        printf("Enter the number of the unit you want to convert to: ");
        scanf("%d", &choice2);
        if (choice2 <= 0 || choice2 > MAX_UNITS) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        selected_unit2 = units[choice2 - 1];

        convert(selected_unit1, selected_unit2);

        print_menu();
        printf("Do you want to continue? (1 for yes, any other key for no): ");
        scanf("%d", &choice);
        if (choice != 1) {
            break;
        }
    }

    return 0;
}