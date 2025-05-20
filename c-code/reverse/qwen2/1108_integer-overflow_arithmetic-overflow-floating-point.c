#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

float convertLength(float value, char fromUnit, char toUnit) {
    float result = 0.0;
    switch(fromUnit) {
        case 'm':
            switch(toUnit) {
                case 'm': result = value; break;
                case 'km': result = value / 1000.0; break;
                case 'mi': result = value * 0.000621371; break;
                default: printf("Invalid conversion\n"); return -1;
            }
            break;
        case 'km':
            switch(toUnit) {
                case 'm': result = value * 1000.0; break;
                case 'km': result = value; break;
                case 'mi': result = value * 0.621371; break;
                default: printf("Invalid conversion\n"); return -1;
            }
            break;
        case 'mi':
            switch(toUnit) {
                case 'm': result = value / 0.000621371; break;
                case 'km': result = value / 0.621371; break;
                case 'mi': result = value; break;
                default: printf("Invalid conversion\n"); return -1;
            }
            break;
        default: printf("Invalid unit\n"); return -1;
    }
    return result;
}

int main() {
    float value;
    char fromUnit, toUnit;
    printf("Enter value: ");
    scanf("%f", &value);
    printf("Enter from unit (m/km/mi): ");
    scanf(" %c", &fromUnit);
    printf("Enter to unit (m/km/mi): ");
    scanf(" %c", &toUnit);

    float convertedValue = convertLength(value, fromUnit, toUnit);
    if(convertedValue != -1) {
        printf("%.2f %c is %.2f %c\n", value, fromUnit, convertedValue, toUnit);
    }

    return 0;
}
