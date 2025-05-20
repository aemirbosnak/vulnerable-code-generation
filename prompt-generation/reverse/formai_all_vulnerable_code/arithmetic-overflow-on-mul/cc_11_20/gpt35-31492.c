//FormAI DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>

int main() {
    int fromUnit, toUnit, value;

    printf("Enter the unit to convert from (1 for meter, 2 for foot, 3 for inch): ");
    scanf("%d", &fromUnit);

    printf("Enter the unit to convert to (1 for meter, 2 for foot, 3 for inch): ");
    scanf("%d", &toUnit);

    printf("Enter the value to convert: ");
    scanf("%d", &value);

    float convertedValue;

    switch(fromUnit) {
        case 1:
            // Convert from meter
            switch(toUnit) {
                case 1:
                    convertedValue = value; // Meter to meter
                    break;
                case 2:
                    convertedValue = value * 3.28084; // Meter to foot
                    break;
                case 3:
                    convertedValue = value * 39.3701; // Meter to inch
                    break;
                default:
                    printf("Invalid unit to convert to\n");
                    return 0;
            }
            break;
        case 2:
            // Convert from foot
            switch(toUnit) {
                case 1:
                    convertedValue = value / 3.28084; // Foot to meter
                    break;
                case 2:
                    convertedValue = value; // Foot to foot
                    break;
                case 3:
                    convertedValue = value * 12; // Foot to inch
                    break;
                default:
                    printf("Invalid unit to convert to\n");
                    return 0;
            }
            break;
        case 3:
            // Convert from inch
            switch(toUnit) {
                case 1:
                    convertedValue = value / 39.3701; // Inch to meter
                    break;
                case 2:
                    convertedValue = value / 12; // Inch to foot
                    break;
                case 3:
                    convertedValue = value; // Inch to inch
                    break;
                default:
                    printf("Invalid unit to convert to\n");
                    return 0;
            }
            break;
        default:
            printf("Invalid unit to convert from\n");
            return 0;
    }

    printf("%d converted from unit %d to unit %d is %.2f\n", value, fromUnit, toUnit, convertedValue);

    return 0;
}