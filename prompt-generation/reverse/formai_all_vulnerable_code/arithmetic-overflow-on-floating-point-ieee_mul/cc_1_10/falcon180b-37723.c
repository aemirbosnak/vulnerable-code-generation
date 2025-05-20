//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    char input[100];
    char *endptr;
    double temp;
    int choice;

    printf("Welcome to the Cyberpunk Temperature Converter!\n\n");
    printf("Enter a temperature (in Celsius, Fahrenheit or Kelvin) and press Enter:\n");
    scanf("%s", input);

    temp = strtod(input, &endptr);
    if (*endptr!= '\0')
    {
        printf("Invalid input. Please enter a valid temperature.\n");
        return 1;
    }

    printf("Select the unit you want to convert to:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            temp -= 273.15;
            printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit or %.2lf Kelvin.\n", temp, temp * 9 / 5 + 32, temp + 273.15);
            break;
        case 2:
            temp = (temp - 32) * 5 / 9;
            printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius or %.2lf Kelvin.\n", temp, temp + 273.15, temp * 9 / 5 + 32);
            break;
        case 3:
            temp -= 273.15;
            printf("%.2lf Kelvin is %.2lf degrees Celsius or %.2lf degrees Fahrenheit.\n", temp, temp + 273.15, temp * 9 / 5 + 32);
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            return 1;
    }

    return 0;
}