//FormAI DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <string.h>

void print_menu();
double convert_unit(double value, char from_unit[], char to_unit[]);

int main()
{
    printf("Welcome to the Unit Converter Program.\n");
    printf("---------------------------------------\n");

    print_menu();

    while (1)
    {
        char from_unit[20], to_unit[20];
        double value, result;

        printf("\nEnter the value to convert: ");
        scanf("%lf", &value);

        printf("Enter the unit to convert from: ");
        scanf("%s", from_unit);

        printf("Enter the unit to convert to: ");
        scanf("%s", to_unit);

        result = convert_unit(value, from_unit, to_unit);

        if (result == -1)
        {
            printf("\nSorry, the units you entered are not supported by this program.\n");
        }
        else
        {
            printf("\n%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);
        }

        char choice;

        printf("\nDo you want to continue (Y/N)? ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n')
        {
            break;
        }
    }

    return 0;
}

void print_menu()
{
    printf("Supported Units:\n");
    printf("1. Length: meter (m), kilometer (km), centimeter (cm), millimeter (mm).\n");
    printf("2. Weight: kilogram (kg), gram (g), pound (lb), ounce (oz).\n");
    printf("3. Temperature: Celsius (C), Fahrenheit (F), Kelvin (K).\n");
    printf("4. Area: square meter (m2), square centimeter (cm2), square kilometer (km2).\n");
    printf("5. Volume: cubic meter (m3), liter (L), milliliter (mL), gallon (gal), quart (qt), pint (pt).\n");
}

double convert_unit(double value, char from_unit[], char to_unit[])
{
    if (strcmp(from_unit, "m") == 0)
    {
        if (strcmp(to_unit, "km") == 0)
        {
            return value / 1000;
        }
        else if (strcmp(to_unit, "cm") == 0)
        {
            return value * 100;
        }
        else if (strcmp(to_unit, "mm") == 0)
        {
            return value * 1000;
        }
        else if (strcmp(to_unit, "m") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "km") == 0)
    {
        if (strcmp(to_unit, "m") == 0)
        {
            return value * 1000;
        }
        else if (strcmp(to_unit, "cm") == 0)
        {
            return value * 100000;
        }
        else if (strcmp(to_unit, "mm") == 0)
        {
            return value * 1000000;
        }
        else if (strcmp(to_unit, "km") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "cm") == 0)
    {
        if (strcmp(to_unit, "m") == 0)
        {
            return value / 100;
        }
        else if (strcmp(to_unit, "km") == 0)
        {
            return value / 100000;
        }
        else if (strcmp(to_unit, "mm") == 0)
        {
            return value * 10;
        }
        else if (strcmp(to_unit, "cm") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "mm") == 0)
    {
        if (strcmp(to_unit, "m") == 0)
        {
            return value / 1000;
        }
        else if (strcmp(to_unit, "km") == 0)
        {
            return value / 1000000;
        }
        else if (strcmp(to_unit, "cm") == 0)
        {
            return value / 10;
        }
        else if (strcmp(to_unit, "mm") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "kg") == 0)
    {
        if (strcmp(to_unit, "g") == 0)
        {
            return value * 1000;
        }
        else if (strcmp(to_unit, "lb") == 0)
        {
            return value * 2.20462;
        }
        else if (strcmp(to_unit, "oz") == 0)
        {
            return value * 35.274;
        }
        else if (strcmp(to_unit, "kg") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "g") == 0)
    {
        if (strcmp(to_unit, "kg") == 0)
        {
            return value / 1000;
        }
        else if (strcmp(to_unit, "lb") == 0)
        {
            return value * 0.00220462;
        }
        else if (strcmp(to_unit, "oz") == 0)
        {
            return value * 0.035274;
        }
        else if (strcmp(to_unit, "g") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "lb") == 0)
    {
        if (strcmp(to_unit, "kg") == 0)
        {
            return value * 0.453592;
        }
        else if (strcmp(to_unit, "g") == 0)
        {
            return value * 453.592;
        }
        else if (strcmp(to_unit, "oz") == 0)
        {
            return value * 16;
        }
        else if (strcmp(to_unit, "lb") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "oz") == 0)
    {
        if (strcmp(to_unit, "kg") == 0)
        {
            return value * 0.0283495;
        }
        else if (strcmp(to_unit, "g") == 0)
        {
            return value * 28.3495;
        }
        else if (strcmp(to_unit, "lb") == 0)
        {
            return value * 0.0625;
        }
        else if (strcmp(to_unit, "oz") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "C") == 0)
    {
        if (strcmp(to_unit, "F") == 0)
        {
            return (value * 9 / 5) + 32;
        }
        else if (strcmp(to_unit, "K") == 0)
        {
            return value + 273.15;
        }
        else if (strcmp(to_unit, "C") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "F") == 0)
    {
        if (strcmp(to_unit, "C") == 0)
        {
            return (value - 32) * 5 / 9;
        }
        else if (strcmp(to_unit, "K") == 0)
        {
            return ((value - 32) * 5 / 9) + 273.15;
        }
        else if (strcmp(to_unit, "F") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "K") == 0)
    {
        if (strcmp(to_unit, "C") == 0)
        {
            return value - 273.15;
        }
        else if (strcmp(to_unit, "F") == 0)
        {
            return ((value - 273.15) * 9 / 5) + 32;
        }
        else if (strcmp(to_unit, "K") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "m2") == 0)
    {
        if (strcmp(to_unit, "cm2") == 0)
        {
            return value * 10000;
        }
        else if (strcmp(to_unit, "km2") == 0)
        {
            return value / 1000000;
        }
        else if (strcmp(to_unit, "m2") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "cm2") == 0)
    {
        if (strcmp(to_unit, "m2") == 0)
        {
            return value / 10000;
        }
        else if (strcmp(to_unit, "km2") == 0)
        {
            return value / 10000000000;
        }
        else if (strcmp(to_unit, "cm2") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "km2") == 0)
    {
        if (strcmp(to_unit, "m2") == 0)
        {
            return value * 1000000;
        }
        else if (strcmp(to_unit, "cm2") == 0)
        {
            return value * 10000000000;
        }
        else if (strcmp(to_unit, "km2") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "m3") == 0)
    {
        if (strcmp(to_unit, "L") == 0)
        {
            return value * 1000;
        }
        else if (strcmp(to_unit, "mL") == 0)
        {
            return value * 1000000;
        }
        else if (strcmp(to_unit, "gal") == 0)
        {
            return value * 264.172;
        }
        else if (strcmp(to_unit, "qt") == 0)
        {
            return value * 1056.69;
        }
        else if (strcmp(to_unit, "pt") == 0)
        {
            return value * 2113.38;
        }
        else if (strcmp(to_unit, "m3") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "L") == 0)
    {
        if (strcmp(to_unit, "m3") == 0)
        {
            return value / 1000;
        }
        else if (strcmp(to_unit, "mL") == 0)
        {
            return value * 1000;
        }
        else if (strcmp(to_unit, "gal") == 0)
        {
            return value * 0.264172;
        }
        else if (strcmp(to_unit, "qt") == 0)
        {
            return value * 1.05669;
        }
        else if (strcmp(to_unit, "pt") == 0)
        {
            return value * 2.11338;
        }
        else if (strcmp(to_unit, "L") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "mL") == 0)
    {
        if (strcmp(to_unit, "m3") == 0)
        {
            return value / 1000000;
        }
        else if (strcmp(to_unit, "L") == 0)
        {
            return value / 1000;
        }
        else if (strcmp(to_unit, "gal") == 0)
        {
            return value * 0.000264172;
        }
        else if (strcmp(to_unit, "qt") == 0)
        {
            return value * 0.00105669;
        }
        else if (strcmp(to_unit, "pt") == 0)
        {
            return value * 0.00211338;
        }
        else if (strcmp(to_unit, "mL") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "gal") == 0)
    {
        if (strcmp(to_unit, "m3") == 0)
        {
            return value / 264.172;
        }
        else if (strcmp(to_unit, "L") == 0)
        {
            return value / 0.264172;
        }
        else if (strcmp(to_unit, "mL") == 0)
        {
            return value / 0.000264172;
        }
        else if (strcmp(to_unit, "qt") == 0)
        {
            return value * 4;
        }
        else if (strcmp(to_unit, "pt") == 0)
        {
            return value * 8;
        }
        else if (strcmp(to_unit, "gal") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "qt") == 0)
    {
        if (strcmp(to_unit, "m3") == 0)
        {
            return value / 1056.69;
        }
        else if (strcmp(to_unit, "L") == 0)
        {
            return value / 1.05669;
        }
        else if (strcmp(to_unit, "mL") == 0)
        {
            return value / 0.00105669;
        }
        else if (strcmp(to_unit, "gal") == 0)
        {
            return value / 4;
        }
        else if (strcmp(to_unit, "pt") == 0)
        {
            return value * 2;
        }
        else if (strcmp(to_unit, "qt") == 0)
        {
            return value;
        }
    }
    else if (strcmp(from_unit, "pt") == 0)
    {
        if (strcmp(to_unit, "m3") == 0)
        {
            return value / 2113.38;
        }
        else if (strcmp(to_unit, "L") == 0)
        {
            return value / 2.11338;
        }
        else if (strcmp(to_unit, "mL") == 0)
        {
            return value / 0.00211338;
        }
        else if (strcmp(to_unit, "gal") == 0)
        {
            return value / 8;
        }
        else if (strcmp(to_unit, "qt") == 0)
        {
            return value / 2;
        }
        else if (strcmp(to_unit, "pt") == 0)
        {
            return value;
        }
    }
        
    return -1;
}