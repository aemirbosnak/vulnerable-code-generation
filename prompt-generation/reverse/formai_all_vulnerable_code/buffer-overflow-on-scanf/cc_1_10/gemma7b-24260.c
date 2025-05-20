//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void unit_converter(int choice)
{
    float value;
    switch (choice)
    {
        case 1:
            printf("Enter the value to convert: ");
            scanf("%f", &value);
            printf("The converted value is: %.2f kilograms", value * 1000);
            break;
        case 2:
            printf("Enter the value to convert: ");
            scanf("%f", &value);
            printf("The converted value is: %.2f grams", value * 1000);
            break;
        case 3:
            printf("Enter the value to convert: ");
            scanf("%f", &value);
            printf("The converted value is: %.2f cubic meters", value * 1000);
            break;
        case 4:
            printf("Enter the value to convert: ");
            scanf("%f", &value);
            printf("The converted value is: %.2f liters", value * 1000);
            break;
        default:
            printf("Invalid choice");
            break;
    }
}

int main()
{
    int choice;

    printf("Select an option:\n");
    printf("1. Convert kilograms to grams\n");
    printf("2. Convert grams to kilograms\n");
    printf("3. Convert cubic meters to liters\n");
    printf("4. Convert liters to cubic meters\n");

    scanf("%d", &choice);

    unit_converter(choice);

    return 0;
}