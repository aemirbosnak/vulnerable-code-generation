//FormAI DATASET v1.0 Category: Unit converter ; Style: immersive
#include<stdio.h>

int main()
{
    printf("Welcome to the Unit Converter!\n");
    printf("Please select the conversion type:\n");
    printf("1. Temperature\n2. Length\n3. Weight\n");
    int option;
    scanf("%d", &option);
    switch(option)
    {
        case 1: // Temperature Conversion
            printf("Please select the source unit:\n");
            printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
            int source_unit;
            scanf("%d", &source_unit);
            printf("Enter the temperature: ");
            float temp, result;
            scanf("%f", &temp);
            switch(source_unit)
            {
                case 1: // Celsius
                    printf("Please select the target unit:\n");
                    printf("1. Fahrenheit\n2. Kelvin\n");
                    int target_unit;
                    scanf("%d", &target_unit);
                    if(target_unit == 1)
                    {
                        result = (temp * 9/5) + 32;
                        printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit.", temp, result);
                    }
                    else if(target_unit == 2)
                    {
                        result = temp + 273.15;
                        printf("%.2f degree Celsius is equal to %.2f Kelvin.", temp, result);
                    }
                    else
                    {
                        printf("Invalid target unit!");
                    }
                    break;
                case 2: // Fahrenheit
                    printf("Please select the target unit:\n");
                    printf("1. Celsius\n2. Kelvin\n");
                    scanf("%d", &target_unit);
                    if(target_unit == 1)
                    {
                        result = (temp - 32) * 5/9;
                        printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius.", temp, result);
                    }
                    else if(target_unit == 2)
                    {
                        result = (temp - 32) * 5/9 + 273.15;
                        printf("%.2f degree Fahrenheit is equal to %.2f Kelvin.", temp, result);
                    }
                    else
                    {
                        printf("Invalid target unit!");
                    }
                    break;
                case 3: // Kelvin
                    printf("Please select the target unit:\n");
                    printf("1. Celsius\n2. Fahrenheit\n");
                    scanf("%d", &target_unit);
                    if(target_unit == 1)
                    {
                        result = temp - 273.15;
                        printf("%.2f Kelvin is equal to %.2f degree Celsius.", temp, result);
                    }
                    else if(target_unit == 2)
                    {
                        result = (temp - 273.15) * 9/5 + 32;
                        printf("%.2f Kelvin is equal to %.2f degree Fahrenheit.", temp, result);
                    }
                    else
                    {
                        printf("Invalid target unit!");
                    }
                    break;
                default:
                    printf("Invalid source unit!");
                    break;
             }
             break;

        case 2: // Length Conversion
            printf("Please select the source unit:\n");
            printf("1. Meter\n2. Kilometer\n3. Mile\n");
            scanf("%d", &source_unit);
            printf("Enter the length: ");
            float length;
            scanf("%f", &length);
            switch(source_unit)
            {
                case 1: // Meter
                    printf("Please select the target unit:\n");
                    printf("1. Kilometer\n2. Mile\n");
                    int target_unit;
                    scanf("%d", &target_unit);
                    if(target_unit == 1)
                    {
                        result = length / 1000;
                        printf("%.2f meter is equal to %.2f kilometer.", length, result);
                    }
                    else if(target_unit == 2)
                    {
                        result = length / 1609.344;
                        printf("%.2f meter is equal to %.2f mile.", length, result);
                    }
                    else
                    {
                        printf("Invalid target unit!");
                    }
                    break;
                case 2: // Kilometer
                    printf("Please select the target unit:\n");
                    printf("1. Meter\n2. Mile\n");
                    scanf("%d", &target_unit);
                    if(target_unit == 1)
                    {
                        result = length * 1000;
                        printf("%.2f kilometer is equal to %.2f meter.", length, result);
                    }
                    else if(target_unit == 2)
                    {
                        result = length / 1.609344;
                        printf("%.2f kilometer is equal to %.2f mile.", length, result);
                    }
                    else
                    {
                        printf("Invalid target unit!");
                    }
                    break;
                case 3: // Mile
                    printf("Please select the target unit:\n");
                    printf("1. Meter\n2. Kilometer\n");
                    scanf("%d", &target_unit);
                    if(target_unit == 1)
                    {
                        result = length * 1609.344;
                        printf("%.2f mile is equal to %.2f meter.", length, result);
                    }
                    else if(target_unit == 2)
                    {
                        result = length * 1.609344;
                        printf("%.2f mile is equal to %.2f kilometer.", length, result);
                    }
                    else
                    {
                        printf("Invalid target unit!");
                    }
                    break;
                default:
                    printf("Invalid source unit!");
                    break;
            }
            break;

        case 3: // Weight Conversion
            printf("Please select the source unit:\n");
            printf("1. Kilogram\n2. Gram\n3. Pound\n");
            scanf("%d", &source_unit);
            printf("Enter the weight: ");
            float weight;
            scanf("%f", &weight);
            switch(source_unit)
            {
                case 1: // Kilogram
                    printf("Please select the target unit:\n");
                    printf("1. Gram\n2. Pound\n");
                    int target_unit;
                    scanf("%d", &target_unit);
                    if(target_unit == 1)
                    {
                        result = weight * 1000;
                        printf("%.2f kilogram is equal to %.2f gram.", weight, result);
                    }
                    else if(target_unit == 2)
                    {
                        result = weight * 2.20462262;
                        printf("%.2f kilogram is equal to %.2f pound.", weight, result);
                    }
                    else
                    {
                        printf("Invalid target unit!");
                    }
                    break;
                case 2: // Gram
                    printf("Please select the target unit:\n");
                    printf("1. Kilogram\n2. Pound\n");
                    scanf("%d", &target_unit);
                    if(target_unit == 1)
                    {
                        result = weight / 1000;
                        printf("%.2f gram is equal to %.2f kilogram.", weight, result);
                    }
                    else if(target_unit == 2)
                    {
                        result = weight / 453.59237;
                        printf("%.2f gram is equal to %.2f pound.", weight, result);
                    }
                    else
                    {
                        printf("Invalid target unit!");
                    }
                    break;
                case 3: // Pound
                    printf("Please select the target unit:\n");
                    printf("1. Kilogram\n2. Gram\n");
                    scanf("%d", &target_unit);
                    if(target_unit == 1)
                    {
                        result = weight / 2.20462262;
                        printf("%.2f pound is equal to %.2f kilogram.", weight, result);
                    }
                    else if(target_unit == 2)
                    {
                        result = weight * 453.59237;
                        printf("%.2f pound is equal to %.2f gram.", weight, result);
                    }
                    else
                    {
                        printf("Invalid target unit!");
                    }
                    break;
                default:
                    printf("Invalid source unit!");
                    break;
            }
            break;
        default:
            printf("Invalid option!");
            break;
    }
    return 0;
}