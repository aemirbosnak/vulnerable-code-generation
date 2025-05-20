//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    system("clear");
    printf("---------------------------------------------------------------------\n");
    printf("           WELCOME TO THE CYBERSPACE UNIT CONVERTER!\n");
    printf("---------------------------------------------------------------------\n");

    char unit_from[20];
    char unit_to[20];
    float value;

    printf("Enter the value you want to convert: ");
    scanf("%f", &value);

    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit_to);

    float converted_value = 0;

    if (strcmp(unit_from, "kg") == 0 && strcmp(unit_to, "g") == 0)
    {
        converted_value = value * 1000;
    }
    else if (strcmp(unit_from, "g") == 0 && strcmp(unit_to, "kg") == 0)
    {
        converted_value = value / 1000;
    }
    else if (strcmp(unit_from, "km") == 0 && strcmp(unit_to, "m") == 0)
    {
        converted_value = value * 1000;
    }
    else if (strcmp(unit_from, "m") == 0 && strcmp(unit_to, "km") == 0)
    {
        converted_value = value / 1000;
    }
    else if (strcmp(unit_from, "h") == 0 && strcmp(unit_to, "min") == 0)
    {
        converted_value = value * 60;
    }
    else if (strcmp(unit_from, "min") == 0 && strcmp(unit_to, "h") == 0)
    {
        converted_value = value / 60;
    }
    else
    {
        printf("Invalid unit conversion.\n");
    }

    if (converted_value != 0)
    {
        printf("The converted value is: %.2f %s.\n", converted_value, unit_to);
    }

    system("pause");
}