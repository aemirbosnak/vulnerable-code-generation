//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

void UnitConverter(float value, int unit_from, int unit_to)
{
    switch (unit_from)
    {
        case 1:  // Kilo
            switch (unit_to)
            {
                case 2:  // Gram
                    printf("%f grams are equal to %f kilos.\n", value, value * 1000);
                    break;
                case 3:  // Centigram
                    printf("%f centigrams are equal to %f kilos.\n", value, value * 1000);
                    break;
            }
            break;
        case 2:  // Gram
            switch (unit_to)
            {
                case 1:  // Kilo
                    printf("%f kilos are equal to %f grams.\n", value, value * 1000);
                    break;
                case 3:  // Centigram
                    printf("%f grams are equal to %f centigrams.\n", value, value * 10) ;
                    break;
            }
            break;
        case 3:  // Centigram
            switch (unit_to)
            {
                case 1:  // Kilo
                    printf("%f kilos are equal to %f centigrams.\n", value, value * 1000);
                    break;
                case 2:  // Gram
                    printf("%f centigrams are equal to %f grams.\n", value, value * 10);
                    break;
            }
            break;
    }
}

int main()
{
    float value;
    int unit_from, unit_to;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the unit you are converting from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you are converting to: ");
    scanf("%d", &unit_to);

    UnitConverter(value, unit_from, unit_to);

    return 0;
}