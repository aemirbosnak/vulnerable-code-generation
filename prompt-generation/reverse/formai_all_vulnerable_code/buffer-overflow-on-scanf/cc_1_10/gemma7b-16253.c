//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

int main()
{
    float f_celsius, f_fahrenheit, f_kelvin;
    char choice;

    // Display the menu options
    printf("Enter 'C' for Celsius, 'F' for Fahrenheit, or 'K' for Kelvin: ");
    scanf(" %c", &choice);

    // Get the input temperature
    printf("Enter the temperature: ");
    scanf(" %f", &f_celsius);

    // Convert the temperature
    switch (choice)
    {
        case 'C':
            f_fahrenheit = (f_celsius * 9.0 / 5.0) + 32.0;
            f_kelvin = f_celsius + 273.15;
            break;
        case 'F':
            f_celsius = (f_fahrenheit - 32.0) * 5.0 / 9.0;
            f_kelvin = (f_fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
            break;
        case 'K':
            f_celsius = f_kelvin - 273.15;
            f_fahrenheit = (f_kelvin - 273.15) * 9.0 / 5.0 + 32.0;
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    // Display the converted temperature
    printf("The converted temperature is: ");
    switch (choice)
    {
        case 'C':
            printf("%f degrees Celsius.\n", f_celsius);
            break;
        case 'F':
            printf("%f degrees Fahrenheit.\n", f_fahrenheit);
            break;
        case 'K':
            printf("%f degrees Kelvin.\n", f_kelvin);
            break;
    }

    return 0;
}