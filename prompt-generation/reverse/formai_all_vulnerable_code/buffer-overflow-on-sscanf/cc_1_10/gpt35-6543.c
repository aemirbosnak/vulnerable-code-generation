//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to calculate the mortgage payment
float calculateMortgagePayment(float loanAmount, float interestRate, int loanTermInMonths)
{
    // Convert interest rate from annual to monthly
    interestRate /= 1200.0;
    
    // Calculate monthly payment
    float monthlyPayment = (loanAmount * interestRate) / (1 - pow(1 + interestRate, -loanTermInMonths));
    
    return monthlyPayment;
}

// Asynchronous function that prompts user for input and calculates mortgage payment
void getMortgagePayment()
{
    char input[20];
    float loanAmount, interestRate, monthlyPayment;
    int loanTermInMonths;
    bool validInput = false;
    
    // Prompt user for loan amount
    printf("Enter loan amount: ");
    
    // Continuously prompt user until valid input is received
    while(!validInput)
    {
        fgets(input, 20, stdin);
        if(sscanf(input, "%f", &loanAmount) == 1 && loanAmount > 0)
            validInput = true;
        else 
            printf("Invalid input, please enter a positive number: ");
    }
    
    // Reset validInput flag for next prompt
    validInput = false;
    
    // Prompt user for interest rate
    printf("Enter interest rate (APR): ");
    
    // Continuously prompt user until valid input is received
    while(!validInput)
    {
        fgets(input, 20, stdin);
        if(sscanf(input, "%f", &interestRate) == 1 && interestRate > 0)
            validInput = true;
        else 
            printf("Invalid input, please enter a positive number: ");
    }
    
    // Reset validInput flag for next prompt
    validInput = false;
    
    // Prompt user for loan term in months
    printf("Enter loan term (in months): ");
    
    // Continuously prompt user until valid input is received
    while(!validInput)
    {
        fgets(input, 20, stdin);
        if(sscanf(input, "%d", &loanTermInMonths) == 1 && loanTermInMonths > 0)
            validInput = true;
        else 
            printf("Invalid input, please enter a positive integer: ");
    }
    
    // Calculate monthly mortgage payment using asynchronous function
    monthlyPayment = calculateMortgagePayment(loanAmount, interestRate, loanTermInMonths);
    
    // Print calculated monthly payment
    printf("Your monthly mortgage payment is: $%.2f\n", monthlyPayment);
}

int main()
{
    // Call asynchronous function to prompt user for input and calculate mortgage payment
    getMortgagePayment();
    
    return 0;
}