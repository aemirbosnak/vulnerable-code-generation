//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void UnitConverter(int);

int main()
{
    int choice;

    printf("Enter your choice:\n");
    printf("1. Convert meters to kilometers\n");
    printf("2. Convert liters to gallons\n");
    printf("3. Convert kilograms to pounds\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            UnitConverter(1);
            break;
        case 2:
            UnitConverter(2);
            break;
        case 3:
            UnitConverter(3);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

void UnitConverter(int type)
{
    float value;

    printf("Enter the value you want to convert:\n");
    scanf("%f", &value);

    switch (type)
    {
        case 1:
            printf("The converted value is: %.2f kilometers\n", value * 1000);
            break;
        case 2:
            printf("The converted value is: %.2f gallons\n", value * 3.785);
            break;
        case 3:
            printf("The converted value is: %.2f pounds\n", value * 2.205);
            break;
    }
}