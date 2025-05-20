//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define MAX_CONVERT 100

int main()
{
    double fahrenheit, celsius, conversion_factor, converted_celsius;
    int choice, i;

    // Display menu options
    printf("Enter 1 for Fahrenheit to Celsius conversion.\n");
    printf("Enter 2 for Celsius to Fahrenheit conversion.\n");

    // Get the user's choice
    scanf("Enter your choice: ", &choice);

    // Calculate conversion factor based on user's choice
    switch (choice)
    {
        case 1:
            conversion_factor = 5 / 9.0;
            break;
        case 2:
            conversion_factor = 9 / 5.0;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Get the user's input
    printf("Enter the temperature: ");
    scanf("%lf", &fahrenheit);

    // Convert the temperature
    converted_celsius = (fahrenheit - 32) * conversion_factor;

    // Display the converted temperature
    printf("The converted temperature is: %.2lf Celsius.\n", converted_celsius);

    // Repeat for multiple conversions (optional)
    printf("Do you want to convert another temperature? (Y/N): ");
    scanf("Enter your answer: ", &i);

    if (i == 'Y')
    {
        main();
    }

    return 0;
}