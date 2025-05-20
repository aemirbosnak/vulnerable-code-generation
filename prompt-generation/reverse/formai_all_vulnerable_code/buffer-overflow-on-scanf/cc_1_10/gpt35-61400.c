//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Function prototypes
void displayInstructions();
void doCalculations(char operation, double num1, double num2);

int main()
{
    char input[50];
    double num1, num2;
    char operation;

    displayInstructions(); //Display the instructions

    while(1) //Keep running until user exits
    {
        printf("Enter an operation: ");
        scanf("%s", input);

        if(strcmp(input, "exit") == 0) //If user wants to exit
        {
            printf("Good bye!\n");
            break;
        }
        else if(strcmp(input, "+") == 0 || strcmp(input, "-") == 0 || strcmp(input, "*") == 0 || strcmp(input, "/") == 0) //If user entered a valid operation
        {
            operation = input[0]; //Save the operation

            printf("Enter first number: ");
            scanf("%lf", &num1);

            printf("Enter second number: ");
            scanf("%lf", &num2);

            doCalculations(operation, num1, num2); //Do the calculations
        }
        else //If user entered an invalid operation
        {
            printf("Invalid operation. Please try again.\n");
        }
    }

    return 0;
}

void displayInstructions()
{
    //Display the instructions
    printf("Welcome to the Medieval Calculator!\n");
    printf("This calculator can perform the following operations:\n");
    printf("+ - Addition\n");
    printf("- - Subtraction\n");
    printf("* - Multiplication\n");
    printf("/ - Division\n\n");
}

void doCalculations(char operation, double num1, double num2)
{
    double result;

    //Perform calculations based on the operation
    switch(operation)
    {
        case '+':
            result = num1 + num2;
            printf("The sum of %.2lf and %.2lf is %.2lf.\n\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("The difference between %.2lf and %.2lf is %.2lf.\n\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("The product of %.2lf and %.2lf is %.2lf.\n\n", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) //If user is dividing by 0
            {
                printf("Error: cannot divide by zero.\n\n");
            }
            else
            {
                result = num1 / num2;
                printf("%.2lf divided by %.2lf is %.2lf.\n\n", num1, num2, result);
            }
            break;
    }
}