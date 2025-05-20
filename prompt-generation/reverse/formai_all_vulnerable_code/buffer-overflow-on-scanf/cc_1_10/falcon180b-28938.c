//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[20];
    int celsius, fahrenheit;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter your temperature in Celsius: ");
    scanf("%s", input);

    // Check if input is valid
    if (input[0] == '-') {
        celsius = atoi(input);
    }
    else {
        printf("Invalid input! Please enter a valid temperature in Celsius.\n");
        return 0;
    }

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9/5) + 32;

    // Print results
    printf("Your temperature in Celsius is: %d\n", celsius);
    printf("Your temperature in Fahrenheit is: %d\n", fahrenheit);

    // Ask user if they want to convert another temperature
    printf("Do you want to convert another temperature? (y/n) ");
    scanf(" %c", &choice);

    // Loop until user chooses to quit
    while (choice == 'y' || choice == 'Y') {
        printf("Enter your temperature in Celsius: ");
        scanf("%s", input);

        // Check if input is valid
        if (input[0] == '-') {
            celsius = atoi(input);
        }
        else {
            printf("Invalid input! Please enter a valid temperature in Celsius.\n");
            return 0;
        }

        // Convert Celsius to Fahrenheit
        fahrenheit = (celsius * 9/5) + 32;

        // Print results
        printf("Your temperature in Celsius is: %d\n", celsius);
        printf("Your temperature in Fahrenheit is: %d\n", fahrenheit);

        // Ask user if they want to convert another temperature
        printf("Do you want to convert another temperature? (y/n) ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the Temperature Converter! Have a great day!\n");

    return 0;
}