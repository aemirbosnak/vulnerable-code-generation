//FormAI DATASET v1.0 Category: Unit converter ; Style: protected
#include<stdio.h>
#include<stdlib.h>

/* Function prototypes */
float convertTemp(float temperature, char fromUnit, char toUnit);
float convertLength(float length, char fromUnit, char toUnit);
int main();

/* Convert temperature from Fahrenheit to Celsius and vice versa */
float convertTemp(float temperature, char fromUnit, char toUnit)
{
    if(fromUnit == 'F' && toUnit == 'C')
        return (temperature - 32) * 5/9;
    else if(fromUnit == 'C' && toUnit == 'F')
        return (temperature * 9/5) + 32;
    else
        return temperature;
}

/* Convert length from meters to feet and vice versa */
float convertLength(float length, char fromUnit, char toUnit)
{
    if(fromUnit == 'M' && toUnit == 'F')
        return length * 3.28084;
    else if(fromUnit == 'F' && toUnit == 'M')
        return length / 3.28084;
    else
        return length;
}

/* Main function */
int main()
{
    char choice, fromUnit, toUnit;
    float value, result;
    int option;

    do
    {
        printf("\n\nC Unit Converter\n");
        printf("=================\n\n");
        printf("1. Temperature Conversion\n");
        printf("2. Length Conversion\n");
        printf("3. Exit\n");
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nTemperature Conversion\n");
                printf("=======================\n");
                printf("Enter the value: ");
                scanf("%f", &value);
                printf("\nEnter the unit of measurement (F/C): ");
                scanf(" %c", &fromUnit);
                printf("\nEnter the desired unit of measurement (F/C): ");
                scanf(" %c", &toUnit);
                result = convertTemp(value, fromUnit, toUnit);
                printf("\n%.2f %c = %.2f %c\n\n", value, fromUnit, result, toUnit);
                break;

            case 2:
                printf("\nLength Conversion\n");
                printf("===================\n");
                printf("Enter the value: ");
                scanf("%f", &value);
                printf("\nEnter the unit of measurement (M/F): ");
                scanf(" %c", &fromUnit);
                printf("\nEnter the desired unit of measurement (M/F): ");
                scanf(" %c", &toUnit);
                result = convertLength(value, fromUnit, toUnit);
                printf("\n%.2f %c = %.2f %c\n\n", value, fromUnit, result, toUnit);
                break;

            case 3:
                printf("\nThank you for using C Unit Converter!\n\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please enter a valid choice (1-3).\n");
        }

        printf("Do you want to convert again? (Y/N): ");
        scanf(" %c", &choice);

    } while(choice == 'Y' || choice == 'y');

    printf("\nThank you for using C Unit Converter!\n\n");
    return 0;
}