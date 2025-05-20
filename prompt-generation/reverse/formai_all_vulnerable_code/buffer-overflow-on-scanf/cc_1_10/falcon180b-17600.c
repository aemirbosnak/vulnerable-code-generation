//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char input[20];
    float celsius, fahrenheit;
    int choice;

    // Initialize variables
    strcpy(input, "0");
    celsius = 0;
    fahrenheit = 0;

    // Loop until user decides to quit
    while (strcmp(input, "quit")!= 0)
    {
        // Display menu
        printf("\n");
        printf("Temperature Converter\n");
        printf("----------------------\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("\n");

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Convert Celsius to Fahrenheit
        if (choice == 1)
        {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9 / 5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
        }

        // Convert Fahrenheit to Celsius
        else if (choice == 2)
        {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5 / 9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
        }

        // Exit program
        else if (choice == 3)
        {
            strcpy(input, "quit");
        }

        // Invalid choice
        else
        {
            printf("Invalid choice. Please try again.\n");
        }

        // Pause program
        system("pause");
    }

    // Exit program
    return 0;
}