//FormAI DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include<stdio.h>

float Celsius_to_Fahrenheit(float temperature)
{
    float result = (temperature * 9/5) + 32;
    return result;
}

float Fahrenheit_to_Celsius(float temperature)
{
    float result = (temperature - 32) * 5/9;
    return result;
}

int main()
{
    int choice = 0;
    float temperature = 0;

    while(1)
    {
        printf("Please choose an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("%.2fC = %.2fF\n\n", temperature, Celsius_to_Fahrenheit(temperature));
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("%.2fF = %.2fC\n\n", temperature, Fahrenheit_to_Celsius(temperature));
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}