//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TEMP_MIN -273.15
#define TEMP_MAX 1000.0

int main()
{
    char input[100];
    double temperature;
    int choice;

    printf("Welcome to the Medieval Temperature Monitor!\n");
    printf("Please enter the temperature you wish to monitor (in Celsius): ");
    scanf("%lf", &temperature);

    while(1)
    {
        printf("\n");
        printf("1. Convert to Fahrenheit\n");
        printf("2. Convert to Kelvin\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                temperature = (temperature * 1.8) + 32;
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, temperature);
                break;

            case 2:
                temperature = temperature + TEMP_MIN;
                printf("%.2lf degrees Celsius is equal to %.2lf Kelvin.\n", temperature, temperature);
                break;

            case 3:
                printf("Thank you for using the Medieval Temperature Monitor!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}