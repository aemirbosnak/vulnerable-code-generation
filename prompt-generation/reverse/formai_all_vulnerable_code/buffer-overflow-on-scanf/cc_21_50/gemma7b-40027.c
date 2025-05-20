//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice, unit_from, unit_to, num;
    float result;

    printf("Welcome to the Unit Converter!\n");

    // Display available units
    printf("Available units:\n");
    printf("1. Meter\n");
    printf("2. Centimeter\n");
    printf("3. Kilometer\n");
    printf("4. Mile\n");
    printf("5. Yard\n");

    // Get user input
    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    printf("Enter the number you want to convert: ");
    scanf("%d", &num);

    // Calculate the conversion factor
    switch (unit_from)
    {
        case 1:
            switch (unit_to)
            {
                case 2:
                    result = num * 10;
                    break;
                case 3:
                    result = num * 1000;
                    break;
                case 4:
                    result = num * 1609.34;
                    break;
                case 5:
                    result = num * 3280.84;
                    break;
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    result = num / 10;
                    break;
                case 3:
                    result = num * 1000;
                    break;
                case 4:
                    result = num * 1609.34;
                    break;
                case 5:
                    result = num * 3280.84;
                    break;
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    result = num / 1000;
                    break;
                case 2:
                    result = num * 1000;
                    break;
                case 4:
                    result = num * 1609.34;
                    break;
                case 5:
                    result = num * 3280.84;
                    break;
            }
            break;
        case 4:
            switch (unit_to)
            {
                case 1:
                    result = num * 0.0062137;
                    break;
                case 2:
                    result = num * 0.0062137;
                    break;
                case 3:
                    result = num * 0.0062137;
                    break;
                case 5:
                    result = num * 0.0062137;
                    break;
            }
            break;
        case 5:
            switch (unit_to)
            {
                case 1:
                    result = num * 0.003051;
                    break;
                case 2:
                    result = num * 0.003051;
                    break;
                case 3:
                    result = num * 0.003051;
                    break;
                case 4:
                    result = num * 0.003051;
                    break;
            }
            break;
    }

    // Display the converted result
    printf("The converted result is: %.2f", result);

    return 0;
}