//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment, balance;
    int years, months, total_months;

    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);

    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter the number of years: ");
    scanf("%d", &years);

    printf("Enter the monthly payment: ");
    scanf("%f", &monthly_payment);

    total_months = years * 12;
    balance = loan_amount;

    printf("\nYear\tMonth\tBalance\n");

    for(int i = 1; i <= total_months; i++) {
        months = i % 12;

        if(months == 1) {
            printf("%d\t%d\t%.2f\n", (i - 1) / 12, months - 1, balance);
        }
        
        float monthly_interest = (interest_rate / 12) / 100;
        float interest_payment = balance * monthly_interest;
        float principal_payment = monthly_payment - interest_payment;

        if(principal_payment > balance) {
            principal_payment = balance;
            monthly_payment = balance + interest_payment;
        }

        balance -= principal_payment;

        if(balance <= 0) {
            balance = 0;
            printf("%d\t%d\t%.2f\n", i / 12, months, balance);
            break;
        }

        printf("%d\t%d\t%.2f\n", i / 12, months, balance);
    }

    return 0;
}