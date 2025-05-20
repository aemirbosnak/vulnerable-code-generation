//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char symbol[3];
    double conversion_factor;
} Unit;

Unit units[] = {{"cm", 0.01}, {"m", 1.0}, {"km", 1000.0}, {"mm", 0.001}, {"in", 0.0254}, {"ft", 0.3048}, {"yd", 0.9144}, {"mile", 1609.34}};

int num_units = sizeof(units) / sizeof(Unit);

void print_menu() {
    printf("\nWelcome to the Magical Unit Converter!\n");
    printf("-------------------------------------\n");
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%s : %s\n", units[i].symbol, units[i].symbol);
    }
}

void convert(double value, Unit from, Unit to) {
    double result = value * (to.conversion_factor / from.conversion_factor);
    printf("%.2lf %s is equal to %.2lf %s\n", value, from.symbol, result, to.symbol);
}

bool is_valid_input(char* input) {
    bool valid = true;
    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != ' ' && input[i] != '\0') {
            valid = false;
            break;
        }
    }
    return valid;
}

int main() {
    char input1[50], input2[50], unit1[3], unit2[3];
    double value;
    int index1, index2;

    print_menu();

    printf("Enter the value to convert: ");
    scanf("%s", input1);

    if (!is_valid_input(input1)) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    value = atof(input1);

    printf("Enter the unit of the value: ");
    scanf("%s", unit1);

    for (int i = 0; i < num_units; i++) {
        if (strcasecmp(units[i].symbol, unit1) == 0) {
            index1 = i;
            break;
        }
    }

    if (index1 == num_units) {
        printf("Invalid unit. Please enter a valid unit.\n");
        return 1;
    }

    print_menu();

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit2);

    for (int i = 0; i < num_units; i++) {
        if (strcasecmp(units[i].symbol, unit2) == 0) {
            index2 = i;
            break;
        }
    }

    if (index2 == num_units) {
        printf("Invalid unit. Please enter a valid unit.\n");
        return 1;
    }

    convert(value, units[index1], units[index2]);

    return 0;
}