//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int choice;
    float fahrenheit, celsius, kelvin;

    printf("Enter your choice:\n1. Convert Fahrenheit to Celsius\n2. Convert Celsius to Fahrenheit\n3. Convert Celsius to Kelvin\n4. Convert Kelvin to Celsius\n5. Convert Fahrenheit to Kelvin\n6. Convert Kelvin to Fahrenheit\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f",&fahrenheit);
            celsius = (fahrenheit - 32) / 1.8;
            printf("Equivalent temperature in Celsius: %.2f\n",celsius);
            break;

        case 2:
            printf("Enter temperature in Celsius: ");
            scanf("%f",&celsius);
            fahrenheit = (celsius * 1.8) + 32;
            printf("Equivalent temperature in Fahrenheit: %.2f\n",fahrenheit);
            break;

        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f",&celsius);
            kelvin = celsius + 273.15;
            printf("Equivalent temperature in Kelvin: %.2f\n",kelvin);
            break;

        case 4:
            printf("Enter temperature in Celsius: ");
            scanf("%f",&celsius);
            kelvin = celsius + 273.15;
            printf("Equivalent temperature in Kelvin: %.2f\n",kelvin);
            break;

        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f",&fahrenheit);
            kelvin = (fahrenheit + 459.67) * 5/9;
            printf("Equivalent temperature in Kelvin: %.2f\n",kelvin);
            break;

        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f",&kelvin);
            fahrenheit = (kelvin * 9/5) - 459.67;
            printf("Equivalent temperature in Fahrenheit: %.2f\n",fahrenheit);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}