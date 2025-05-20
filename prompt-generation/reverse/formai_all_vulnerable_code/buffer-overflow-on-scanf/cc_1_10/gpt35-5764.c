//FormAI DATASET v1.0 Category: Unit converter ; Style: surrealist
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void welcome();
float convert(float num, char from_unit[], char to_unit[]);
void print_conversion(float num, char from_unit[], char to_unit[], float result);

int main()
{
    welcome();

    char from_unit[20], to_unit[20];
    float num, result;

    printf("\n Please enter a number: ");
    scanf("%f", &num);

    printf("\n Please enter a unit to convert from: ");
    scanf("%s", from_unit);

    printf("\n Please enter a unit to convert to: ");
    scanf("%s", to_unit);

    result = convert(num, from_unit, to_unit);

    print_conversion(num, from_unit, to_unit, result);

    printf("\n Thank you for using our surrealistic unit converter! Have a weird day!");
    return 0;
}

void welcome()
{
    printf("\n Welcome to the surrealistic unit converter!");
    printf("\n Please keep in mind that this unit converter is not bound by the laws of physics.");
    printf("\n It may produce unexpected and even disturbing results. \n");
}

float convert(float num, char from_unit[], char to_unit[])
{
    // surrealistic unit conversion logic
    if (strcmp(from_unit, "elephant") == 0 && strcmp(to_unit, "moon") == 0)
        return num * 834855138.43;
    else if (strcmp(from_unit, "zombie") == 0 && strcmp(to_unit, "unicorn") == 0)
        return num * 0.005;
    else if (strcmp(from_unit, "cthulhu") == 0 && strcmp(to_unit, "kraken") == 0)
        return num * 10;
    else if (strcmp(from_unit, "rainbow") == 0 && strcmp(to_unit, "pot of gold") == 0)
        return num * 69;
    else if (strcmp(from_unit, "ghost") == 0 && strcmp(to_unit, "demon") == 0)
        return num * 6.66;
    else
    {
        printf("\n Sorry, we could not find a surrealistic conversion from %s to %s.", from_unit, to_unit);
        exit(1);
    }
}

void print_conversion(float num, char from_unit[], char to_unit[], float result)
{
    printf("\n %f %s is equal to %f %s according to our surrealistic algorithm.", num, from_unit, result, to_unit);
}