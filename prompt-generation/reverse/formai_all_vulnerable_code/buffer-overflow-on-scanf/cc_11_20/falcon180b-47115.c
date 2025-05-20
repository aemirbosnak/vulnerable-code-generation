//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>

int main() {
    int choice;
    float value, result;
    char unit[20];

    printf("Enter the unit you want to convert from:\n");
    scanf("%s", unit);

    printf("What is the value you want to convert?\n");
    scanf("%f", &value);

    printf("Enter the unit you want to convert to:\n");
    scanf("%s", unit);

    switch(choice) {
        case 1: // length conversion
            switch(unit[0]) {
                case'm':
                    result = value * 3.28084;
                    printf("%f meters is equal to %f feet.\n", value, result);
                    break;
                case 'f':
                    result = value * 0.3048;
                    printf("%f feet is equal to %f meters.\n", value, result);
                    break;
                case 'c':
                    result = value * 1.09361;
                    printf("%f meters is equal to %f yards.\n", value, result);
                    break;
                case 'y':
                    result = value * 1.09361 * 3;
                    printf("%f meters is equal to %f yards.\n", value, result);
                    break;
                default:
                    printf("Invalid unit of measurement.\n");
                    break;
            }
            break;
        case 2: // weight conversion
            switch(unit[0]) {
                case 'k':
                    result = value * 2.20462;
                    printf("%f kilograms is equal to %f pounds.\n", value, result);
                    break;
                case 'p':
                    result = value * 0.453592;
                    printf("%f pounds is equal to %f kilograms.\n", value, result);
                    break;
                case 'o':
                    result = value * 0.035274;
                    printf("%f ounces is equal to %f kilograms.\n", value, result);
                    break;
                default:
                    printf("Invalid unit of measurement.\n");
                    break;
            }
            break;
        case 3: // temperature conversion
            switch(unit[0]) {
                case 'c':
                    result = value * 1.8 + 32;
                    printf("%f degrees Celsius is equal to %f degrees Fahrenheit.\n", value, result);
                    break;
                case 'f':
                    result = (value - 32) / 1.8;
                    printf("%f degrees Fahrenheit is equal to %f degrees Celsius.\n", value, result);
                    break;
                default:
                    printf("Invalid unit of measurement.\n");
                    break;
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}