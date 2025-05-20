//GPT-4o-mini DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <math.h>

#define MAX_LOANS 10
#define MAX_STR_LEN 100

typedef struct {
    float principal;
    float annualInterestRate;
    int years;
} Loan;

void inputLoanDetails(Loan *loan);
float calculateMonthlyPayment(Loan loan);
void displayLoanDetails(Loan loan, float monthlyPayment);
void displayAmortizationSchedule(Loan loan);

int main() {
    Loan loans[MAX_LOANS];
    int loanCount = 0, choice;

    do {
        printf("Mortgage Calculator\n");
        printf("1. Add a loan\n");
        printf("2. Calculate payments\n");
        printf("3. Display Amortization Schedule\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (loanCount < MAX_LOANS) {
                inputLoanDetails(&loans[loanCount]);
                loanCount++;
            } else {
                printf("Maximum number of loans reached.\n");
            }
            break;

        case 2:
            for (int i = 0; i < loanCount; i++) {
                float monthlyPayment = calculateMonthlyPayment(loans[i]);
                displayLoanDetails(loans[i], monthlyPayment);
            }
            break;

        case 3:
            for (int i = 0; i < loanCount; i++) {
                displayAmortizationSchedule(loans[i]);
            }
            break;

        case 4:
            printf("Exiting the program...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void inputLoanDetails(Loan *loan) {
    printf("Enter loan principal amount: ");
    scanf("%f", &(loan->principal));
    printf("Enter annual interest rate (percentage): ");
    scanf("%f", &(loan->annualInterestRate));
    printf("Enter loan term (in years): ");
    scanf("%d", &(loan->years));
}

float calculateMonthlyPayment(Loan loan) {
    float monthlyRate = loan.annualInterestRate / 100 / 12;
    int numberOfPayments = loan.years * 12;
    return loan.principal * (monthlyRate * pow(1 + monthlyRate, numberOfPayments)) /
           (pow(1 + monthlyRate, numberOfPayments) - 1);
}

void displayLoanDetails(Loan loan, float monthlyPayment) {
    printf("\nLoan Details:\n");
    printf("Principal: $%.2f\n", loan.principal);
    printf("Annual Interest Rate: %.2f%%\n", loan.annualInterestRate);
    printf("Term: %d years\n", loan.years);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
}

void displayAmortizationSchedule(Loan loan) {
    float monthlyPayment = calculateMonthlyPayment(loan);
    float monthlyRate = loan.annualInterestRate / 100 / 12;
    int numberOfPayments = loan.years * 12;

    printf("\nAmortization Schedule for the Loan:\n");
    printf("Payment No.\tPayment\t\tPrincipal\tInterest\tRemaining Balance\n");

    float remainingBalance = loan.principal;
    for (int i = 1; i <= numberOfPayments; i++) {
        float interestPayment = remainingBalance * monthlyRate;
        float principalPayment = monthlyPayment - interestPayment;
        remainingBalance -= principalPayment;

        printf("%d\t\t$%.2f\t$%.2f\t\t$%.2f\t\t$%.2f\n", 
               i, 
               monthlyPayment, 
               principalPayment, 
               interestPayment, 
               remainingBalance < 0 ? 0 : remainingBalance);
    }
}