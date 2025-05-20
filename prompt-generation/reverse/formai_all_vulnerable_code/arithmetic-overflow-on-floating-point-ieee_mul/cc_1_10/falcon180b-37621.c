//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float celsius, fahrenheit;
    char choice;

    // Cheerful welcome message
    printf("Hello and welcome to the Temperature Converter!\n");
    printf("I'm here to help you convert temperatures from Celsius to Fahrenheit and vice versa.\n");
    printf("Let's get started!\n\n");

    // Loop until user chooses to quit
    while (1) {
        // Display menu options
        printf("Please choose an option:\n");
        printf("C - Convert from Celsius to Fahrenheit\n");
        printf("F - Convert from Fahrenheit to Celsius\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        // Convert Celsius to Fahrenheit
        if (choice == 'C' || choice == 'c') {
            printf("\nEnter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
        }

        // Convert Fahrenheit to Celsius
        else if (choice == 'F' || choice == 'f') {
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
        }

        // Quit program
        else if (choice == 'Q' || choice == 'q') {
            printf("\nThank you for using the Temperature Converter! Have a great day!\n");
            break;
        }

        // Invalid choice
        else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}