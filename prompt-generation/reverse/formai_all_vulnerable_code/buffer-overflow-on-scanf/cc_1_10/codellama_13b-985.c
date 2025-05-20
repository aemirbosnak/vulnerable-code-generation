//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct PersonalFinance {
    int balance;
    int income;
    int expenses;
};

void display_menu(void) {
    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please select an option:\n");
    printf("1. Add income\n");
    printf("2. Add expenses\n");
    printf("3. View balance\n");
    printf("4. Exit\n");
}

void add_income(struct PersonalFinance *pf) {
    int amount;
    printf("Enter the amount of income: ");
    scanf("%d", &amount);
    pf->income += amount;
    printf("Income added successfully!\n");
}

void add_expenses(struct PersonalFinance *pf) {
    int amount;
    printf("Enter the amount of expenses: ");
    scanf("%d", &amount);
    pf->expenses += amount;
    printf("Expenses added successfully!\n");
}

void view_balance(struct PersonalFinance *pf) {
    printf("Your current balance is: %d\n", pf->balance);
}

int main() {
    struct PersonalFinance pf;
    pf.balance = 0;
    pf.income = 0;
    pf.expenses = 0;

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_income(&pf);
                break;
            case 2:
                add_expenses(&pf);
                break;
            case 3:
                view_balance(&pf);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}