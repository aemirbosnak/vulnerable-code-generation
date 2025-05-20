//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    double number;
    int unit;
    double converted_number;

    printf("Welcome to the OmniConverter!\n");
    printf("Please enter a number: ");
    scanf("%lf", &number);

    printf("Please select a unit to convert from:\n");
    printf("1. Kilograms\n");
    printf("2. Pounds\n");
    printf("3. Grams\n");
    printf("4. Meters\n");
    printf("5. Centimeters\n");
    printf("Please select an option: ");
    scanf("%d", &unit);

    switch (unit)
    {
        case 1:
            converted_number = number * 1000;
            printf("The converted number is: %.2lf kilograms.\n", converted_number);
            break;
        case 2:
            converted_number = number * 2.2046;
            printf("The converted number is: %.2lf pounds.\n", converted_number);
            break;
        case 3:
            converted_number = number * 1000;
            printf("The converted number is: %.2lf grams.\n", converted_number);
            break;
        case 4:
            converted_number = number * 1000;
            printf("The converted number is: %.2lf meters.\n", converted_number);
            break;
        case 5:
            converted_number = number * 100;
            printf("The converted number is: %.2lf centimeters.\n", converted_number);
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}