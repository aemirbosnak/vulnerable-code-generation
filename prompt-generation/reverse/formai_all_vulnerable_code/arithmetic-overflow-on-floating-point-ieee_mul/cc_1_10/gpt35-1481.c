//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: high level of detail
#include <stdio.h>

int main() {
    double principal_amount, interest_rate, monthly_payment, balance;
    int num_of_payments;
    
    // Prompt user to enter principal amount, interest rate, number of payments and monthly payment
    printf("Enter principal amount: $");
    scanf("%lf", &principal_amount);
    
    printf("Enter interest rate per year: ");
    scanf("%lf", &interest_rate);
    
    printf("Enter number of payments: ");
    scanf("%d", &num_of_payments);
    
    printf("Enter monthly payment: $");
    scanf("%lf", &monthly_payment);
    
    // Calculate monthly interest rate
    double monthly_interest_rate = interest_rate / 12.0 / 100.0;
    
    // Calculate balance by subtracting monthly payment from principal amount
    balance = principal_amount - monthly_payment;
    
    // Iterate through each payment period
    for (int i = 1; i <= num_of_payments; i++) {
        // Calculate interest for this month
        double interest = balance * monthly_interest_rate;
        
        // Calculate total payment for this month
        double total_payment = interest + monthly_payment;
        
        // Update balance by subtracting total payment
        balance -= total_payment;
        
        // Print out the result for each payment period
        printf("Payment period %d: Interest paid: $%.2lf, Principal paid: $%.2lf, Remaining balance: $%.2lf\n",
               i, interest, monthly_payment - interest, balance);
        
        // Check if balance is less than monthly payment
        if (balance <= monthly_payment) {
            // Final payment calculation
            double final_payment = balance + interest;
            
            // Print out the final result
            printf("Final Payment: Interest paid: $%.2lf, Principal paid: $%.2lf, Remaining balance: $0\n",
                   interest, final_payment - interest);
            
            break;
        }
    }
    
    return 0;
}