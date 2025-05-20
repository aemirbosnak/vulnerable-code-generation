//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct
{
    char name[20];
    float celsius;
    float fahrenheit;
    float kelvin;
}unit;

void main()
{
    unit u1,u2;
    char choice,ch;
    int i;
    printf("Enter the temperature value: ");
    scanf("%f",&u1.celsius);
    printf("Enter the unit of temperature (C/F/K): ");
    scanf(" %c",&choice);
    getchar();
    switch(choice)
    {
        case 'C':
        case 'c':
            printf("The temperature in Celsius is: %.2f",u1.celsius);
            printf("\nThe temperature in Fahrenheit is: %.2f",(u1.celsius*9/5)+32);
            printf("\nThe temperature in Kelvin is: %.2f",u1.celsius+273.15);
            break;
        case 'F':
        case 'f':
            u1.fahrenheit = (u1.celsius*9/5)+32;
            printf("The temperature in Celsius is: %.2f",(u1.fahrenheit-32)*5/9);
            printf("\nThe temperature in Fahrenheit is: %.2f",u1.fahrenheit);
            printf("\nThe temperature in Kelvin is: %.2f",(u1.fahrenheit+459.67)*5/9);
            break;
        case 'K':
        case 'k':
            u1.kelvin = u1.celsius+273.15;
            printf("The temperature in Celsius is: %.2f",u1.kelvin-273.15);
            printf("\nThe temperature in Fahrenheit is: %.2f",(u1.kelvin-273.15)*9/5+32);
            printf("\nThe temperature in Kelvin is: %.2f",u1.kelvin);
            break;
        default:
            printf("Invalid unit of temperature!");
    }
    printf("\nDo you want to convert another temperature? (Y/N) ");
    scanf(" %c",&ch);
    getchar();
    if(ch=='Y' || ch=='y')
    {
        main();
    }
    else
    {
        exit(0);
    }
}