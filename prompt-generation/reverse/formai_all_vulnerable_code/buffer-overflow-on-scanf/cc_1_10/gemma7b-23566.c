//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void temp_converter(float, int);

int main()
{
    float temp;
    int choice;

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    printf("Enter the conversion choice:\n1. Fahrenheit\n2. Celsius\n3. Kelvin\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            temp_converter(temp, 1);
            break;
        case 2:
            temp_converter(temp, 2);
            break;
        case 3:
            temp_converter(temp, 3);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

void temp_converter(float t, int c)
{
    float converted_temp;

    switch (c)
    {
        case 1:
            converted_temp = (t * 1.8) + 32;
            break;
        case 2:
            converted_temp = (t - 32) * 5 / 9;
            break;
        case 3:
            converted_temp = t + 273.15;
            break;
        default:
            printf("Invalid choice.\n");
    }

    printf("The converted temperature is: %.2f\n", converted_temp);
}