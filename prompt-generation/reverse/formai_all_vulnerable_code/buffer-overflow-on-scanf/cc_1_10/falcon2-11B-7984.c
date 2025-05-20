//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct BankAccount {
    int accountNumber;
    char name[50];
    double balance;
    double interestRate;
};

struct Budget {
    struct BankAccount savings;
    struct BankAccount checking;
    struct BankAccount creditCard;
    int budgetMonth;
    int budgetYear;
};

void createAccount(struct BankAccount *account) {
    printf("Enter Account Number: ");
    scanf("%d", &account->accountNumber);
    printf("Enter Account Name: ");
    scanf(" %s", account->name);
    printf("Enter Initial Balance: ");
    scanf("%lf", &account->balance);
    printf("Enter Interest Rate: ");
    scanf("%lf", &account->interestRate);
}

void displayAccount(struct BankAccount account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Name: %s\n", account.name);
    printf("Balance: %.2lf\n", account.balance);
    printf("Interest Rate: %.2lf%%\n", account.interestRate);
}

void deposit(struct BankAccount *account, double amount) {
    account->balance += amount;
}

void withdraw(struct BankAccount *account, double amount) {
    if (account->balance < amount) {
        printf("Insufficient funds\n");
    } else {
        account->balance -= amount;
    }
}

void updateInterest(struct BankAccount *account) {
    account->balance *= (1 + account->interestRate / 100.0);
}

void createBudget(struct Budget *budget) {
    createAccount(&budget->savings);
    createAccount(&budget->checking);
    createAccount(&budget->creditCard);
    printf("Enter Budget Month (MM): ");
    scanf("%d", &budget->budgetMonth);
    printf("Enter Budget Year: ");
    scanf("%d", &budget->budgetYear);
}

void displayBudget(struct Budget budget) {
    displayAccount(budget.savings);
    displayAccount(budget.checking);
    displayAccount(budget.creditCard);
    printf("Budget Month: %d/%d\n", budget.budgetMonth, budget.budgetYear);
}

void budgetMonth(struct Budget *budget) {
    if (budget->budgetMonth == 1 || budget->budgetMonth == 3 || budget->budgetMonth == 5 || budget->budgetMonth == 7 || budget->budgetMonth == 8 || budget->budgetMonth == 10 || budget->budgetMonth == 12) {
        printf("Savings Budget Month\n");
        deposit(&budget->savings, 1000);
    } else if (budget->budgetMonth == 2 || budget->budgetMonth == 4 || budget->budgetMonth == 6 || budget->budgetMonth == 9 || budget->budgetMonth == 11) {
        printf("Checking Budget Month\n");
        deposit(&budget->checking, 500);
    } else {
        printf("Credit Card Budget Month\n");
        withdraw(&budget->creditCard, 100);
    }
    updateInterest(&budget->savings);
    updateInterest(&budget->checking);
    updateInterest(&budget->creditCard);
}

int main() {
    struct BankAccount savings;
    struct BankAccount checking;
    struct BankAccount creditCard;
    struct Budget budget;
    createAccount(&savings);
    createAccount(&checking);
    createAccount(&creditCard);
    createBudget(&budget);
    budgetMonth(&budget);
    return 0;
}