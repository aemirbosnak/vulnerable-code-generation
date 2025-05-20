//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <math.h>

void main()
{
    float fC, fK, fF;
    char cUnit, cTargetUnit;

    printf("Welcome to the Last Unit Converter!\n");

    // Get the current unit
    printf("What is the current unit of the value? (C/K/F): ");
    scanf("%c", &cUnit);

    // Get the value
    printf("Enter the value: ");
    scanf("%f", &fC);

    // Convert the value
    switch (cUnit)
    {
        case 'C':
            fK = fC * 1.8 + 273.15;
            fF = (fC * 1.8 + 273.15) * 1.8 + 32.0;
            break;
        case 'K':
            fC = (fK - 273.15) * 5/9;
            fF = (fK - 273.15) * 1.8 + 32.0;
            break;
        case 'F':
            fC = (fF - 32.0) * 5/9 - 273.15;
            fK = (fF - 32.0) * 1.8 + 273.15;
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    // Get the target unit
    printf("What is the target unit of the converted value? (C/K/F): ");
    scanf("%c", &cTargetUnit);

    // Convert the value to the target unit
    switch (cTargetUnit)
    {
        case 'C':
            fK = fC * 1.8 + 273.15;
            fF = (fC * 1.8 + 273.15) * 1.8 + 32.0;
            break;
        case 'K':
            fC = (fK - 273.15) * 5/9;
            fF = (fK - 273.15) * 1.8 + 32.0;
            break;
        case 'F':
            fC = (fF - 32.0) * 5/9 - 273.15;
            fK = (fF - 32.0) * 1.8 + 273.15;
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    // Print the converted value
    printf("The converted value is: %.2f %s.\n", fC, cTargetUnit);

    return;
}