//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    int choice, unit_from, unit_to;
    float value;

    printf("Welcome to the Surrealist Unit Converter!\n");

    printf("Please choose the unit you want to convert from:\n");
    printf("1. Quibble\n");
    printf("2. Giggle\n");
    printf("3. Whimsy\n");
    printf("4. Whiff\n");

    scanf("%d", &unit_from);

    printf("Please choose the unit you want to convert to:\n");
    printf("1. Quibble\n");
    printf("2. Giggle\n");
    printf("3. Whimsy\n");
    printf("4. Whiff\n");

    scanf("%d", &unit_to);

    printf("Please enter the value you want to convert:");
    scanf("%f", &value);

    switch (unit_from)
    {
        case 1:
            switch (unit_to)
            {
                case 1:
                    printf("The converted value is: %.2f quibble.\n", value);
                    break;
                case 2:
                    printf("The converted value is: %.2f giggle.\n", value * 2);
                    break;
                case 3:
                    printf("The converted value is: %.2f whimsy.\n", value * 3);
                    break;
                case 4:
                    printf("The converted value is: %.2f whiff.\n", value * 4);
                    break;
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    printf("The converted value is: %.2f quibble.\n", value / 2);
                    break;
                case 2:
                    printf("The converted value is: %.2f giggle.\n", value);
                    break;
                case 3:
                    printf("The converted value is: %.2f whimsy.\n", value * 1.5);
                    break;
                case 4:
                    printf("The converted value is: %.2f whiff.\n", value * 2);
                    break;
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    printf("The converted value is: %.2f quibble.\n", value / 3);
                    break;
                case 2:
                    printf("The converted value is: %.2f giggle.\n", value * 0.666);
                    break;
                case 3:
                    printf("The converted value is: %.2f whimsy.\n", value);
                    break;
                case 4:
                    printf("The converted value is: %.2f whiff.\n", value * 1.333);
                    break;
            }
            break;
        case 4:
            switch (unit_to)
            {
                case 1:
                    printf("The converted value is: %.2f quibble.\n", value / 4);
                    break;
                case 2:
                    printf("The converted value is: %.2f giggle.\n", value * 0.5);
                    break;
                case 3:
                    printf("The converted value is: %.2f whimsy.\n", value * 0.75);
                    break;
                case 4:
                    printf("The converted value is: %.2f whiff.\n", value);
                    break;
            }
            break;
    }

    return 0;
}