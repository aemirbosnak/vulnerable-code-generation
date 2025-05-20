//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unit_from, unit_to, value;

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    printf("Enter the value you want to convert: ");
    scanf("%d", &value);

    switch (unit_from)
    {
        case 1:
            switch (unit_to)
            {
                case 2:
                    value *= 2.54;
                    break;
                case 3:
                    value *= 1.613;
                    break;
                case 4:
                    value *= 1.157;
                    break;
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    value *= 0.45359;
                    break;
                case 3:
                    value *= 1.613;
                    break;
                case 4:
                    value *= 1.157;
                    break;
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    value *= 0.625;
                    break;
                case 2:
                    value *= 1.613;
                    break;
                case 4:
                    value *= 1.157;
                    break;
            }
            break;
        case 4:
            switch (unit_to)
            {
                case 1:
                    value *= 0.8989;
                    break;
                case 2:
                    value *= 1.613;
                    break;
                case 3:
                    value *= 1.157;
                    break;
            }
            break;
    }

    printf("The converted value is: %d", value);

    return 0;
}