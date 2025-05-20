//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char name[10];
    double conversion_factor;
} Unit;

Unit units[] = {
    {"Meters", 1.0},
    {"Feet", 0.3048},
    {"Inches", 0.0254},
    {"Centimeters", 0.01},
};

void print_menu() {
    int i;
    printf("\n--- Unit Converter Menu ---\n");
    for (i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    printf("5. Exit\n");
}

int main() {
    int choice, source, target;
    double value;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter value to convert in %s: ", units[choice - 1].name);
        scanf("%lf", &value);

        printf("Convert to:\n");
        print_menu();
        scanf("%d", &target);

        if (target == 5) {
            printf("Exiting the program...\n");
            break;
        }

        if (target < 1 || target > 5) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        double result = value * units[target - 1].conversion_factor / units[choice - 1].conversion_factor;
        printf("%.2lf %s is equal to %.2lf %s\n", value, units[choice - 1].name, result, units[target - 1].name);
    }

    return 0;
}