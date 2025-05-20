//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

int main()
{
    float amount, rate, monthly_payment, principal_paid, interest_paid, total_principal_paid, total_interest_paid, balance;

    char input[MAX_INPUT_SIZE];
    char *token;

    printf("Mortgage Calculator\n\n");

    printf("Loan Amount: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    amount = strtof(input, NULL);

    printf("Annual Interest Rate: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    rate = strtof(input, NULL);

    printf("Monthly Payment: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    monthly_payment = strtof(input, NULL);

    printf("\n");

    printf("Month\tBalance\t\tPayment\t\tPrincipal\tInterest\tTotal Principal\tTotal Interest\n");

    balance = amount;
    total_principal_paid = 0;
    total_interest_paid = 0;

    int month;
    for (month = 1; balance > 0; month++)
    {
        interest_paid = balance * rate / 12;
        principal_paid = monthly_payment - interest_paid;

        if (principal_paid > balance)
        {
            principal_paid = balance;
            monthly_payment = principal_paid + interest_paid;
        }

        total_principal_paid += principal_paid;
        total_interest_paid += interest_paid;
        balance -= principal_paid;

        printf("%d\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\n", month, balance, monthly_payment, principal_paid, interest_paid, total_principal_paid, total_interest_paid);
    }

    printf("\n");
    printf("It will take %d months to pay off the mortgage.\n", month-1);
    printf("Total paid:\n");
    printf("Principal: %8.2f\n", total_principal_paid);
    printf("Interest: %8.2f\n", total_interest_paid);
    printf("Total: %8.2f\n", total_principal_paid + total_interest_paid);

    return 0;
}