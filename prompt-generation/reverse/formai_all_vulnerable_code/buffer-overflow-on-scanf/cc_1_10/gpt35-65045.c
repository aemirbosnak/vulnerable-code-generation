//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ada Lovelace
/* This program converts temperature from Celsius to Fahrenheit and vice versa
   in a very simple way, demonstrating the functionality of conditional statements
   and arithmetic operations in C. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variable declaration
    float temp_c, temp_f;
    int choice;

    // Displaying menu options
    printf("Temperature converter\n");
    printf("---------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");

    // Getting user's choice
    printf("\nEnter your choice (1-3): ");
    scanf("%d", &choice);

    // Conditional statement based on user's choice
    if(choice == 1)
    {
        // Getting temperature in Celsius from user
        printf("\nEnter temperature in Celsius: ");
        scanf("%f", &temp_c);

        // Converting Celsius to Fahrenheit using formula
        temp_f = (9 * temp_c / 5) + 32;

        // Displaying the result
        printf("\nTemperature in Fahrenheit: %.2f", temp_f);
    }
    else if(choice == 2)
    {
        // Getting temperature in Fahrenheit from user
        printf("\nEnter temperature in Fahrenheit: ");
        scanf("%f", &temp_f);

        // Converting Fahrenheit to Celsius using formula
        temp_c = (temp_f - 32) * 5 / 9;

        // Displaying the result
        printf("\nTemperature in Celsius: %.2f", temp_c);
    }
    else if(choice == 3)
    {
        // Exiting the program
        printf("\nExiting the program...");
        exit(0);
    }
    else
    {
        // Handling invalid choice
        printf("\nInvalid choice, please try again!");
    }

    return 0;
}