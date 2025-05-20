//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: retro
#include <stdio.h>
#include <math.h>

int main()
{
    double celsius, fahrenheit, kelvin;
    char choice;

    do
    {
        printf("Enter temperature type (c/f/k): ");
        scanf("%c", &choice);

        switch(choice)
        {
            case 'c':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &celsius);
                fahrenheit = (celsius * 9/5) + 32;
                kelvin = celsius + 273.15;
                printf("%.2lf Celsius = %.2lf Fahrenheit = %.2lf Kelvin", celsius, fahrenheit, kelvin);
                break;

            case 'f':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &fahrenheit);
                celsius = (fahrenheit - 32) * 5/9;
                kelvin = (fahrenheit + 459.67) * 5/9;
                printf("%.2lf Fahrenheit = %.2lf Celsius = %.2lf Kelvin", fahrenheit, celsius, kelvin);
                break;

            case 'k':
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &kelvin);
                celsius = kelvin - 273.15;
                fahrenheit = (kelvin * 9/5) - 459.67;
                printf("%.2lf Kelvin = %.2lf Celsius = %.2lf Fahrenheit", kelvin, celsius, fahrenheit);
                break;

            default:
                printf("Invalid choice! Please enter again.\n");
        }

        printf("\nDo you want to convert another temperature? (y/n): ");
        scanf("%c", &choice);
    }
    while(choice == 'y' || choice == 'Y');

    return 0;
}