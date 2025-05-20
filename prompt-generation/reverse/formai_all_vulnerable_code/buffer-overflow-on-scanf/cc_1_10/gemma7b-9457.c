//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, units_from, units_to;
    float number;

    printf("Welcome, dear Watson, to the grandest unit converter in all of Baker Street!\n");
    printf("Please select the units you want to convert from:\n");
    printf("1. Metric\n");
    printf("2. Imperial\n");
    printf("Please enter your selection: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            units_from = 1;
            units_to = 2;
            break;
        case 2:
            units_from = 2;
            units_to = 1;
            break;
        default:
            printf("Error, dear Watson, I'm afraid you've made a mistake.\n");
            return 1;
    }

    printf("Now, please provide me with the number you want to convert: ");
    scanf("%f", &number);

    float converted_number = 0;

    switch (units_from)
    {
        case 1:
            converted_number = number * 1000;
            break;
        case 2:
            converted_number = number * 2.2046;
            break;
    }

    switch (units_to)
    {
        case 1:
            converted_number = converted_number / 1000;
            break;
        case 2:
            converted_number = converted_number / 2.2046;
            break;
    }

    printf("Ah-ha! The converted number, my dear Watson, is: %.2f %s.\n", converted_number, units_to);

    return 0;
}