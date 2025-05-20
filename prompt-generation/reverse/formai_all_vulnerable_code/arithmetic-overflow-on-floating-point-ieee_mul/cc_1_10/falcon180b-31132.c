//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <wchar.h>

#define MAX_LINE 1000
#define MAX_NUMBERS 100
#define MAX_WORD 20

char input[MAX_LINE];
char *token;
int count;

double celsius_to_fahrenheit(double celsius)
{
    return (celsius * 1.8) + 32;
}

double fahrenheit_to_celsius(double fahrenheit)
{
    return (fahrenheit - 32) / 1.8;
}

int main()
{
    setlocale(LC_ALL, "");
    printf("Welcome to the Temperature Converter!\n\n");
    while (1)
    {
        printf("Please enter a temperature in Celsius or Fahrenheit and press enter:\n");
        fgets(input, MAX_LINE, stdin);
        token = strtok(input, " ");
        count = 0;
        while (token!= NULL)
        {
            if (isdigit(token[0]))
            {
                if (count == 0)
                {
                    double celsius = atof(token);
                    double fahrenheit = celsius_to_fahrenheit(celsius);
                    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
                }
                else if (count == 1)
                {
                    double fahrenheit = atof(token);
                    double celsius = fahrenheit_to_celsius(fahrenheit);
                    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
                }
            }
            else if (isalpha(token[0]))
            {
                printf("Invalid input. Please enter a temperature in Celsius or Fahrenheit.\n");
                break;
            }
            count++;
            token = strtok(NULL, " ");
        }
        if (count!= 2)
        {
            printf("Invalid input. Please enter a temperature in Celsius or Fahrenheit.\n");
        }
    }
    return 0;
}