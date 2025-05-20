//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double value, result;
    char unit[10];
    system("clear"); // clear the console

    printf("Welcome to the Unit Converter!\n");

    printf("\nEnter the value you want to convert: ");
    scanf("%lf", &value);

    printf("\nEnter the unit you want to convert from: ");
    scanf("%s", unit);

    printf("\nChoose the unit you want to convert to:\n");
    printf("1. Meter\n2. Kilometer\n3. Centimeter\n4. Millimeter\n5. Inch\n6. Foot\n7. Yard\n8. Mile\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result = value / 100;
            printf("\n%.2lf %s = %.2lf Meters\n", value, unit, result);
            break;
        case 2:
            result = value / 1000;
            printf("\n%.2lf %s = %.2lf Kilometers\n", value, unit, result);
            break;
        case 3:
            result = value / 100;
            printf("\n%.2lf %s = %.2lf Centimeters\n", value, unit, result);
            break;
        case 4:
            result = value / 10;
            printf("\n%.2lf %s = %.2lf Millimeters\n", value, unit, result);
            break;
        case 5:
            result = value / 0.0254;
            printf("\n%.2lf %s = %.2lf Inches\n", value, unit, result);
            break;
        case 6:
            result = value / 0.3048;
            printf("\n%.2lf %s = %.2lf Feet\n", value, unit, result);
            break;
        case 7:
            result = value / 0.9144;
            printf("\n%.2lf %s = %.2lf Yards\n", value, unit, result);
            break;
        case 8:
            result = value / 1609.34;
            printf("\n%.2lf %s = %.2lf Miles\n", value, unit, result);
            break;
        default:
            printf("\nInvalid choice!");
    }

    return 0;
}