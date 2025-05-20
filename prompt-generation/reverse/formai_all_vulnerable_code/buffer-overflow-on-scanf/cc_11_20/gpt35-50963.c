//FormAI DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>

int main() {
    double value;
    char unit_from, unit_to;
    
    printf("Enter a value followed by the unit you want to convert from (C,F,K): ");
    scanf("%lf %c", &value, &unit_from);
    
    printf("Enter the unit you want to convert to (C,F,K): ");
    scanf(" %c", &unit_to);
    
    double result;
    
    if (unit_from == 'C') {
        if (unit_to == 'C') {
            result = value;
        } else if (unit_to == 'F') {
            result = (value * 9/5) + 32;
        } else if (unit_to == 'K') {
            result = value + 273.15;
        } else {
            printf("Unknown unit.");
            return 1;
        }
    } else if (unit_from == 'F') {
        if (unit_to == 'C') {
            result = (value - 32) * 5/9;
        } else if (unit_to == 'F') {
            result = value;
        } else if (unit_to == 'K') {
            result = (value + 459.67) * 5/9;
        } else {
            printf("Unknown unit.");
            return 1;
        }
    } else if (unit_from == 'K') {
        if (unit_to == 'C') {
            result = value - 273.15;
        } else if (unit_to == 'F') {
            result = (value * 9/5) - 459.67;
        } else if (unit_to == 'K') {
            result = value;
        } else {
            printf("Unknown unit.");
            return 1;
        }
    } else {
        printf("Unknown unit.");
        return 1;
    }
    
    printf("%.2f %c = %.2f %c\n", value, unit_from, result, unit_to);
    
    return 0;
}