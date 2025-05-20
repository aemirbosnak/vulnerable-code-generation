//FormAI DATASET v1.0 Category: Unit converter ; Style: systematic
#include<stdio.h>

int main()
{
    float inputVal;
    int inputUnit;
    int outputUnit;
    float outputVal;

    printf("This program converts units of length, weight and temperature.\n");
    printf("Please select the input unit: \n");
    printf("1 - Meter, 2 - Kilometers, 3 - Feet, 4 - Inches, 5 - Pounds, 6 - Kilograms, 7 - Celsius, 8 - Fahrenheit\n");
    scanf("%d", &inputUnit);

    printf("Please enter the value you want to convert: \n");
    scanf("%f", &inputVal);

    if (inputUnit == 1) // Meter to ...
    {
        printf("Please select the output unit: \n");
        printf("2 - Kilometers, 3 - Feet, 4 - Inches\n");
        scanf("%d", &outputUnit);

        if (outputUnit == 2) // Meter to Kilometer
        {
            outputVal = inputVal / 1000;
            printf("%.2f meters is %.2f kilometers.", inputVal, outputVal);
        }
        else if (outputUnit == 3) // Meter to Feet
        {
            outputVal = inputVal * 3.281;
            printf("%.2f meters is %.2f feet.", inputVal, outputVal);
        }
        else if (outputUnit == 4) // Meter to Inches
        {
            outputVal = inputVal * 39.37;
            printf("%.2f meters is %.2f inches.", inputVal, outputVal);
        }
        else
        {
            printf("Invalid output unit selected.\n");
        }

    }
    else if (inputUnit == 2) // Kilometer to ...
    {
        printf("Please select the output unit: \n");
        printf("1 - Meter, 3 - Feet, 4 - Inches\n");
        scanf("%d", &outputUnit);

        if (outputUnit == 1) // Kilometer to Meter
        {
            outputVal = inputVal * 1000;
            printf("%.2f kilometers is %.2f meters.", inputVal, outputVal);
        }
        else if (outputUnit == 3) // Kilometer to Feet
        {
            outputVal = inputVal * 3281;
            printf("%.2f kilometers is %.2f feet.", inputVal, outputVal);
        }
        else if (outputUnit == 4) // Kilometer to Inches
        {
            outputVal = inputVal * 39370;
            printf("%.2f kilometers is %.2f inches.", inputVal, outputVal);
        }
        else
        {
            printf("Invalid output unit selected.\n");
        }
    }
    else if (inputUnit == 3) // Feet to ...
    {
        printf("Please select the output unit: \n");
        printf("1 - Meter, 2 - Kilometers, 4 - Inches\n");
        scanf("%d", &outputUnit);

        if (outputUnit == 1) // Feet to Meter
        {
            outputVal = inputVal / 3.281;
            printf("%.2f feet is %.2f meters.", inputVal, outputVal);
        }
        else if (outputUnit == 2) // Feet to Kilometer
        {
            outputVal = inputVal / 3281;
            printf("%.2f feet is %.2f kilometers.", inputVal, outputVal);
        }
        else if (outputUnit == 4) // Feet to Inches
        {
            outputVal = inputVal * 12;
            printf("%.2f feet is %.2f inches.", inputVal, outputVal);
        }
        else
        {
            printf("Invalid output unit selected.\n");
        }

    }
    else if (inputUnit == 4) // Inches to ...
    {
        printf("Please select the output unit: \n");
        printf("1 - Meter, 2 - Kilometers, 3 - Feet\n");
        scanf("%d", &outputUnit);

        if (outputUnit == 1) // Inches to Meter
        {
            outputVal = inputVal / 39.37;
            printf("%.2f inches is %.2f meters.", inputVal, outputVal);
        }
        else if (outputUnit == 2) // Inches to Kilometer
        {
            outputVal = inputVal / 39370;
            printf("%.2f inches is %.2f kilometers.", inputVal, outputVal);
        }
        else if (outputUnit == 3) // Inches to Feet
        {
            outputVal = inputVal / 12;
            printf("%.2f inches is %.2f feet.", inputVal, outputVal);
        }
        else
        {
            printf("Invalid output unit selected.\n");
        }

    }
    else if (inputUnit == 5) // Pound to ...
    {
        printf("Please select the output unit: \n");
        printf("6 - Kilograms\n");
        scanf("%d", &outputUnit);

        if (outputUnit == 6) // Pound to Kilogram
        {
            outputVal = inputVal / 2.205;
            printf("%.2f pounds is %.2f kilograms.", inputVal, outputVal);
        }
        else
        {
            printf("Invalid output unit selected.\n");
        }
    }
    else if (inputUnit == 6) // Kilogram to ...
    {
        printf("Please select the output unit: \n");
        printf("5 - Pounds\n");
        scanf("%d", &outputUnit);

        if (outputUnit == 5) // Kilogram to Pound
        {
            outputVal = inputVal * 2.205;
            printf("%.2f kilograms is %.2f pounds.", inputVal, outputVal);
        }
        else
        {
            printf("Invalid output unit selected.\n");
        }
    }
    else if (inputUnit == 7) // Celsius to ...
    {
        printf("Please select the output unit: \n");
        printf("8 - Fahrenheit\n");
        scanf("%d", &outputUnit);

        if (outputUnit == 8) // Celsius to Fahrenheit
        {
            outputVal = (inputVal * 9/5) + 32;
            printf("%.2f Celsius is %.2f Fahrenheit.", inputVal, outputVal);
        }
        else
        {
            printf("Invalid output unit selected.\n");
        }
    }
    else if (inputUnit == 8) // Fahrenheit to ...
    {
        printf("Please select the output unit: \n");
        printf("7 - Celsius\n");
        scanf("%d", &outputUnit);

        if (outputUnit == 7) // Fahrenheit to Celsius
        {
            outputVal = (inputVal - 32) * 5/9;
            printf("%.2f Fahrenheit is %.2f Celsius.", inputVal, outputVal);
        }
        else
        {
            printf("Invalid output unit selected.\n");
        }
    }
    else
    {
        printf("Invalid input unit selected.\n");
    }

    return 0;
}