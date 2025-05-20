//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    char input[100];
    float temperature;
    int choice;

    printf("Enter temperature: ");
    scanf("%s", input);

    while (1)
    {
        printf("Choose option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kelvin to Celsius\n");
        printf("4. Celsius to Kelvin\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (sscanf(input, "%fC", &temperature)!= 1)
                {
                    printf("Invalid input.\n");
                }
                else
                {
                    printf("%.2fC = %.2fF\n", temperature, (temperature * 9 / 5) + 32);
                }
                break;

            case 2:
                if (sscanf(input, "%fF", &temperature)!= 1)
                {
                    printf("Invalid input.\n");
                }
                else
                {
                    printf("%.2fF = %.2fC\n", temperature, (temperature - 32) * 5 / 9);
                }
                break;

            case 3:
                if (sscanf(input, "%fK", &temperature)!= 1)
                {
                    printf("Invalid input.\n");
                }
                else
                {
                    printf("%.2fK = %.2fC\n", temperature, temperature - 273.15);
                }
                break;

            case 4:
                if (sscanf(input, "%fC", &temperature)!= 1)
                {
                    printf("Invalid input.\n");
                }
                else
                {
                    printf("%.2fC = %.2fK\n", temperature, temperature + 273.15);
                }
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}