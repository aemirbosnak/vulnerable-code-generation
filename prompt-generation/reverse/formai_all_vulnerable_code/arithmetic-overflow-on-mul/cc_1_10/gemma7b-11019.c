//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    int choice, num1, num2, unit1, unit2;
    float result;

    system("clear");
    printf("Welcome to the Cyberpunk Unit Converter!\n");
    printf("------------------------\n");

    // Menu options
    printf("1. Metric to Imperial\n");
    printf("2. Imperial to Metric\n");
    printf("Choose an option: ");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the number of units you want to convert: ");
            scanf("%d", &num1);
            printf("Enter the unit you want to convert from: ");
            scanf("%d", &unit1);
            printf("Enter the unit you want to convert to: ");
            scanf("%d", &unit2);

            result = num1 * unit1 * 0.001 * unit2;
            printf("The result is: %.2f", result);
            break;

        case 2:
            printf("Enter the number of units you want to convert: ");
            scanf("%d", &num1);
            printf("Enter the unit you want to convert from: ");
            scanf("%d", &unit1);
            printf("Enter the unit you want to convert to: ");
            scanf("%d", &unit2);

            result = num1 * unit1 * 1000 / unit2;
            printf("The result is: %.2f", result);
            break;

        default:
            printf("Invalid input.\n");
    }

    system("pause");
}