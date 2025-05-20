//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int choice;
    float num, converted_num;
    char unit, converted_unit;

    // Menu options
    printf("\nPlease select an option:");
    printf("\n1. Convert kilograms to grams\n");
    printf("2. Convert liters to gallons\n");
    printf("3. Convert miles to kilometers\n");
    printf("4. Convert degrees Celsius to Fahrenheit\n");

    scanf("%d", &choice);

    // Unit conversion logic
    switch (choice) {
        case 1:
            printf("Enter the mass in kilograms:");
            scanf("%f", &num);
            converted_num = num * 1000;
            converted_unit = 'g';
            break;
        case 2:
            printf("Enter the volume in liters:");
            scanf("%f", &num);
            converted_num = num * 1000;
            converted_unit = 'ml';
            break;
        case 3:
            printf("Enter the distance in miles:");
            scanf("%f", &num);
            converted_num = num * 1.613;
            converted_unit = 'km';
            break;
        case 4:
            printf("Enter the temperature in degrees Celsius:");
            scanf("%f", &num);
            converted_num = (num * 9/5) + 32;
            converted_unit = 'F';
            break;
        default:
            printf("Invalid selection\n");
            break;
    }

    // Conversion result
    printf("\nThe converted number is: %.2f %s", converted_num, converted_unit);

    return 0;
}