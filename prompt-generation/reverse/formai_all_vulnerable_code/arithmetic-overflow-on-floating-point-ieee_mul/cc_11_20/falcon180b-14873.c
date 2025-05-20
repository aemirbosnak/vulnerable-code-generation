//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char unit[MAX_UNITS];
    double value;
} Unit;

int main() {
    Unit input, output;
    int num_units, i;
    char choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter the input unit and its value:\n");
    scanf("%s", input.unit);
    scanf("%lf", &input.value);

    printf("Enter the output unit:\n");
    scanf("%c", &choice);

    switch(choice) {
        case'm':
            output.unit[0] ='m';
            output.value = input.value;
            break;
        case 'ft':
            output.unit[0] = 'ft';
            output.value = input.value * 3.28084;
            break;
        case 'in':
            output.unit[0] = 'in';
            output.value = input.value * 39.3701;
            break;
        case 'yd':
            output.unit[0] = 'yd';
            output.value = input.value * 1.09361;
            break;
        case'mi':
            output.unit[0] ='mi';
            output.value = input.value * 0.00062137;
            break;
        case 'kg':
            output.unit[0] = 'kg';
            output.value = input.value * 2.20462;
            break;
        case 'lb':
            output.unit[0] = 'lb';
            output.value = input.value * 0.453592;
            break;
        case 'gal':
            output.unit[0] = 'gal';
            output.value = input.value * 0.264172;
            break;
        case 'l':
            output.unit[0] = 'l';
            output.value = input.value * 3.78541;
            break;
        case 'c':
            output.unit[0] = 'c';
            output.value = (input.value - 32) * 5.0/9.0;
            break;
        default:
            printf("Invalid output unit!\n");
            return 1;
    }

    printf("The converted value is: %s = %.2lf\n", output.unit, output.value);

    return 0;
}