//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char name[20];
    float conversion_factor;
} Unit;

Unit units[] = {
    {"Miles", 1609.34},
    {"Kilometers", 0.001},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Degrees Fahrenheit", 1.8},
    {"Degrees Celsius", 1}
};

int num_units = sizeof(units) / sizeof(units[0]);

void print_menu() {
    int i;
    printf("\n------------------- UNIT CONVERTER -------------------\n");
    printf("| Available Units  | Conversion Factor |\n");
    for (i = 0; i < num_units; i++) {
        printf("| %-14s        | %8.5f        |\n", units[i].name, units[i].conversion_factor);
    }
    printf("-----------------------------------------------------\n");
}

int get_user_input() {
    int i, choice;
    float value, converted_value;

    print_menu();

    printf("\nEnter the index of the source unit: ");
    scanf("%d", &choice);

    printf("Enter the value you want to convert: ");
    scanf("%f", &value);

    printf("\nEnter the index of the target unit: ");
    scanf("%d", &choice);

    if (choice >= 0 && choice < num_units) {
        converted_value = value * units[choice].conversion_factor;
        printf("\n%0.2f %s is equal to %0.2f %s\n", value, units[choice - num_units].name, converted_value, units[choice].name);
    } else {
        printf("Invalid choice. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

int main() {
    get_user_input();
    return 0;
}