//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, temp_celsius, temp_fahrenheit;
    char answer;

    printf("Welcome, traveler! You have stumbled upon the Enchanted Converter, a device of immense magical power.\n");

    printf("Please select an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Celsius:");
            scanf("%d", &temp_celsius);

            temp_fahrenheit = (temp_celsius * 9 / 5) + 32;

            printf("The temperature in Fahrenheit is: %d", temp_fahrenheit);

            break;

        case 2:
            printf("Enter the temperature in Fahrenheit:");
            scanf("%d", &temp_fahrenheit);

            temp_celsius = (temp_fahrenheit - 32) * 5 / 9;

            printf("The temperature in Celsius is: %d", temp_celsius);

            break;

        default:
            printf("Invalid selection. Please try again.");
    }

    printf("\nWould you like to continue using the Enchanted Converter? (Y/N): ");
    scanf(" %c", &answer);

    if (answer == 'Y')
    {
        main();
    }
    else
    {
        printf("Thank you for using the Enchanted Converter. May your journey be filled with wonder and delight.");
    }

    return 0;
}