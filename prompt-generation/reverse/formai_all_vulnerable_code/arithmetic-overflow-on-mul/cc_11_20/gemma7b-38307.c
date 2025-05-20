//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main() {
    int num_1, num_2, unit_1, unit_2, factor;
    char unit_symbol_1, unit_symbol_2;

    printf("Enter the number:");
    scanf("%d", &num_1);

    printf("Enter the unit symbol:");
    scanf(" %c", &unit_symbol_1);

    printf("Enter the unit symbol to be converted to:");
    scanf(" %c", &unit_symbol_2);

    switch (unit_symbol_1) {
        case 'kg':
            unit_1 = 1000;
            break;
        case 'g':
            unit_1 = 1000;
            break;
        case 'mg':
            unit_1 = 1000000;
            break;
        case 'L':
            unit_1 = 1000;
            break;
        case 'ml':
            unit_1 = 1000;
            break;
    }

    switch (unit_symbol_2) {
        case 'kg':
            unit_2 = 1000;
            break;
        case 'g':
            unit_2 = 1000;
            break;
        case 'mg':
            unit_2 = 1000000;
            break;
        case 'L':
            unit_2 = 1000;
            break;
        case 'ml':
            unit_2 = 1000;
            break;
    }

    factor = unit_1 * unit_2;
    num_2 = num_1 * factor;

    printf("The converted number is: %d %c", num_2, unit_symbol_2);
}