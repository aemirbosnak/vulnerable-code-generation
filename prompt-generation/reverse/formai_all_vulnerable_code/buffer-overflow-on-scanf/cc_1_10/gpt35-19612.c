//FormAI DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>

/* convert length units */
float convert_length(float value, char from_unit, char to_unit) {
    float result = value;
    
    /* convert from units to meters */
    switch (from_unit) {
        /* inches to meters */
        case 'i':
            result *= 0.0254;
            break;
        /* feet to meters */
        case 'f':
            result *= 0.3048;
            break;
        /* yards to meters */
        case 'y':
            result *= 0.9144;
            break;
        /* miles to meters */
        case 'm':
            result *= 1609.34;
            break;
        /* meters - do nothing */
        case 'M':
            break;
        /* unrecognized unit - return same value */
        default:
            printf("Error: unrecognized unit '%c'\n", from_unit);
            return value;
    }
    
    /* convert from meters to desired units */
    switch (to_unit) {
        /* inches from meters */
        case 'i':
            result *= 39.3701;
            break;
        /* feet from meters */
        case 'f':
            result *= 3.28084;
            break;
        /* yards from meters */
        case 'y':
            result *= 1.09361;
            break;
        /* miles from meters */
        case 'm':
            result /= 1609.34;
            break;
        /* meters - do nothing */
        case 'M':
            break;
        /* unrecognized unit - return converted value */
        default:
            printf("Error: unrecognized unit '%c'\n", to_unit);
    }
    
    return result;
}

/* convert temperature units */
float convert_temperature(float value, char from_unit, char to_unit) {
    float result = value;
    
    /* convert from units to celsius */
    switch (from_unit) {
        /* fahrenheit to celsius */
        case 'f':
            result = (value - 32) * (5.0/9.0);
            break;
        /* kelvin to celsius */
        case 'k':
            result = value - 273.15;
            break;
        /* celsius - do nothing */
        case 'c':
            break;
        /* unrecognized unit - return same value */
        default:
            printf("Error: unrecognized unit '%c'\n", from_unit);
            return value;
    }
    
    /* convert from celsius to desired units */
    switch (to_unit) {
        /* fahrenheit from celsius */
        case 'f':
            result = (result * (9.0/5.0)) + 32;
            break;
        /* kelvin from celsius */
        case 'k':
            result += 273.15;
            break;
        /* celsius - do nothing */
        case 'c':
            break;
        /* unrecognized unit - return converted value */
        default:
            printf("Error: unrecognized unit '%c'\n", to_unit);
    }
    
    return result;
}

int main() {
    float value;
    char from_unit, to_unit, option;
    
    printf("Welcome to the Unit Converter!\n");
    do {
        /* display menu */
        printf("\nWhat would you like to convert?\n");
        printf("1. Length\n");
        printf("2. Temperature\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf(" %c", &option);
        
        switch (option) {
            case '1':
                /* length conversion */
                printf("\nEnter the value to convert: ");
                scanf("%f", &value);
                printf("Enter the unit to convert from (i, f, y, m, M): ");
                scanf(" %c", &from_unit);
                printf("Enter the unit to convert to (i, f, y, m, M): ");
                scanf(" %c", &to_unit);
                
                printf("%.2f %c = %.2f %c\n", value, from_unit, convert_length(value, from_unit, to_unit), to_unit);
                break;
            case '2':
                /* temperature conversion */
                printf("\nEnter the value to convert: ");
                scanf("%f", &value);
                printf("Enter the unit to convert from (c, f, k): ");
                scanf(" %c", &from_unit);
                printf("Enter the unit to convert to (c, f, k): ");
                scanf(" %c", &to_unit);
                
                printf("%.2f %c = %.2f %c\n", value, from_unit, convert_temperature(value, from_unit, to_unit), to_unit);
                break;
            case '3':
                /* exit program */
                break;
            default:
                /* invalid input */
                printf("Invalid option. Please try again.\n");
        }
    } while (option != '3');
    
    printf("\nThank you for using the Unit Converter!\n");
    
    return 0;
}