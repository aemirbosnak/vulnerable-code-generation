//FormAI DATASET v1.0 Category: Calculator ; Style: content
// Welcome to the unique C Calculator program!
// This calculator allows you to perform basic arithmetic calculations and perform conversions between various units.

#include <stdio.h> // include standard input/output library

int main() // main function
{
    float num1, num2, result; // declare variables for input and output
    
    char operator; // declare operator variable for arithmetic operations
    
    int choice; // declare choice variable for menu selection
    
    printf("Welcome to the C Calculator Program!\n\n"); // print welcome message and new line
    
    printf("Please select an option from the menu below:\n"); // print menu message
    
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Convert Celsius to Fahrenheit\n6. Convert Fahrenheit to Celsius\n"); // print menu options
    
    scanf("%d", &choice); // read user choice input
    
    switch(choice) // switch statement for menu options
    {
        // Addition
        case 1:
            printf("Enter the first number:\n"); // prompt user for first number
            scanf("%f", &num1); // read first number input
            printf("Enter the second number:\n"); // prompt user for second number
            scanf("%f", &num2); // read second number input
            result = num1 + num2; // perform addition operation
            printf("The sum is %.2f.\n", result); // print result to two decimal places
            break; // exit switch statement
            
        // Subtraction
        case 2:
            printf("Enter the first number:\n"); // prompt user for first number
            scanf("%f", &num1); // read first number input
            printf("Enter the second number:\n"); // prompt user for second number
            scanf("%f", &num2); // read second number input
            result = num1 - num2; // perform subtraction operation
            printf("The difference is %.2f.\n", result); // print result to two decimal places
            break; // exit switch statement
        
        // Multiplication
        case 3:
            printf("Enter the first number:\n"); // prompt user for first number
            scanf("%f", &num1); // read first number input
            printf("Enter the second number:\n"); // prompt user for second number
            scanf("%f", &num2); // read second number input
            result = num1 * num2; // perform multiplication operation
            printf("The product is %.2f.\n", result); // print result to two decimal places
            break; // exit switch statement
        
        // Division
        case 4:
            printf("Enter the first number:\n"); // prompt user for first number
            scanf("%f", &num1); // read first number input
            printf("Enter the second number:\n"); // prompt user for second number
            scanf("%f", &num2); // read second number input
            
            if(num2 == 0) // check for divide by zero error
            {
                printf("Error: divide by zero.\n"); // print error message
            }
            else
            {
                result = num1 / num2; // perform division operation
                printf("The quotient is %.2f.\n", result); // print result to two decimal places
            }
            break; // exit switch statement
            
        // Celsius to Fahrenheit Conversion
        case 5:
            printf("Enter the temperature in Celsius:\n"); // prompt user for temperature input
            scanf("%f", &num1); // read temperature input
            
            result = (num1 * 1.8) + 32; // perform Celsius to Fahrenheit conversion
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", num1, result); // print result to two decimal places
            break; // exit switch statement
            
        // Fahrenheit to Celsius Conversion
        case 6:
            printf("Enter the temperature in Fahrenheit:\n"); // prompt user for temperature input
            scanf("%f", &num1); // read temperature input
            
            result = (num1 - 32) / 1.8; // perform Fahrenheit to Celsius conversion
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", num1, result); // print result to two decimal places
            break; // exit switch statement
        
        // Invalid Option
        default:
            printf("Invalid option selected.\n"); // print error message for invalid option
            break; // exit switch statement
    }
    
    printf("Thank you for using the C Calculator Program!\n"); // print farewell message
    
    return 0; // exit program
}