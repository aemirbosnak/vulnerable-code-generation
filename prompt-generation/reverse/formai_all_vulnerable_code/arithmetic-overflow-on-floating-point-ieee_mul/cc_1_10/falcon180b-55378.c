//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

// Function prototypes
int isNumber(char *str);
double celsiusToFahrenheit(double c);
double fahrenheitToCelsius(double f);

int main()
{
    char input[MAX];
    double celsius, fahrenheit;
    int choice;

    do
    {
        printf("Enter a temperature in Celsius or Fahrenheit: ");
        fgets(input, MAX, stdin);

        if (isNumber(input))
        {
            celsius = atof(input);

            printf("Enter 1 to convert Celsius to Fahrenheit or 2 to convert Fahrenheit to Celsius: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    fahrenheit = celsiusToFahrenheit(celsius);
                    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
                    break;

                case 2:
                    fahrenheit = atof(input);
                    celsius = fahrenheitToCelsius(fahrenheit);
                    printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
                    break;

                default:
                    printf("Invalid choice.\n");
            }
        }
        else
        {
            printf("Invalid input.\n");
        }

    } while (TRUE);

    return 0;
}

// Function to check if a string contains only numbers
int isNumber(char *str)
{
    int i, n;

    for (i = 0, n = 0; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return FALSE;
        }
        n++;
    }

    if (n == 0)
    {
        return FALSE;
    }

    return TRUE;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double c)
{
    return (c * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double f)
{
    return (f - 32.0) * 5.0 / 9.0;
}