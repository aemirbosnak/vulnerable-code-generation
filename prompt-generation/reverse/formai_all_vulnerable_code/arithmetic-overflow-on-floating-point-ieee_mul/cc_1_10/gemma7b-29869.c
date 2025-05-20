//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

void main()
{
    int choice;
    float num, factor, converted_num;

    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert meters to kilometers\n");
    printf("2. Convert liters to gallons\n");
    printf("3. Convert pounds to kilograms\n");
    printf("4. Convert degrees to radians\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the number of meters:");
            scanf("%f", &num);
            factor = 1000;
            converted_num = num * factor;
            printf("The converted number of kilometers is: %.2f\n", converted_num);
            break;

        case 2:
            printf("Enter the number of liters:");
            scanf("%f", &num);
            factor = 1000;
            converted_num = num * factor;
            printf("The converted number of gallons is: %.2f\n", converted_num);
            break;

        case 3:
            printf("Enter the number of pounds:");
            scanf("%f", &num);
            factor = 2.2046;
            converted_num = num * factor;
            printf("The converted number of kilograms is: %.2f\n", converted_num);
            break;

        case 4:
            printf("Enter the number of degrees:");
            scanf("%f", &num);
            factor = M_PI / 180;
            converted_num = num * factor;
            printf("The converted number of radians is: %.2f\n", converted_num);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return;
}