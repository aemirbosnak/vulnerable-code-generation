//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
void display_menu();

int main()
{
    int choice;
    float temp,result;
    char unit;

    display_menu();

    do{
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter temperature in Celsius: ");
                    scanf("%f",&temp);
                    result=celsius_to_fahrenheit(temp);
                    printf("%.2f Celsius = %.2f Fahrenheit\n",temp,result);
                    break;

            case 2: printf("\nEnter temperature in Fahrenheit: ");
                    scanf("%f",&temp);
                    result=fahrenheit_to_celsius(temp);
                    printf("%.2f Fahrenheit = %.2f Celsius\n",temp,result);
                    break;

            case 3: exit(0);

            default: printf("\nInvalid Choice! Enter again!\n");
                     break;
        }
    }while(choice!=3);

    return 0;
}

void display_menu()
{
    system("clear");

    printf("********TEMPERATURE CONVERTER********\n\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

float celsius_to_fahrenheit(float celsius)
{
    return (celsius*9/5)+32;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit-32)*5/9;
}