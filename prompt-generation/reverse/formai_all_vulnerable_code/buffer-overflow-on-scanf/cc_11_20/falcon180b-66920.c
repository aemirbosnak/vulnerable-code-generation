//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_TEMP 1000
#define MIN_TEMP -273.15
#define MAX_ITER 1000
#define DELTA_T 0.1
#define DELTA_X 0.1

int main()
{
    int i, j, n;
    double x, x1, x2, fx, fx1, fx2, err, sum, t;
    double temp, celsius, fahrenheit;
    char choice;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please select a unit of measurement:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    scanf("%d", &n);

    if (n == 1)
    {
        printf("Celsius selected.\n");
    }
    else if (n == 2)
    {
        printf("Fahrenheit selected.\n");
    }
    else
    {
        printf("Invalid selection.\n");
        return 0;
    }

    do
    {
        printf("Enter the current temperature: ");
        scanf("%lf", &temp);

        if (n == 1)
        {
            celsius = temp;
            fahrenheit = (temp * 9/5) + 32;
        }
        else if (n == 2)
        {
            fahrenheit = temp;
            celsius = (temp - 32) * 5/9;
        }

        printf("The current temperature in %s is %.2lf degrees.\n", (n == 1)? "Celsius" : "Fahrenheit", temp);

        printf("Do you want to convert the temperature? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            printf("Enter the temperature to convert: ");
            scanf("%lf", &temp);

            if (choice == 'y' || choice == 'Y')
            {
                if (n == 1)
                {
                    fahrenheit = temp;
                    celsius = (temp - 32) * 5/9;
                }
                else if (n == 2)
                {
                    celsius = temp;
                    fahrenheit = (temp * 9/5) + 32;
                }

                printf("%.2lf %s is equal to %.2lf %s.\n", temp, (n == 1)? "Celsius" : "Fahrenheit", temp, (n == 1)? "Fahrenheit" : "Celsius");
            }
        }
    } while (TRUE);

    return 0;
}