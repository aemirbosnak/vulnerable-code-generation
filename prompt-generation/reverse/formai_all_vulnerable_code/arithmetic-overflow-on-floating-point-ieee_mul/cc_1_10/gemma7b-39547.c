//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void shock_unit_converter(void)
{
    int choice;
    float value, converted_value;

    printf("Prepare for a shock of a lifetime!\n");
    printf("------------------------\n");
    printf("Choose the unit you want to convert:\n");
    printf("1. Kilo to Gram\n");
    printf("2. Liter to Cubic Meter\n");
    printf("3. Pound to Stone\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the weight in kilo:");
            scanf("%f", &value);
            converted_value = value * 1000;
            printf("The converted weight in gram is: %.2f", converted_value);
            break;

        case 2:
            printf("Enter the volume in liter:");
            scanf("%f", &value);
            converted_value = value * 1000;
            printf("The converted volume in cubic meter is: %.2f", converted_value);
            break;

        case 3:
            printf("Enter the weight in pound:");
            scanf("%f", &value);
            converted_value = value * 2.2046;
            printf("The converted weight in stone is: %.2f", converted_value);
            break;

        default:
            printf("Invalid choice. Please try again.");
    }

    printf("\n");
    printf("Thanks for using the shock unit converter. Prepare for another shock!\n");
    system("pause");
}

int main()
{
    shock_unit_converter();

    return 0;
}