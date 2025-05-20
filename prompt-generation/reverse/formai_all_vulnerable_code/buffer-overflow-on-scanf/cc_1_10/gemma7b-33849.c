//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

typedef struct Temperature
{
    float value;
    char unit;
} Temperature;

void convert_temperature(Temperature, Temperature);

int main()
{
    Temperature t1, t2;

    printf("Enter the temperature:");
    scanf("%f %c", &t1.value, &t1.unit);

    printf("Enter the target unit:");
    scanf("%c", &t2.unit);

    convert_temperature(t1, t2);

    printf("The converted temperature is: %.2f %c", t2.value, t2.unit);

    return 0;
}

void convert_temperature(Temperature t1, Temperature t2)
{
    switch (t1.unit)
    {
        case 'C':
            t2.value = t1.value;
            t2.unit = 'C';
            break;
        case 'F':
            t2.value = (t1.value - 32) * 5 / 9 + t1.value;
            t2.unit = 'C';
            break;
        case 'K':
            t2.value = t1.value - 273.15;
            t2.unit = 'C';
            break;
        default:
            printf("Error: invalid unit");
            break;
    }
}