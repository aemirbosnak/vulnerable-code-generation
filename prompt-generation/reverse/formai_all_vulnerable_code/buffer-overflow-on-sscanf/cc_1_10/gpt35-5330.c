//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <string.h>

// function to convert Celsius to Fahrenheit
double CtoF(double celsius)
{
    double fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// function to convert Fahrenheit to Celsius
double FtoC(double fahrenheit)
{
    double celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

int main()
{
    char input[100];
    char unit[100];
    double value = 0;
    double result = 0;

    printf("Welcome to our puzzling unit converter program!\n");
    printf("Please enter a value and unit to convert (e.g. 25C or 68F): ");
    fgets(input, 100, stdin);
    sscanf(input, "%lf%s", &value, unit);

    if (strlen(unit) == 1)
    {
        // we assume that the user has entered the unit only ("C" or "F")
        char user_unit = unit[0];
        if (user_unit == 'C')
        {
            // convert Celsius to Fahrenheit
            result = CtoF(value);
            printf("%.2lfC is equal to %.2lfF\n", value, result);
        }
        else if (user_unit == 'F')
        {
            // convert Fahrenheit to Celsius
            result = FtoC(value);
            printf("%.2lfF is equal to %.2lfC\n", value, result);
        }
        else
        {
            printf("Invalid unit entered!\n");
            return 1;
        }
    }
    else
    {
        // we assume that the user has entered the value and unit (e.g. "25C" or "68F")
        char user_unit = unit[strlen(unit) - 1];
        unit[strlen(unit) - 1] = '\0';

        if (strcmp(unit, "C") == 0)
        {
            // convert Celsius to Fahrenheit
            result = CtoF(value);
            printf("%.2lfC is equal to %.2lfF\n", value, result);
        }
        else if (strcmp(unit, "F") == 0)
        {
            // convert Fahrenheit to Celsius
            result = FtoC(value);
            printf("%.2lfF is equal to %.2lfC\n", value, result);
        }
        else
        {
            printf("Invalid unit entered!\n");
            return 1;
        }
    }

    return 0;
}