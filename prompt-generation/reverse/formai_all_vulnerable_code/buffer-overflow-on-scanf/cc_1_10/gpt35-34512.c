//FormAI DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * This is a secure C Unit Converter program that supports the 
 * conversion of different units including length, speed, temperature,
 * weight/mass, and volume. 
 */ 

// Convert length units
double convertLength(char fromUnit[], char toUnit[], double value) {
    if (strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "km") == 0) {
        return value / 1000;
    } else if (strcmp(fromUnit, "km") == 0 && strcmp(toUnit, "m") == 0) {
        return value * 1000;
    } else if (strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "in") == 0) {
        return value / 2.54;
    } else if (strcmp(fromUnit, "in") == 0 && strcmp(toUnit, "cm") == 0) {
        return value * 2.54;
    } else {
        printf("Invalid conversion! \n");
        return 0;
    }
}

// Convert speed units
double convertSpeed(char fromUnit[], char toUnit[], double value) {
    if (strcmp(fromUnit, "km/h") == 0 && strcmp(toUnit, "mph") == 0) {
        return value / 1.609344;
    } else if (strcmp(fromUnit, "mph") == 0 && strcmp(toUnit, "km/h") == 0) {
        return value * 1.609344;
    } else {
        printf("Invalid conversion! \n");
        return 0;
    }
}

// Convert temperature units
double convertTemperature(char fromUnit[], char toUnit[], double value) {
    double convertedValue;
    if (strcmp(fromUnit, "C") == 0 && strcmp(toUnit, "F") == 0) {
        convertedValue = (value * (9.0 / 5.0)) + 32;
    } else if (strcmp(fromUnit, "F") == 0 && strcmp(toUnit, "C") == 0) {
        convertedValue = (value - 32) * (5.0 / 9.0);
    } else {
        printf("Invalid conversion! \n");
        return 0;
    }
    return convertedValue;
}

// Convert weight/mass units
double convertWeight(char fromUnit[], char toUnit[], double value) {
    if (strcmp(fromUnit, "kg") == 0 && strcmp(toUnit, "lbs") == 0) {
        return value * 2.20462;
    } else if (strcmp(fromUnit, "lbs") == 0 && strcmp(toUnit, "kg") == 0) {
        return value / 2.20462;
    } else {
        printf("Invalid conversion! \n");
        return 0;
    }
}

// Convert volume units
double convertVolume(char fromUnit[], char toUnit[], double value) {
    if (strcmp(fromUnit, "l") == 0 && strcmp(toUnit, "gal") == 0) {
        return value * 0.264172;
    } else if (strcmp(fromUnit, "gal") == 0 && strcmp(toUnit, "l") == 0) {
        return value / 0.264172;
    } else {
        printf("Invalid conversion! \n");
        return 0;
    }
}

// Main function
int main() {
    char unitType, fromUnit[10], toUnit[10];
    double value, convertedValue;
    
    // Prompt user for input
    printf("Choose a unit type to convert (length, speed, temperature, weight/mass, volume): ");
    scanf("%s", &unitType);
    unitType = tolower(unitType);

    // Perform conversion based on unit type
    switch(unitType) {
        case 'l':
            printf("Enter value: ");
            scanf("%lf", &value);
            printf("Enter unit to convert from (m, km, cm, in): ");
            scanf("%s", &fromUnit);
            printf("Enter unit to convert to (m, km, cm, in): ");
            scanf("%s", &toUnit);

            convertedValue = convertLength(fromUnit, toUnit, value);
            if (convertedValue != 0) {
                printf("%.2lf %s = %.2lf %s \n", value, fromUnit, convertedValue, toUnit);
            }
            break;
        case 's':
            printf("Enter value: ");
            scanf("%lf", &value);
            printf("Enter unit to convert from (km/h, mph): ");
            scanf("%s", &fromUnit);
            printf("Enter unit to convert to (km/h, mph): ");
            scanf("%s", &toUnit);

            convertedValue = convertSpeed(fromUnit, toUnit, value);
            if (convertedValue != 0) {
                printf("%.2lf %s = %.2lf %s \n", value, fromUnit, convertedValue, toUnit);
            }
            break;
        case 't':
            printf("Enter value: ");
            scanf("%lf", &value);
            printf("Enter unit to convert from (C, F): ");
            scanf("%s", &fromUnit);
            printf("Enter unit to convert to (C, F): ");
            scanf("%s", &toUnit);

            convertedValue = convertTemperature(fromUnit, toUnit, value);
            if (convertedValue != 0) {
                printf("%.2lf %s = %.2lf %s \n", value, fromUnit, convertedValue, toUnit);
            }
            break;
        case 'w':
            printf("Enter value: ");
            scanf("%lf", &value);
            printf("Enter unit to convert from (kg, lbs): ");
            scanf("%s", &fromUnit);
            printf("Enter unit to convert to (kg, lbs): ");
            scanf("%s", &toUnit);

            convertedValue = convertWeight(fromUnit, toUnit, value);
            if (convertedValue != 0) {
                printf("%.2lf %s = %.2lf %s \n", value, fromUnit, convertedValue, toUnit);
            }
            break;
        case 'v':
            printf("Enter value: ");
            scanf("%lf", &value);
            printf("Enter unit to convert from (l, gal): ");
            scanf("%s", &fromUnit);
            printf("Enter unit to convert to (l, gal): ");
            scanf("%s", &toUnit);

            convertedValue = convertVolume(fromUnit, toUnit, value);
            if (convertedValue != 0) {
                printf("%.2lf %s = %.2lf %s \n", value, fromUnit, convertedValue, toUnit);
            }
            break;
        default:
            printf("Invalid input! \n");
            break;
    }

    return 0;
}