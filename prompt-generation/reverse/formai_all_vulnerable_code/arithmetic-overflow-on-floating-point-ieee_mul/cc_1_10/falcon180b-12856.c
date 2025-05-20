//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input[100];
    char *endptr;
    double value, converted_value;
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the value you want to convert:\n");
    fgets(input, 100, stdin);
    value = strtod(input, &endptr);

    printf("Please select the unit you want to convert from:\n");
    printf("1. Kilometers\n2. Meters\n3. Centimeters\n4. Millimeters\n5. Feet\n6. Inches\n7. Yards\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            converted_value = value / 1000;
            printf("%.2lf kilometers is %.2lf meters.\n", value, converted_value);
            break;
        case 2:
            converted_value = value / 100;
            printf("%.2lf meters is %.2lf centimeters.\n", value, converted_value);
            break;
        case 3:
            converted_value = value / 10;
            printf("%.2lf centimeters is %.2lf millimeters.\n", value, converted_value);
            break;
        case 4:
            converted_value = value * 25.4;
            printf("%.2lf millimeters is %.2lf inches.\n", value, converted_value);
            break;
        case 5:
            converted_value = value * 2.54;
            printf("%.2lf inches is %.2lf centimeters.\n", value, converted_value);
            break;
        case 6:
            converted_value = value * 2.54;
            printf("%.2lf inches is %.2lf millimeters.\n", value, converted_value);
            break;
        case 7:
            converted_value = value * 0.9144;
            printf("%.2lf inches is %.2lf yards.\n", value, converted_value);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}