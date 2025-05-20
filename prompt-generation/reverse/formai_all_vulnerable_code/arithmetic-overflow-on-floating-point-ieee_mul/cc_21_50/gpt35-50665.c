//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>

float convertTemperature(float temp, char fromUnit, char toUnit);
float convertLength(float length, char fromUnit, char toUnit);
float convertWeight(float weight, char fromUnit, char toUnit);

int main() {
    int choice;
    char fromUnit, toUnit;
    float value, result;
    
    printf("Welcome to the Unit Converter Program\n");
    printf("Select the conversion type:\n1. Temperature\n2. Length\n3. Weight\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the value to convert: ");
            scanf("%f", &value);
            printf("Enter the unit to convert from (C/F/K): ");
            scanf(" %c", &fromUnit);
            printf("Enter the unit to convert to (C/F/K): ");
            scanf(" %c", &toUnit);
            result = convertTemperature(value, fromUnit, toUnit);
            printf("%.2f %c is equal to %.2f %c\n", value, fromUnit, result, toUnit);
            break;
        case 2:
            printf("Enter the value to convert: ");
            scanf("%f", &value);
            printf("Enter the unit to convert from (m/cm/mm/in/ft/mi): ");
            scanf(" %c", &fromUnit);
            printf("Enter the unit to convert to (m/cm/mm/in/ft/mi): ");
            scanf(" %c", &toUnit);
            result = convertLength(value, fromUnit, toUnit);
            printf("%.2f %c is equal to %.2f %c\n", value, fromUnit, result, toUnit);
            break;
        case 3:
            printf("Enter the value to convert: ");
            scanf("%f", &value);
            printf("Enter the unit to convert from (kg/g/lb/oz): ");
            scanf(" %c", &fromUnit);
            printf("Enter the unit to convert to (kg/g/lb/oz): ");
            scanf(" %c", &toUnit);
            result = convertWeight(value, fromUnit, toUnit);
            printf("%.2f %c is equal to %.2f %c\n", value, fromUnit, result, toUnit);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    
    return 0;
}

float convertTemperature(float temp, char fromUnit, char toUnit) {
    float result;
    
    if(fromUnit == toUnit) {
        result = temp;
    } else if(fromUnit == 'C' && toUnit == 'F') {
        result = (temp * 9 / 5) + 32;
    } else if(fromUnit == 'C' && toUnit == 'K') {
        result = temp + 273.15;
    } else if(fromUnit == 'F' && toUnit == 'C') {
        result = (temp - 32) * 5 / 9;
    } else if(fromUnit == 'F' && toUnit == 'K') {
        result = ((temp - 32) * 5 / 9) + 273.15;
    } else if(fromUnit == 'K' && toUnit == 'C') {
        result = temp - 273.15;
    } else if(fromUnit == 'K' && toUnit == 'F') {
        result = ((temp - 273.15) * 9 / 5) + 32;
    } else {
        printf("Invalid conversion\n");
        result = temp;
    }
    
    return result;
}

float convertLength(float length, char fromUnit, char toUnit) {
    float result;
    
    if(fromUnit == toUnit) {
        result = length;
    } else if(fromUnit == 'm' && toUnit == 'cm') {
        result = length * 100;
    } else if(fromUnit == 'm' && toUnit == 'mm') {
        result = length * 1000;
    } else if(fromUnit == 'm' && toUnit == 'in') {
        result = length * 39.3701;
    } else if(fromUnit == 'm' && toUnit == 'ft') {
        result = length * 3.28084;
    } else if(fromUnit == 'm' && toUnit == 'mi') {
        result = length * 0.000621371;
    } else if(fromUnit == 'cm' && toUnit == 'm') {
        result = length / 100;
    } else if(fromUnit == 'cm' && toUnit == 'mm') {
        result = length * 10;
    } else if(fromUnit == 'cm' && toUnit == 'in') {
        result = length * 0.393701;
    } else if(fromUnit == 'cm' && toUnit == 'ft') {
        result = length * 0.0328084;
    } else if(fromUnit == 'cm' && toUnit == 'mi') {
        result = length * 0.00000621371;
    } else if(fromUnit == 'mm' && toUnit == 'm') {
        result = length / 1000;
    } else if(fromUnit == 'mm' && toUnit == 'cm') {
        result = length / 10;
    } else if(fromUnit == 'mm' && toUnit == 'in') {
        result = length * 0.0393701;
    } else if(fromUnit == 'mm' && toUnit == 'ft') {
        result = length * 0.00328084;
    } else if(fromUnit == 'mm' && toUnit == 'mi') {
        result = length * 0.000000621371;
    } else if(fromUnit == 'in' && toUnit == 'm') {
        result = length * 0.0254;
    } else if(fromUnit == 'in' && toUnit == 'cm') {
        result = length * 2.54;
    } else if(fromUnit == 'in' && toUnit == 'mm') {
        result = length * 25.4;
    } else if(fromUnit == 'in' && toUnit == 'ft') {
        result = length * 0.0833333;
    } else if(fromUnit == 'in' && toUnit == 'mi') {
        result = length * 0.0000157828;
    } else if(fromUnit == 'ft' && toUnit == 'm') {
        result = length * 0.3048;
    } else if(fromUnit == 'ft' && toUnit == 'cm') {
        result = length * 30.48;
    } else if(fromUnit == 'ft' && toUnit == 'mm') {
        result = length * 304.8;
    } else if(fromUnit == 'ft' && toUnit == 'in') {
        result = length * 12;
    } else if(fromUnit == 'ft' && toUnit == 'mi') {
        result = length * 0.000189394;
    } else if(fromUnit == 'mi' && toUnit == 'm') {
        result = length * 1609.34;
    } else if(fromUnit == 'mi' && toUnit == 'cm') {
        result = length * 160934;
    } else if(fromUnit == 'mi' && toUnit == 'mm') {
        result = length * 1609344;
    } else if(fromUnit == 'mi' && toUnit == 'in') {
        result = length * 63360;
    } else if(fromUnit == 'mi' && toUnit == 'ft') {
        result = length * 5280;
    } else {
        printf("Invalid conversion\n");
        result = length;
    }
    
    return result;
}

float convertWeight(float weight, char fromUnit, char toUnit) {
    float result;
    
    if(fromUnit == toUnit) {
        result = weight;
    } else if(fromUnit == 'kg' && toUnit == 'g') {
        result = weight * 1000;
    } else if(fromUnit == 'kg' && toUnit == 'lb') {
        result = weight * 2.20462;
    } else if(fromUnit == 'kg' && toUnit == 'oz') {
        result = weight * 35.274;
    } else if(fromUnit == 'g' && toUnit == 'kg') {
        result = weight / 1000;
    } else if(fromUnit == 'g' && toUnit == 'lb') {
        result = weight * 0.00220462;
    } else if(fromUnit == 'g' && toUnit == 'oz') {
        result = weight * 0.035274;
    } else if(fromUnit == 'lb' && toUnit == 'kg') {
        result = weight * 0.453592;
    } else if(fromUnit == 'lb' && toUnit == 'g') {
        result = weight * 453.592;
    } else if(fromUnit == 'lb' && toUnit == 'oz') {
        result = weight * 16;
    } else if(fromUnit == 'oz' && toUnit == 'kg') {
        result = weight * 0.0283495;
    } else if(fromUnit == 'oz' && toUnit == 'g') {
        result = weight * 28.3495;
    } else if(fromUnit == 'oz' && toUnit == 'lb') {
        result = weight * 0.0625;
    } else {
        printf("Invalid conversion\n");
        result = weight;
    }
    
    return result;
}