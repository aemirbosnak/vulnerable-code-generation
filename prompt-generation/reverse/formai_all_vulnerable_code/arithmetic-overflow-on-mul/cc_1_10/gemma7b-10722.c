//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int choice, input, convert, result;
    float f_result;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please select an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%d", &input);

            convert = (input - 32) * 5 / 9;
            result = convert;
            f_result = (float)convert;

            printf("The temperature in Celsius is: %d\n", result);
            printf("The temperature in Celsius (floating-point) is: %.2f\n", f_result);
            break;

        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%d", &input);

            convert = (input * 9 / 5) + 32;
            result = convert;
            f_result = (float)convert;

            printf("The temperature in Fahrenheit is: %d\n", result);
            printf("The temperature in Fahrenheit (floating-point) is: %.2f\n", f_result);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}