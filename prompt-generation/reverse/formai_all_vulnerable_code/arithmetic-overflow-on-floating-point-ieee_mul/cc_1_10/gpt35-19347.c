//FormAI DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double kilometers_to_miles(double kilometers);
double miles_to_kilometers(double miles);

int main()
{
    char choice[10];
    double input, output;
    
    while(1)
    {
        // Print menu and get user input
        printf("-- UNIT CONVERTER --\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kilometers to Miles\n");
        printf("4. Miles to Kilometers\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        fgets(choice, 10, stdin);
        
        // Convert input string to integer
        int option = atoi(choice);
        if(option < 1 || option > 5)
        {
            printf("Invalid choice. Try again.\n");
            continue;
        }
        else if(option == 5)
        {
            // Quit program
            printf("Goodbye!\n");
            break;
        }
        
        printf("Enter input value: ");
        scanf("%lf", &input);
        
        // Perform unit conversion based on user choice
        switch(option)
        {
            case 1:
                output = celsius_to_fahrenheit(input);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", input, output);
                break;
            case 2:
                output = fahrenheit_to_celsius(input);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", input, output);
                break;
            case 3:
                output = kilometers_to_miles(input);
                printf("%.2lf Kilometers = %.2lf Miles\n", input, output);
                break;
            case 4:
                output = miles_to_kilometers(input);
                printf("%.2lf Miles = %.2lf Kilometers\n", input, output);
                break;
        }
    }
    
    return 0;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius)
{
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Kilometers to Miles
double kilometers_to_miles(double kilometers)
{
    return kilometers / 1.609;
}

// Function to convert Miles to Kilometers
double miles_to_kilometers(double miles)
{
    return miles * 1.609;
}