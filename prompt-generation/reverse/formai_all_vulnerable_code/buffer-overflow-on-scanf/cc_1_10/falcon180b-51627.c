//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int choice, end;
    double num, result;
    char unit[10];

    printf("Enter the number: ");
    scanf("%lf", &num);

    printf("Enter the unit of the number: ");
    scanf("%s", unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit);

    if(strcmp(unit, "meter") == 0)
    {
        result = num * 100;
        printf("%lf %s = %lf centimeter\n", num, unit, result);
    }
    else if(strcmp(unit, "centimeter") == 0)
    {
        result = num / 100;
        printf("%lf %s = %lf meter\n", num, unit, result);
    }
    else if(strcmp(unit, "kilogram") == 0)
    {
        result = num * 1000;
        printf("%lf %s = %lf gram\n", num, unit, result);
    }
    else if(strcmp(unit, "gram") == 0)
    {
        result = num / 1000;
        printf("%lf %s = %lf kilogram\n", num, unit, result);
    }
    else if(strcmp(unit, "liter") == 0)
    {
        result = num * 1000;
        printf("%lf %s = %lf milliliter\n", num, unit, result);
    }
    else if(strcmp(unit, "milliliter") == 0)
    {
        result = num / 1000;
        printf("%lf %s = %lf liter\n", num, unit, result);
    }
    else
    {
        printf("Invalid unit entered.\n");
    }

    return 0;
}