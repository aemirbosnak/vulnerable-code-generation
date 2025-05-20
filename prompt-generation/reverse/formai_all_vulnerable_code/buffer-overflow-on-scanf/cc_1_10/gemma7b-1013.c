//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void morph_temp(int, int);

int main()
{
    int choice, t_from, t_to;
    char unit_from, unit_to;

    printf("Enter the temperature conversion unit you want to use:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit:");
            scanf("%d", &t_from);
            t_to = (t_from - 32) * 5 / 9;
            unit_from = 'F';
            unit_to = 'C';
            break;
        case 2:
            printf("Enter the temperature in Celsius:");
            scanf("%d", &t_from);
            t_to = (t_from * 9 / 5) + 32;
            unit_from = 'C';
            unit_to = 'F';
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    morph_temp(t_from, t_to);

    printf("\nThe converted temperature is: %.2f %c.", t_to, unit_to);
    return 0;
}

void morph_temp(int t_from, int t_to)
{
    int i;
    for (i = t_from; i <= t_to; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}