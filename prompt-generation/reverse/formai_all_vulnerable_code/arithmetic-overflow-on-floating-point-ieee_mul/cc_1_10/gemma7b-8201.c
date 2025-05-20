//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main() {
    int choice;
    float value;
    char unit;

    printf("Enter your choice:\n");
    printf("1. Convert meters to kilometers\n");
    printf("2. Convert liters to gallons\n");
    printf("3. Convert degrees Celsius to Fahrenheit\n");
    printf("4. Convert pounds to kilograms\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the value in meters:");
            scanf("%f", &value);
            unit = 'k';
            break;
        case 2:
            printf("Enter the value in liters:");
            scanf("%f", &value);
            unit = 'g';
            break;
        case 3:
            printf("Enter the value in degrees Celsius:");
            scanf("%f", &value);
            unit = 'F';
            break;
        case 4:
            printf("Enter the value in pounds:");
            scanf("%f", &value);
            unit = 'kg';
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    switch (unit) {
        case 'k':
            value *= 1000;
            printf("The value in kilometers is: %.2f\n", value);
            break;
        case 'g':
            value *= 1000;
            printf("The value in gallons is: %.2f\n", value);
            break;
        case 'F':
            value = (value - 32) * 5/9;
            printf("The value in Fahrenheit is: %.2f\n", value);
            break;
        case 'kg':
            value *= 2.20462;
            printf("The value in kilograms is: %.2f\n", value);
            break;
        default:
            printf("Invalid unit\n");
            break;
    }

    return 0;
}