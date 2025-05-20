//FormAI DATASET v1.0 Category: Unit converter ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function prototypes
void chooseConversion(int choice);
void convertLength();
void convertTemperature();
void convertWeight();

int main()
{
    int choice;

    printf("\nUnit Converter");
    printf("\n--------------");
    printf("\n1. Length");
    printf("\n2. Temperature");
    printf("\n3. Weight");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    chooseConversion(choice);

    return 0;
}

void chooseConversion(int choice)
{
    switch(choice)
    {
        case 1:
            convertLength();
            break;
        case 2:
            convertTemperature();
            break;
        case 3:
            convertWeight();
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }
}

void convertLength()
{
    char fromUnit[10], toUnit[10];
    float fromValue, toValue;

    printf("\nLength Converter");
    printf("\n----------------");
    printf("\nEnter the value to convert: ");
    scanf("%f", &fromValue);
    printf("Enter the unit to convert from: ");
    scanf("%s", fromUnit);
    printf("Enter the unit to convert to: ");
    scanf("%s", toUnit);

    // Convert all input units to lowercase for easier comparison
    for(int i=0; i<strlen(fromUnit); i++)
    {
        fromUnit[i] = tolower(fromUnit[i]);
    }
    for(int i=0; i<strlen(toUnit); i++)
    {
        toUnit[i] = tolower(toUnit[i]);
    }

    if(strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "m") == 0)
    {
        toValue = fromValue / 100;
    }
    else if(strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "in") == 0)
    {
        toValue = fromValue / 2.54;
    }
    else if(strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "cm") == 0)
    {
        toValue = fromValue * 100;
    }
    else if(strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "in") == 0)
    {
        toValue = fromValue * 39.37;
    }
    else if(strcmp(fromUnit, "in") == 0 && strcmp(toUnit, "cm") == 0)
    {
        toValue = fromValue * 2.54;
    }
    else if(strcmp(fromUnit, "in") == 0 && strcmp(toUnit, "m") == 0)
    {
        toValue = fromValue / 39.37;
    }
    else
    {
        printf("\nInvalid units.\n");
        return;
    }

    printf("\n%.2f %s = %.2f %s\n", fromValue, fromUnit, toValue, toUnit);
}

void convertTemperature()
{
    char fromUnit[10], toUnit[10];
    float fromValue, toValue;

    printf("\nTemperature Converter");
    printf("\n---------------------");
    printf("\nEnter the value to convert: ");
    scanf("%f", &fromValue);
    printf("Enter the unit to convert from: ");
    scanf("%s", fromUnit);
    printf("Enter the unit to convert to: ");
    scanf("%s", toUnit);

    // Convert all input units to lowercase for easier comparison
    for(int i=0; i<strlen(fromUnit); i++)
    {
        fromUnit[i] = tolower(fromUnit[i]);
    }
    for(int i=0; i<strlen(toUnit); i++)
    {
        toUnit[i] = tolower(toUnit[i]);
    }

    if(strcmp(fromUnit, "c") == 0 && strcmp(toUnit, "f") == 0)
    {
        toValue = (fromValue * 1.8) + 32;
    }
    else if(strcmp(fromUnit, "f") == 0 && strcmp(toUnit, "c") == 0)
    {
        toValue = (fromValue - 32) * 0.5556;
    }
    else if(strcmp(fromUnit, "c") == 0 && strcmp(toUnit, "k") == 0)
    {
        toValue = fromValue + 273.15;
    }
    else if(strcmp(fromUnit, "f") == 0 && strcmp(toUnit, "k") == 0)
    {
        toValue = (fromValue + 459.67) * 0.5556;
    }
    else if(strcmp(fromUnit, "k") == 0 && strcmp(toUnit, "c") == 0)
    {
        toValue = fromValue - 273.15;
    }
    else if(strcmp(fromUnit, "k") == 0 && strcmp(toUnit, "f") == 0)
    {
        toValue = (fromValue * 1.8) - 459.67;
    }
    else
    {
        printf("\nInvalid units.\n");
        return;
    }

    printf("\n%.2f %s = %.2f %s\n", fromValue, fromUnit, toValue, toUnit);
}

void convertWeight()
{
    char fromUnit[10], toUnit[10];
    float fromValue, toValue;

    printf("\nWeight Converter");
    printf("\n----------------");
    printf("\nEnter the value to convert: ");
    scanf("%f", &fromValue);
    printf("Enter the unit to convert from: ");
    scanf("%s", fromUnit);
    printf("Enter the unit to convert to: ");
    scanf("%s", toUnit);

    // Convert all input units to lowercase for easier comparison
    for(int i=0; i<strlen(fromUnit); i++)
    {
        fromUnit[i] = tolower(fromUnit[i]);
    }
    for(int i=0; i<strlen(toUnit); i++)
    {
        toUnit[i] = tolower(toUnit[i]);
    }

    if(strcmp(fromUnit, "g") == 0 && strcmp(toUnit, "kg") == 0)
    {
        toValue = fromValue / 1000;
    }
    else if(strcmp(fromUnit, "g") == 0 && strcmp(toUnit, "oz") == 0)
    {
        toValue = fromValue * 0.035274;
    }
    else if(strcmp(fromUnit, "kg") == 0 && strcmp(toUnit, "g") == 0)
    {
        toValue = fromValue * 1000;
    }
    else if(strcmp(fromUnit, "kg") == 0 && strcmp(toUnit, "oz") == 0)
    {
        toValue = fromValue * 35.274;
    }
    else if(strcmp(fromUnit, "oz") == 0 && strcmp(toUnit, "g") == 0)
    {
        toValue = fromValue / 0.035274;
    }
    else if(strcmp(fromUnit, "oz") == 0 && strcmp(toUnit, "kg") == 0)
    {
        toValue = fromValue / 35.274;
    }
    else
    {
        printf("\nInvalid units.\n");
        return;
    }

    printf("\n%.2f %s = %.2f %s\n", fromValue, fromUnit, toValue, toUnit);
}