//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a number
int isNumber(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the monthly payment
double calculateMonthlyPayment(double principal, double interestRate, int loanTerm) {
    double monthlyInterestRate = interestRate / 1200;
    double monthlyPayment = principal * (monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -loanTerm)));
    return monthlyPayment;
}

int main() {
    // Get the user's input
    char principalStr[100];
    char interestRateStr[100];
    char loanTermStr[100];
    printf("Enter the principal amount: ");
    scanf("%s", principalStr);
    printf("Enter the interest rate (in percent): ");
    scanf("%s", interestRateStr);
    printf("Enter the loan term (in years): ");
    scanf("%s", loanTermStr);

    // Check if the user's input is valid
    if (!isNumber(principalStr) || !isNumber(interestRateStr) || !isNumber(loanTermStr)) {
        printf("Invalid input. Please enter valid numbers.\n");
        return 1;
    }

    // Convert the user's input to doubles
    double principal = atof(principalStr);
    double interestRate = atof(interestRateStr) / 100;
    int loanTerm = atoi(loanTermStr);

    // Calculate the monthly payment
    double monthlyPayment = calculateMonthlyPayment(principal, interestRate, loanTerm);

    // Print the monthly payment
    printf("The monthly payment is: $%.2f\n", monthlyPayment);

    return 0;
}