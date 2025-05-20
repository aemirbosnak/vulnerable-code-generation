//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: dynamic
#include <stdio.h>
#include <math.h>

int main(void) {
    float loanAmount, interestRate, monthlyPayment, totalInterestPaid, amortizationTable[30][4], remainingBalance;
    int loanTerm, numPayments, month, year;
    
    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);
    
    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interestRate);
    
    printf("Enter the loan term (in years): ");
    scanf("%d", &loanTerm);
    
    numPayments = loanTerm * 12;
    
    printf("Enter the monthly payment amount: ");
    scanf("%f", &monthlyPayment);
    
    // Calculate the total interest paid
    totalInterestPaid = numPayments * monthlyPayment - loanAmount;
    
    // Calculate the remaining balance each month for the amortization table
    remainingBalance = loanAmount;
    
    // Create the amortization table
    for (int i = 0; i < numPayments; i++) {
        float interestPaid = remainingBalance * interestRate / 100 / 12;
        float principalPaid = monthlyPayment - interestPaid;
        remainingBalance -= principalPaid;
        
        // Update the remaining balance in the amortization table
        amortizationTable[i][3] = remainingBalance;
        
        // Populate the amortization table
        if (i == 0) {
            month = 1;
            year = 2021;
        } else {
            month++;
            if (month == 13) {
                month = 1;
                year++;
            }
        }
        amortizationTable[i][0] = month;
        amortizationTable[i][1] = year;
        amortizationTable[i][2] = principalPaid;
    }
    
    // Display the results
    printf("\n\nLoan Amount: %.2f\n", loanAmount);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Loan Term: %d years\n", loanTerm);
    printf("Monthly Payment: %.2f\n", monthlyPayment);
    printf("Total Interest Paid: %.2f\n\n", totalInterestPaid);
    
    // Display the amortization table
    printf("---------------------------------------------\n");
    printf("|      Date    | Principal Paid | Remaining  |\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < numPayments; i++) {
        printf("| %02.0f-%d-%d |    $%-9.2f | $%-9.2f |\n", amortizationTable[i][0], (int)amortizationTable[i][1], loanTerm + (int)amortizationTable[i][1] - 1, amortizationTable[i][2], amortizationTable[i][3]);
    }
    printf("---------------------------------------------\n");
    
    return 0;
}