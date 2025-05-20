//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 10

void convert_units(int unit_from, int unit_to, double value)
{
    switch (unit_from)
    {
        case 0: // Grams
            switch (unit_to)
            {
                case 0: // Grams
                    printf("The value remains the same: %.2lf grams.\n", value);
                    break;
                case 1: // Centigrams
                    printf("The value is converted to %.2lf Centigrams: %.2lf Centigrams.\n", value * 10, value);
                    break;
                case 2: // Milligrams
                    printf("The value is converted to %.2lf Milligrams: %.2lf Milligrams.\n", value * 1000, value);
                    break;
            }
            break;
        case 1: // Centigrams
            switch (unit_to)
            {
                case 0: // Grams
                    printf("The value is converted to %.2lf Grams: %.2lf grams.\n", value / 10, value);
                    break;
                case 1: // Centigrams
                    printf("The value remains the same: %.2lf Centigrams.\n", value);
                    break;
                case 2: // Milligrams
                    printf("The value is converted to %.2lf Milligrams: %.2lf Milligrams.\n", value * 10, value);
                    break;
            }
            break;
        case 2: // Milligrams
            switch (unit_to)
            {
                case 0: // Grams
                    printf("The value is converted to %.2lf Grams: %.2lf grams.\n", value / 1000, value);
                    break;
                case 1: // Centigrams
                    printf("The value is converted to %.2lf Centigrams: %.2lf Centigrams.\n", value / 10, value);
                    break;
                case 2: // Milligrams
                    printf("The value remains the same: %.2lf Milligrams.\n", value);
                    break;
            }
            break;
    }
}

int main()
{
    int unit_from, unit_to;
    double value;

    printf("Enter the unit you want to convert from: (0 - Grams, 1 - Centigrams, 2 - Milligrams)\n");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: (0 - Grams, 1 - Centigrams, 2 - Milligrams)\n");
    scanf("%d", &unit_to);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    convert_units(unit_from, unit_to, value);

    return 0;
}