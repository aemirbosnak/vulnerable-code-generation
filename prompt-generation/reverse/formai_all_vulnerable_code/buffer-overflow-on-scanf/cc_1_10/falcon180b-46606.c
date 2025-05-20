//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include<stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
    float celsius, fahrenheit, kelvin;
    int choice;

    printf("Enter your choice:\n1. Convert Celsius to Fahrenheit\n2. Convert Celsius to Kelvin\n3. Convert Fahrenheit to Celsius\n4. Convert Fahrenheit to Kelvin\n5. Convert Kelvin to Celsius\n6. Convert Kelvin to Fahrenheit\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f",&celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n",celsius,fahrenheit);
            break;

        case 2:
            printf("Enter temperature in Celsius: ");
            scanf("%f",&celsius);
            kelvin = celsius + 273.15;
            printf("%.2f degrees Celsius is equal to %.2f Kelvin.\n",celsius,kelvin);
            break;

        case 3:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f",&fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n",fahrenheit,celsius);
            break;

        case 4:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f",&fahrenheit);
            kelvin = (fahrenheit + 459.67) * 5/9;
            printf("%.2f degrees Fahrenheit is equal to %.2f Kelvin.\n",fahrenheit,kelvin);
            break;

        case 5:
            printf("Enter temperature in Kelvin: ");
            scanf("%f",&kelvin);
            celsius = kelvin - 273.15;
            printf("%.2f Kelvin is equal to %.2f degrees Celsius.\n",kelvin,celsius);
            break;

        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f",&kelvin);
            fahrenheit = (kelvin * 9/5) - 459.67;
            printf("%.2f Kelvin is equal to %.2f degrees Fahrenheit.\n",kelvin,fahrenheit);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}