//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void introspective_unit_converter(void)
{
    float value;
    char unit_from, unit_to;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the unit of the value (e.g. kg, g, lb): ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to (e.g. kg, g, lb): ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'k':
            switch (unit_to)
            {
                case 'g':
                    printf("%f kg is equal to %f g.\n", value, value * 1000);
                    break;
                case 'lb':
                    printf("%f kg is equal to %f lb.\n", value, value * 2.20462);
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'k':
                    printf("%f g is equal to %f kg.\n", value, value / 1000);
                    break;
                case 'lb':
                    printf("%f g is equal to %f lb.\n", value, value * 0.00220462);
                    break;
            }
            break;
        case 'lb':
            switch (unit_to)
            {
                case 'k':
                    printf("%f lb is equal to %f kg.\n", value, value * 0.45359);
                    break;
                case 'g':
                    printf("%f lb is equal to %f g.\n", value, value * 2.20462);
                    break;
            }
            break;
    }

    return;
}

int main()
{
    introspective_unit_converter();

    return 0;
}