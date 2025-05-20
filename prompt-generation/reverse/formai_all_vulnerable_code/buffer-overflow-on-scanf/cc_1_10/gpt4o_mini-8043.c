//GPT-4o-mini DATASET v1.0 Category: Mortgage Calculator ; Style: protected
#include <stdio.h>
#include <math.h>

#define MAX_LOANS 100

typedef struct {
    double principal;
    double annual_rate;
    int years;
} Mortgage;

void print_menu() {
    printf("\nMortgage Calculator");
    printf("\n1. Calculate Monthly Payment");
    printf("\n2. Display All Loans");
    printf("\n3. Exit");
    printf("\nPlease choose an option (1-3): ");
}

double calculate_monthly_payment(Mortgage mortgage) {
    double monthly_rate = mortgage.annual_rate / 100 / 12;
    int number_of_payments = mortgage.years * 12;

    double monthly_payment = (mortgage.principal * monthly_rate) /
                             (1 - pow(1 + monthly_rate, -number_of_payments));

    return monthly_payment;
}

void add_loan(Mortgage loans[], int *loan_count) {
    if (*loan_count >= MAX_LOANS) {
        printf("\nCannot add more loans. Maximum limit reached.\n");
        return;
    }

    Mortgage new_loan;
    printf("Enter the principal amount: ");
    scanf("%lf", &new_loan.principal);
    
    printf("Enter the annual interest rate (%%): ");
    scanf("%lf", &new_loan.annual_rate);
    
    printf("Enter the loan term in years: ");
    scanf("%d", &new_loan.years);

    loans[*loan_count] = new_loan;
    (*loan_count)++;
}

void display_loans(Mortgage loans[], int loan_count) {
    if (loan_count == 0) {
        printf("\nNo loans available.\n");
        return;
    }

    printf("\nList of Loans:\n");
    for (int i = 0; i < loan_count; i++) {
        printf("Loan %d: Principal: %.2f, Annual Rate: %.2f%%, Term: %d years\n",
               i + 1, loans[i].principal, loans[i].annual_rate, loans[i].years);
    }
}

void calculate_and_display_payments(Mortgage loans[], int loan_count) {
    if (loan_count == 0) {
        printf("\nNo loans available to calculate payments.\n");
        return;
    }

    printf("\nMonthly Payments:\n");
    for (int i = 0; i < loan_count; i++) {
        double monthly_payment = calculate_monthly_payment(loans[i]);
        printf("Loan %d: Monthly Payment: %.2f\n", i + 1, monthly_payment);
    }
}

int main() {
    Mortgage loans[MAX_LOANS];
    int loan_count = 0;
    int choice;

    while (1) {
        print_menu();
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculate_and_display_payments(loans, loan_count);
                break;
            case 2:
                display_loans(loans, loan_count);
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}