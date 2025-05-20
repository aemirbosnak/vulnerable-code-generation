//GPT-4o-mini DATASET v1.0 Category: Mortgage Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOANS 10
#define MAX_BUFFER 256

typedef struct {
    char borrower_name[MAX_BUFFER];
    double principal;
    double annual_rate;
    int years;
} Loan;

void clear_screen() {
    printf("\033[H\033[J");  // ANSI escape code to clear screen
}

void print_menu() {
    printf("\nMortgage Calculator\n");
    printf("====================\n");
    printf("1. Add a New Loan\n");
    printf("2. Calculate Monthly Payment\n");
    printf("3. Display All Loans\n");
    printf("4. Exit\n");
}

double calculate_monthly_payment(double principal, double annual_rate, int years) {
    double monthly_rate = annual_rate / 100 / 12;
    int number_of_payments = years * 12;
    return (principal * monthly_rate) / (1 - pow((1 + monthly_rate), -number_of_payments));
}

void add_loan(Loan *loans, int *loan_count) {
    if (*loan_count >= MAX_LOANS) {
        printf("Maximum number of loans reached.\n");
        return;
    }
    
    Loan new_loan;
    
    printf("Enter borrower's name: ");
    fgets(new_loan.borrower_name, MAX_BUFFER, stdin);
    
    printf("Enter loan principal: ");
    scanf("%lf", &new_loan.principal);
    printf("Enter annual interest rate (in percent): ");
    scanf("%lf", &new_loan.annual_rate);
    printf("Enter loan term in years: ");
    scanf("%d", &new_loan.years);
    
    loans[*loan_count] = new_loan;
    (*loan_count)++;
    
    getchar(); // clear the newline character left in the buffer
    printf("Loan added successfully!\n");
}

void calculate_and_display_payments(Loan *loans, int loan_count) {
    if (loan_count == 0) {
        printf("No loans available to calculate payments.\n");
        return;
    }
    
    for (int i = 0; i < loan_count; i++) {
        double monthly_payment = calculate_monthly_payment(loans[i].principal, loans[i].annual_rate, loans[i].years);
        printf("Loan for %s: Monthly Payment: %.2f\n", loans[i].borrower_name, monthly_payment);
    }
}

void display_loans(Loan *loans, int loan_count) {
    if (loan_count == 0) {
        printf("No loans available.\n");
        return;
    }

    printf("\nList of Loans:\n");
    for (int i = 0; i < loan_count; i++) {
        printf("%d. %s", i + 1, loans[i].borrower_name);
        printf("   Principal: %.2f, Rate: %.2f%%, Years: %d\n", loans[i].principal, loans[i].annual_rate, loans[i].years);
    }
}

int main() {
    Loan loans[MAX_LOANS];
    int loan_count = 0;
    int choice;

    do {
        clear_screen();
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear the newline character left in the buffer

        switch (choice) {
            case 1:
                add_loan(loans, &loan_count);
                break;
            case 2:
                calculate_and_display_payments(loans, loan_count);
                break;
            case 3:
                display_loans(loans, loan_count);
                break;
            case 4:
                printf("Exiting the application.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        if (choice != 4) {
            printf("Press Enter to continue...");
            getchar(); // wait for user to press Enter
        }

    } while (choice != 4);

    return 0;
}