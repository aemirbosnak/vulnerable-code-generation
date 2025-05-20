//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, input, output;
    float f_input, f_output;

    // Welcome the traveler
    printf("Welcome to the Ancient Temperature Converter!\n");

    // Present the options
    printf("Please select an option:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");

    // Get the user's choice
    scanf("Enter your choice: ", &choice);

    // Switch statement to handle the user's choice
    switch (choice)
    {
        case 1:
            // Get the Fahrenheit input
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &f_input);

            // Convert Fahrenheit to Celsius
            f_output = (f_input - 32) * 5 / 9;

            // Print the Celsius output
            printf("The temperature in Celsius is: %.2f\n", f_output);

            break;
        case 2:
            // Get the Celsius input
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &f_input);

            // Convert Celsius to Fahrenheit
            f_output = (f_input * 9 / 5) + 32;

            // Print the Fahrenheit output
            printf("The temperature in Fahrenheit is: %.2f\n", f_output);

            break;
        default:
            // Invalid choice
            printf("Invalid choice. Please try again.\n");
    }

    // Thank the traveler
    printf("Thank you for using the Ancient Temperature Converter!\n");

    return 0;
}