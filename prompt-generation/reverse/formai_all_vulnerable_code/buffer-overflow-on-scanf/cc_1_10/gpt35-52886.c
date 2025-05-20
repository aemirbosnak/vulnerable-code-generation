//FormAI DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

float convertToCelsius(float num);
float convertToFahrenheit(float num);
float convertToKelvin(float num);

int main()
{
    int choice;
    float num, result;

    while(1)
    {   
        printf("\n********** Unit Converter **********\n");
        printf("Options:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Fahrenheit to Kelvin\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("7. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 7)
        {
            printf("Exiting program...\n");
            exit(0);
        }

        printf("Enter the number to convert: ");
        scanf("%f", &num);

        switch(choice)
        {
            case 1:
                result = convertToFahrenheit(num);
                printf("%.2f Celsius equals %.2f Fahrenheit\n", num, result);
                break;

            case 2:
                result = convertToCelsius(num);
                printf("%.2f Fahrenheit equals %.2f Celsius\n", num, result);
                break;

            case 3:
                result = convertToKelvin(num);
                printf("%.2f Celsius equals %.2f Kelvin\n", num, result);
                break;

            case 4:
                result = convertToCelsius(num);
                printf("%.2f Kelvin equals %.2f Celsius\n", num, result);
                break;

            case 5:
                result = convertToKelvin(num);
                printf("%.2f Fahrenheit equals %.2f Kelvin\n", num, result);
                break;

            case 6:
                result = convertToFahrenheit(num);
                printf("%.2f Kelvin equals %.2f Fahrenheit\n", num, result);
                break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

float convertToCelsius(float num)
{
    return (num - 32) * 5 / 9;
}

float convertToFahrenheit(float num)
{
    return num * 9 / 5 + 32;
}

float convertToKelvin(float num)
{
    return num + 273.15;
}