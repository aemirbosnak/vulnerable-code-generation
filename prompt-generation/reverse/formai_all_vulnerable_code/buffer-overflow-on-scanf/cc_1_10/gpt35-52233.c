//FormAI DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>

int main() {
    float num, result;
    char unit, to_unit;
    
    printf("Welcome to the Temperature Unit Converter!\n");
    printf("Enter the temperature value: ");
    scanf("%f", &num);
    printf("Enter the temperature unit (C/F/K): ");
    scanf(" %c", &unit);
    printf("What temperature unit do you want to convert to (C/F/K): ");
    scanf(" %c", &to_unit);
    
    switch (unit) {
        case 'C':
            if (to_unit == 'F') {
                // Conversion formula from Celsius to Fahrenheit
                result = num * 9 / 5 + 32;
            } else if (to_unit == 'K') {
                // Conversion formula from Celsius to Kelvin
                result = num + 273.15;
            } else {
                // Same unit, no conversion needed
                result = num;
            }
            break;
        case 'F':
            if (to_unit == 'C') {
                // Conversion formula from Fahrenheit to Celsius
                result = (num - 32) * 5 / 9;
            } else if (to_unit == 'K') {
                // Conversion formula from Fahrenheit to Kelvin
                result = (num - 32) * 5 / 9 + 273.15;
            } else {
                // Same unit, no conversion needed
                result = num;
            }
            break;
        case 'K':
            if (to_unit == 'C') {
                // Conversion formula from Kelvin to Celsius
                result = num - 273.15;
            } else if (to_unit == 'F') {
                // Conversion formula from Kelvin to Fahrenheit
                result = (num - 273.15) * 9 / 5 + 32;
            } else {
                // Same unit, no conversion needed
                result = num;
            }
            break;
        default:
            printf("Invalid unit!\n");
            return 1;
    }
    
    printf("%.2f %c is equal to %.2f %c\n", num, unit, result, to_unit);
    return 0;
}