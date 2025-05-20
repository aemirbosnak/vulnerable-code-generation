//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[])
{
    char input[50];
    char choice;
    float celsius, fahrenheit;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please enter the temperature you would like to convert (in Celsius or Fahrenheit): ");
    scanf("%s", input);

    // Check if input is a number
    for (int i = 0; i < strlen(input); i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }
    }

    // Check if input is Celsius or Fahrenheit
    printf("Please enter 'C' to convert from Celsius or 'F' to convert from Fahrenheit: ");
    scanf(" %c", &choice);

    // Convert Celsius to Fahrenheit
    if (choice == 'C' || choice == 'c')
    {
        if (sscanf(input, "%f", &celsius)!= 1)
        {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        fahrenheit = (celsius * 9/5) + 32;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
    }

    // Convert Fahrenheit to Celsius
    else if (choice == 'F' || choice == 'f')
    {
        if (sscanf(input, "%f", &fahrenheit)!= 1)
        {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        celsius = (fahrenheit - 32) * 5/9;
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
    }

    // Invalid input
    else
    {
        printf("Invalid input. Please enter 'C' or 'F'.\n");
        return 1;
    }

    return 0;
}