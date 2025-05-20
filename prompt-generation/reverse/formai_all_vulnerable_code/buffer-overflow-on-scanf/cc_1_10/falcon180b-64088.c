//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUMBER_OF_LOANS 10

struct loan {
    char name[MAX_STRING_LENGTH];
    double amount;
    double interest_rate;
    int term_in_months;
};

int main() {
    int number_of_loans = 0;
    struct loan loans[MAX_NUMBER_OF_LOANS];

    printf("Welcome to the Mortgage Calculator!\n");
    printf("How many loans do you want to calculate? ");
    scanf("%d", &number_of_loans);

    for (int i = 0; i < number_of_loans; i++) {
        printf("Enter the name of loan %d: ", i + 1);
        scanf("%s", loans[i].name);

        printf("Enter the amount of loan %d: ", i + 1);
        scanf("%lf", &loans[i].amount);

        printf("Enter the interest rate for loan %d (as a decimal): ", i + 1);
        scanf("%lf", &loans[i].interest_rate);

        printf("Enter the term of loan %d in months: ", i + 1);
        scanf("%d", &loans[i].term_in_months);
    }

    printf("\nLoan Summary:\n");
    for (int i = 0; i < number_of_loans; i++) {
        double monthly_payment = loans[i].amount * loans[i].interest_rate / (1 - pow(1 + loans[i].interest_rate, -loans[i].term_in_months));
        double total_interest = loans[i].amount * loans[i].interest_rate * loans[i].term_in_months;

        printf("Loan %d:\n", i + 1);
        printf("Amount: $%.2f\n", loans[i].amount);
        printf("Interest rate: %.2f%%\n", loans[i].interest_rate * 100);
        printf("Term: %d months\n", loans[i].term_in_months);
        printf("Monthly payment: $%.2f\n", monthly_payment);
        printf("Total interest: $%.2f\n", total_interest);
        printf("\n");
    }

    return 0;
}