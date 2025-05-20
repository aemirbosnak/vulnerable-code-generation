//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, i;
    float num, result;
    char unit[10];

    printf("Welcome to the Unit Converter!\n");
    printf("Enter 1 for length conversion\n");
    printf("Enter 2 for weight conversion\n");
    printf("Enter 3 for volume conversion\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the value to convert: ");
            scanf("%f", &num);
            printf("Enter the unit (m, cm, mm, km): ");
            scanf("%s", unit);

            if(strcmp(unit, "m") == 0)
            {
                result = num * 1;
                printf("%f meters is equal to %f kilometers.\n", num, result);
            }
            else if(strcmp(unit, "cm") == 0)
            {
                result = num * 0.01;
                printf("%f centimeters is equal to %f kilometers.\n", num, result);
            }
            else if(strcmp(unit, "mm") == 0)
            {
                result = num * 0.001;
                printf("%f millimeters is equal to %f kilometers.\n", num, result);
            }
            else if(strcmp(unit, "km") == 0)
            {
                result = num / 1;
                printf("%f kilometers is equal to %f meters.\n", num, result);
            }
            else
            {
                printf("Invalid unit.\n");
            }
            break;

        case 2:
            printf("Enter the value to convert: ");
            scanf("%f", &num);
            printf("Enter the unit (kg, g, mg, lb): ");
            scanf("%s", unit);

            if(strcmp(unit, "kg") == 0)
            {
                result = num * 1;
                printf("%f kilograms is equal to %f pounds.\n", num, result);
            }
            else if(strcmp(unit, "g") == 0)
            {
                result = num * 0.001;
                printf("%f grams is equal to %f pounds.\n", num, result);
            }
            else if(strcmp(unit, "mg") == 0)
            {
                result = num * 0.000001;
                printf("%f milligrams is equal to %f pounds.\n", num, result);
            }
            else if(strcmp(unit, "lb") == 0)
            {
                result = num / 1;
                printf("%f pounds is equal to %f kilograms.\n", num, result);
            }
            else
            {
                printf("Invalid unit.\n");
            }
            break;

        case 3:
            printf("Enter the value to convert: ");
            scanf("%f", &num);
            printf("Enter the unit (l, ml, cl, gal): ");
            scanf("%s", unit);

            if(strcmp(unit, "l") == 0)
            {
                result = num * 1;
                printf("%f liters is equal to %f gallons.\n", num, result);
            }
            else if(strcmp(unit, "ml") == 0)
            {
                result = num * 0.000264172;
                printf("%f milliliters is equal to %f gallons.\n", num, result);
            }
            else if(strcmp(unit, "cl") == 0)
            {
                result = num * 0.001;
                printf("%f centiliters is equal to %f gallons.\n", num, result);
            }
            else if(strcmp(unit, "gal") == 0)
            {
                result = num / 1;
                printf("%f gallons is equal to %f liters.\n", num, result);
            }
            else
            {
                printf("Invalid unit.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}