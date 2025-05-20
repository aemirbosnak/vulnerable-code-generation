//FormAI DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

void temp_conversion(float temperature, char source_unit, char dest_unit)
{
    float converted_temp;

    if(source_unit == 'C' || source_unit == 'c')
    {
        if(dest_unit == 'F' || dest_unit == 'f')
        {
            converted_temp = temperature * 1.8 + 32;
            printf("The temperature in Fahrenheit is %0.2f\n", converted_temp); 
        }
        else if(dest_unit == 'K' || dest_unit == 'k')
        {
            converted_temp = temperature + 273.15;
            printf("The temperature in Kelvin is %0.2f\n", converted_temp);
        }
        else
        {
            printf("Invalid destination unit. Please try again.\n");
        }
    }
    else if(source_unit == 'F' || source_unit == 'f')
    {
        if(dest_unit == 'C' || dest_unit == 'c')
        {
            converted_temp = (temperature - 32) / 1.8;
            printf("The temperature in Celsius is %0.2f\n", converted_temp);
        }
        else if(dest_unit == 'K' || dest_unit == 'k')
        {
            converted_temp = (temperature + 459.67) * 5 / 9;
            printf("The temperature in Kelvin is %0.2f\n", converted_temp);
        }
        else
        {
            printf("Invalid destination unit. Please try again.\n");
        }
    }
    else if(source_unit == 'K' || source_unit == 'k')
    {
        if(dest_unit == 'C' || dest_unit == 'c')
        {
            converted_temp = temperature - 273.15;
            printf("The temperature in Celsius is %0.2f\n", converted_temp);
        }
        else if(dest_unit == 'F' || dest_unit == 'f')
        {
            converted_temp = temperature * 9 / 5 - 459.67;
            printf("The temperature in Fahrenheit is %0.2f\n", converted_temp);
        }
        else
        {
            printf("Invalid destination unit. Please try again.\n");
        }
    }
    else
    {
        printf("Invalid source unit. Please try again.\n");
    }
}

int main()
{
    float temperature;
    char source_unit, dest_unit;

    printf("Please enter the temperature:");
    scanf("%f", &temperature);

    printf("Please enter the source unit (C/F/K):");
    scanf(" %c", &source_unit);

    printf("Please enter the destination unit (C/F/K):");
    scanf(" %c", &dest_unit);

    temp_conversion(temperature, source_unit, dest_unit);

    return 0;
}