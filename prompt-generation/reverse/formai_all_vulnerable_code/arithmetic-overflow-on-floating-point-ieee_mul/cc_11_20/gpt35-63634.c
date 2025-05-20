//FormAI DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>

float convertLength(float value, char unit1, char unit2);
float convertTemp(float value, char unit1, char unit2);
float convertWeight(float value, char unit1, char unit2);

int main() {
    char choice, unit1, unit2;
    float value, result;
    
    printf("Welcome to Unit Converter!\n");
    printf("What type of unit conversion do you want to perform?\n");
    printf("1. Length Conversion\n");
    printf("2. Temperature Conversion\n");
    printf("3. Weight Conversion\n");
    printf("\nEnter your choice (1/2/3): ");
    scanf("%c", &choice);
    
    switch(choice) {
        case '1':
            printf("\nEnter the value to be converted: ");
            scanf("%f", &value);
            printf("\nEnter the unit to be converted (m/cm/in/ft): ");
            scanf(" %c", &unit1);
            printf("\nEnter the unit to be converted to (m/cm/in/ft): ");
            scanf(" %c", &unit2);
            result = convertLength(value, unit1, unit2);
            printf("\n%.2f %c is equal to %.2f %c.\n", value, unit1, result, unit2);
            break;
        case '2':
            printf("\nEnter the value to be converted: ");
            scanf("%f", &value);
            printf("\nEnter the unit to be converted (C/F/K): ");
            scanf(" %c", &unit1);
            printf("\nEnter the unit to be converted to (C/F/K): ");
            scanf(" %c", &unit2);
            result = convertTemp(value, unit1, unit2);
            printf("\n%.2f %c is equal to %.2f %c.\n", value, unit1, result, unit2);
            break;
        case '3':
            printf("\nEnter the value to be converted: ");
            scanf("%f", &value);
            printf("\nEnter the unit to be converted (kg/g/lb/oz): ");
            scanf(" %c", &unit1);
            printf("\nEnter the unit to be converted to (kg/g/lb/oz): ");
            scanf(" %c", &unit2);
            result = convertWeight(value, unit1, unit2);
            printf("\n%.2f %c is equal to %.2f %c.\n", value, unit1, result, unit2);
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }
    
    return 0;
}

float convertLength(float value, char unit1, char unit2) {
    switch(unit1) {
        case 'm':
            switch(unit2) {
                case 'm':
                    return value;
                case 'cm':
                    return value * 100;
                case 'in':
                    return value * 39.37;
                case 'ft':
                    return value * 3.28;
                default:
                    return 0;
            }
        case 'cm':
            switch(unit2) {
                case 'm':
                    return value / 100;
                case 'cm':
                    return value;
                case 'in':
                    return value / 2.54;
                case 'ft':
                    return value / 30.48;
                default:
                    return 0;
            }
        case 'in':
            switch(unit2) {
                case 'm':
                    return value / 39.37;
                case 'cm':
                    return value * 2.54;
                case 'in':
                    return value;
                case 'ft':
                    return value / 12;
                default:
                    return 0;
            }
        case 'ft':
            switch(unit2) {
                case 'm':
                    return value / 3.28;
                case 'cm':
                    return value * 30.48;
                case 'in':
                    return value * 12;
                case 'ft':
                    return value;
                default:
                    return 0;
            }
        default:
            return 0;
    }
}

float convertTemp(float value, char unit1, char unit2) {
    float result;
    switch(unit1) {
        case 'C':
            switch(unit2) {
                case 'C':
                    return value;
                case 'F':
                    result = (value * 9/5) + 32;
                    break;
                case 'K':
                    result = value + 273.15;
                    break;
                default:
                    result = 0;
                    break;
            }
            break;
        case 'F':
            switch(unit2) {
                case 'C':
                    result = (value - 32) * 5/9;
                    break;
                case 'F':
                    return value;
                case 'K':
                    result = (value + 459.67) * 5/9;
                    break;
                default:
                    result = 0;
                    break;
            }
            break;
        case 'K':
            switch(unit2) {
                case 'C':
                    result = value - 273.15;
                    break;
                case 'F':
                    result = (value * 9/5) - 459.67;
                    break;
                case 'K':
                    return value;
                default:
                    result = 0;
                    break;
            }
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

float convertWeight(float value, char unit1, char unit2) {
    switch(unit1) {
        case 'kg':
            switch(unit2) {
                case 'kg':
                    return value;
                case 'g':
                    return value * 1000;
                case 'lb':
                    return value * 2.20462;
                case 'oz':
                    return value * 35.274;
                default:
                    return 0;
            }
        case 'g':
            switch(unit2) {
                case 'kg':
                    return value / 1000;
                case 'g':
                    return value;
                case 'lb':
                    return value / 453.592;
                case 'oz':
                    return value / 28.35;
                default:
                    return 0;
            }
        case 'lb':
            switch(unit2) {
                case 'kg':
                    return value / 2.20462;
                case 'g':
                    return value * 453.592;
                case 'lb':
                    return value;
                case 'oz':
                    return value * 16;
                default:
                    return 0;
            }
        case 'oz':
            switch(unit2) {
                case 'kg':
                    return value / 35.274;
                case 'g':
                    return value * 28.35;
                case 'lb':
                    return value / 16;
                case 'oz':
                    return value;
                default:
                    return 0;
            }
        default:
            return 0;
    }
}