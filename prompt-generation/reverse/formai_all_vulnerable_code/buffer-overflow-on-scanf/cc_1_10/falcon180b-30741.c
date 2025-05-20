//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: genious
#include <stdio.h>

int main()
{
    char choice;
    float celsius, fahrenheit, kelvin;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose a temperature unit:\n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    scanf("%c", &choice);

    switch(choice)
    {
        case '1':
            printf("Please enter the temperature in Celsius:\n");
            scanf("%f", &celsius);

            fahrenheit = (celsius * 9/5) + 32;
            kelvin = celsius + 273.15;

            printf("%.2f Celsius = %.2f Fahrenheit = %.2f Kelvin\n", celsius, fahrenheit, kelvin);

            break;

        case '2':
            printf("Please enter the temperature in Fahrenheit:\n");
            scanf("%f", &fahrenheit);

            celsius = (fahrenheit - 32) * 5/9;
            kelvin = (fahrenheit + 459.67) * 5/9;

            printf("%.2f Fahrenheit = %.2f Celsius = %.2f Kelvin\n", fahrenheit, celsius, kelvin);

            break;

        case '3':
            printf("Please enter the temperature in Kelvin:\n");
            scanf("%f", &kelvin);

            celsius = kelvin - 273.15;
            fahrenheit = (kelvin * 9/5) - 459.67;

            printf("%.2f Kelvin = %.2f Celsius = %.2f Fahrenheit\n", kelvin, celsius, fahrenheit);

            break;

        default:
            printf("Invalid choice. Please choose a valid temperature unit.\n");
    }

    return 0;
}