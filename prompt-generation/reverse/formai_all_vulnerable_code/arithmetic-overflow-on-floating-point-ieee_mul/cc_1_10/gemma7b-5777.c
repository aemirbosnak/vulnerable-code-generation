//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TemperatureConverter
{
    char unit;
    float value;
} TemperatureConverter;

int main()
{
    TemperatureConverter tConv;
    char inputUnit;
    float inputValue;
    char outputUnit;
    float outputValue;

    tConv.unit = '\0';
    tConv.value = 0.0f;

    printf("Enter the input unit (C, F, K): ");
    scanf("%c", &inputUnit);

    printf("Enter the input value: ");
    scanf("%f", &inputValue);

    tConv.unit = inputUnit;
    tConv.value = inputValue;

    printf("Enter the output unit (C, F, K): ");
    scanf("%c", &outputUnit);

    switch (outputUnit)
    {
        case 'C':
            outputValue = (tConv.value - 32.0f) * 5.0f / 9.0f + 273.15f;
            break;
        case 'F':
            outputValue = (tConv.value - 32.0f) * 9.0f / 5.0f + 32.0f;
            break;
        case 'K':
            outputValue = tConv.value + 273.15f;
            break;
        default:
            printf("Invalid output unit.\n");
            return 1;
    }

    printf("The output value is: %.2f %s.\n", outputValue, outputUnit);

    return 0;
}