//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
// Consulting Detective Sherlock Holmes

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    float num;
    char unit_from, unit_to;

    // Display available units
    printf("Available units: kg, g, lb, oz, ml, L, km, mi\n");

    // Get user input
    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit you are converting from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you are converting to: ");
    scanf(" %c", &unit_to);

    // Convert units
    switch (unit_from)
    {
        case 'k':
            switch (unit_to)
            {
                case 'g':
                    num *= 1000;
                    break;
                case 'lb':
                    num *= 2.2046;
                    break;
                case 'oz':
                    num *= 2.2046 * 16;
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'k':
                    num /= 1000;
                    break;
                case 'lb':
                    num *= 0.0022046;
                    break;
                case 'oz':
                    num *= 0.0022046 * 16;
                    break;
            }
            break;
        case 'lb':
            switch (unit_to)
            {
                case 'k':
                    num *= 0.45359;
                    break;
                case 'g':
                    num *= 2.2046;
                    break;
                case 'oz':
                    num *= 16;
                    break;
            }
            break;
        case 'oz':
            switch (unit_to)
            {
                case 'k':
                    num *= 0.45359 / 16;
                    break;
                case 'g':
                    num *= 0.45359 / 16;
                    break;
                case 'lb':
                    num /= 16;
                    break;
            }
            break;
        case 'ml':
            switch (unit_to)
            {
                case 'L':
                    num *= 1000;
                    break;
                case 'oz':
                    num *= 0.08333;
                    break;
            }
            break;
        case 'L':
            switch (unit_to)
            {
                case 'ml':
                    num *= 1000;
                    break;
                case 'oz':
                    num *= 8.333;
                    break;
            }
            break;
        case 'km':
            switch (unit_to)
            {
                case 'mi':
                    num *= 0.621371;
                    break;
            }
            break;
        case 'mi':
            switch (unit_to)
            {
                case 'km':
                    num *= 1.60934;
                    break;
            }
            break;
    }

    // Display the converted number
    printf("The converted number is: %.2f %s\n", num, unit_to);

    return 0;
}