//FormAI DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float celsius, fahrenheit;
    int choice;
    printf("Welcome to Temperature Converter!\n\n");

    while (1)
    {
        printf("Select your choice:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);

            fahrenheit = (celsius * 9 / 5) + 32;

            printf("%.2f Celsius = %.2f Fahrenheit\n\n", celsius, fahrenheit);
        }

        else if (choice == 2)
        {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);

            celsius = (fahrenheit - 32) * 5 / 9;

            printf("%.2f Fahrenheit = %.2f Celsius\n\n", fahrenheit, celsius);
        }

        else if (choice == 3)
        {
            printf("Exiting Temperature Converter. Goodbye!\n");
            exit(0);
        }

        else
        {
            printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}