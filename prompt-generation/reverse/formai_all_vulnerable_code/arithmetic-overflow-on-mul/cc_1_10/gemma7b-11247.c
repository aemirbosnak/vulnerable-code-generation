//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>
#include <math.h>

int main()
{
    int choice, temp_in, temp_out, unit_in, unit_out;

    printf("Welcome to the Grand Temperature Converter!\n");
    printf("Please select an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Kelvin to Fahrenheit\n");
    printf("4. Fahrenheit to Kelvin\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit:");
            scanf("%d", &temp_in);
            temp_out = (temp_in - 32) * 5 / 9;
            unit_in = 1;
            unit_out = 2;
            break;
        case 2:
            printf("Enter the temperature in Celsius:");
            scanf("%d", &temp_in);
            temp_out = (temp_in * 9 / 5) + 32;
            unit_in = 2;
            unit_out = 1;
            break;
        case 3:
            printf("Enter the temperature in Kelvin:");
            scanf("%d", &temp_in);
            temp_out = temp_in - 273.15;
            unit_in = 3;
            unit_out = 1;
            break;
        case 4:
            printf("Enter the temperature in Fahrenheit:");
            scanf("%d", &temp_in);
            temp_out = (temp_in - 32) * 5 / 9 + 273.15;
            unit_in = 1;
            unit_out = 3;
            break;
        default:
            printf("Invalid choice. Please try again.");
            break;
    }

    printf("The converted temperature is: %d %s", temp_out, unit_out);

    return 0;
}