//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define NUM_UNITS 7

typedef struct {
    char name[10];
    double conversion_factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"Miles", 1609.34},
    {"Kilometers", 0.621371},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Degrees Fahrenheit", 1.8},
    {"Degrees Celsius", 1.0},
    {"Liters", 0.035315}
};

void print_menu() {
    printf("\n*********************************************************\n");
    printf("*                 UNIT CONVERTER                         *\n");
    printf("*                                                       *\n");
    printf("*********************************************************\n");
    printf("\nAvailable Units:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    printf("\nEnter your choice (1-7) or type 'EXIT' to quit: ");
}

void convert_unit() {
    double original_value, converted_value, factor;
    char input_str[MAX_INPUT_SIZE];
    int choice;

    print_menu();
    scanf("%d", &choice);

    if (choice > NUM_UNITS || choice == 0) {
        printf("Invalid choice!\n");
        return;
    }

    printf("Enter the value you want to convert: ");
    scanf("%lf", &original_value);

    if (choice == 7) { // Fahrenheit to Celsius
        converted_value = original_value * units[choice - 1].conversion_factor;
    } else {
        factor = 1 / units[choice - 1].conversion_factor;
        converted_value = original_value * factor;
    }

    printf("\n%lf %s is equal to %lf %s\n", original_value, units[choice - 1].name, converted_value, units[choice - 1 - (choice % 2)].name);
}

int main() {
    int quit = 0;

    while (!quit) {
        convert_unit();
        printf("\nDo you want to continue? (Y/N) ");
        char option;
        scanf("%c", &option);
        if (option == 'N' || option == 'n') {
            quit = 1;
        }
    }

    return 0;
}