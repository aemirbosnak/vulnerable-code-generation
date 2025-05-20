//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, num1, num2, unit1, unit2;

    printf("Welcome to the Retro Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Metric to Imperial\n");
    printf("2. Imperial to Metric\n");

    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter the number you want to convert:");
        scanf("%d", &num1);
        printf("Enter the unit you want to convert from:");
        scanf("%d", &unit1);
        printf("Enter the unit you want to convert to:");
        scanf("%d", &unit2);

        switch (unit1)
        {
            case 1:
                unit2 = 2;
                break;
            case 2:
                unit2 = 4;
                break;
            case 3:
                unit2 = 5;
                break;
            default:
                printf("Invalid unit selection.\n");
                break;
        }

        num2 = num1 * unit2;
        printf("The converted number is: %d\n", num2);
    }
    else if (choice == 2)
    {
        printf("Enter the number you want to convert:");
        scanf("%d", &num1);
        printf("Enter the unit you want to convert from:");
        scanf("%d", &unit1);
        printf("Enter the unit you want to convert to:");
        scanf("%d", &unit2);

        switch (unit1)
        {
            case 1:
                unit2 = 2;
                break;
            case 2:
                unit2 = 4;
                break;
            case 3:
                unit2 = 5;
                break;
            default:
                printf("Invalid unit selection.\n");
                break;
        }

        num2 = num1 * unit2;
        printf("The converted number is: %d\n", num2);
    }
    else
    {
        printf("Invalid selection.\n");
    }

    return;
}