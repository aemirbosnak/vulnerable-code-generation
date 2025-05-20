//FormAI DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float value;
    int option;
    printf("Welcome to the Exciting Unit Converter!\n\n");
    printf("What type of unit would you like to convert to?\n");
    printf("1. Temperature\n");
    printf("2. Distance\n");
    printf("3. Weight\n");

    printf("\nPlease enter an option: ");
    scanf("%d", &option);

    if(option == 1) // Celsius to Fahrenheit or vice versa
    {
        printf("\nWhich direction do you want to convert?\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");

        printf("\nPlease enter an option: ");
        scanf("%d", &option);

        if(option == 1)
        {
            printf("\nPlease enter a value in Celsius: ");
            scanf("%f", &value);
            printf("\n%.2f Celsius is %.2f Fahrenheit\n", value, (value * 1.8) + 32);
        }
        else if(option == 2)
        {
            printf("\nPlease enter a value in Fahrenheit: ");
            scanf("%f", &value);
            printf("\n%.2f Fahrenheit is %.2f Celsius\n", value, (value - 32) / 1.8);
        }
        else
        {
            printf("\nInvalid option, please try again.\n");
        }
    }
    else if(option == 2) // Miles to Kilometers or vice versa
    {
        printf("\nWhich direction do you want to convert?\n");
        printf("1. Miles to Kilometers\n");
        printf("2. Kilometers to Miles\n");

        printf("\nPlease enter an option: ");
        scanf("%d", &option);

        if(option == 1)
        {
            printf("\nPlease enter a value in Miles: ");
            scanf("%f", &value);
            printf("\n%.2f Miles is %.2f Kilometers\n", value, value * 1.60934);
        }
        else if(option == 2)
        {
            printf("\nPlease enter a value in Kilometers: ");
            scanf("%f", &value);
            printf("\n%.2f Kilometers is %.2f Miles\n", value, value / 1.60934);
        }
        else
        {
            printf("\nInvalid option, please try again.\n");
        }
    }
    else if(option == 3) // Pounds to Kilograms or vice versa
    {
        printf("\nWhich direction do you want to convert?\n");
        printf("1. Pounds to Kilograms\n");
        printf("2. Kilograms to Pounds\n");

        printf("\nPlease enter an option: ");
        scanf("%d", &option);

        if(option == 1)
        {
            printf("\nPlease enter a value in Pounds: ");
            scanf("%f", &value);
            printf("\n%.2f Pounds is %.2f Kilograms\n", value, value * 0.453592);
        }
        else if(option == 2)
        {
            printf("\nPlease enter a value in Kilograms: ");
            scanf("%f", &value);
            printf("\n%.2f Kilograms is %.2f Pounds\n", value, value / 0.453592);
        }
        else
        {
            printf("\nInvalid option, please try again.\n");
        }
    }
    else
    {
        printf("\nInvalid option, please try again.\n");
    }

    printf("\nThank you for using the Exciting Unit Converter!\n");
    return 0;
}