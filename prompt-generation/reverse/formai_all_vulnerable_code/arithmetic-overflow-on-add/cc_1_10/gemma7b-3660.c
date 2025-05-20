//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, num1, num2, unit1, unit2;
    float result;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert meters to kilometers\n");
    printf("2. Convert liters to gallons\n");
    printf("3. Convert kilograms to pounds\n");
    printf("4. Convert degrees Celsius to Fahrenheit\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the number of meters:");
            scanf("%d", &num1);
            unit1 = 1000;
            unit2 = 1;
            result = (num1 * unit1) / unit2;
            printf("The number of kilometers is: %.2f\n", result);
            break;

        case 2:
            printf("Enter the number of liters:");
            scanf("%d", &num1);
            unit1 = 1000;
            unit2 = 4;
            result = (num1 * unit1) / unit2;
            printf("The number of gallons is: %.2f\n", result);
            break;

        case 3:
            printf("Enter the number of kilograms:");
            scanf("%d", &num1);
            unit1 = 1000;
            unit2 = 2.2046;
            result = (num1 * unit1) / unit2;
            printf("The number of pounds is: %.2f\n", result);
            break;

        case 4:
            printf("Enter the number of degrees Celsius:");
            scanf("%d", &num1);
            unit1 = 100;
            unit2 = 1.8;
            result = (num1 * unit1) * unit2 + 32;
            printf("The number of degrees Fahrenheit is: %.2f\n", result);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}