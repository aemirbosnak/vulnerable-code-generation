//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

int convertToFahrenheit(int celsius)
{
    return (celsius * 9 / 5) + 32;
}

int convertToCelsius(int fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

int main()
{
    int option, temperature;

    printf("\n\n");
    printf("**********************************************\n");
    printf("* Welcome to the Temperature Converter!       *\n");
    printf("**********************************************\n\n");

    while (1)
    {
        printf("Please select an option:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch (option)
        {
            case 1: // Convert Celsius to Fahrenheit
            {
                printf("Enter the temperature in Celsius: ");
                scanf("%d", &temperature);
                printf("\n%d degree Celsius is equal to %d degree Fahrenheit.\n\n", temperature, convertToFahrenheit(temperature));
                break;
            }

            case 2: // Convert Fahrenheit to Celsius
            {
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%d", &temperature);
                printf("\n%d degree Fahrenheit is equal to %d degree Celsius.\n\n", temperature, convertToCelsius(temperature));
                break;
            }

            case 3: // Exit
            {
                printf("Thank you for using the Temperature Converter!\n\n");
                exit(0);
                break;
            }

            default:
            {
                printf("Invalid option! Please select a valid option.\n\n");
                break;
            }
        }
    }

    return 0;
}