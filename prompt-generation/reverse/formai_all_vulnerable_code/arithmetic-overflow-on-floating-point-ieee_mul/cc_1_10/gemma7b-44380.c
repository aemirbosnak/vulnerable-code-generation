//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main() {
    int choice;
    float num;
    char unit;

    printf("Enter your choice:\n");
    printf("1. Convert meters to kilometers\n");
    printf("2. Convert liters to gallons\n");
    printf("3. Convert degrees Celsius to Fahrenheit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the number of meters:");
            scanf("%f", &num);
            unit = 'k';
            break;
        case 2:
            printf("Enter the number of liters:");
            scanf("%f", &num);
            unit = 'g';
            break;
        case 3:
            printf("Enter the temperature in Celsius:");
            scanf("%f", &num);
            unit = 'f';
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    switch (unit) {
        case 'k':
            num *= 1000;
            printf("%f kilometers.\n", num);
            break;
        case 'g':
            num *= 16;
            printf("%f gallons.\n", num);
            break;
        case 'f':
            num = (num * 9 / 5) + 32;
            printf("%f Fahrenheit.\n", num);
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    return 0;
}