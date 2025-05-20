//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
    float total_budget;
} PersonalFinance;

void initializeFinance(PersonalFinance *pf) {
    pf->count = 0;
    pf->total_budget = 0.0f;
    printf("🎉 Welcome to Your Personal Finance Planner! 🎉\n\n");
}

void addExpense(PersonalFinance *pf) {
    if (pf->count < MAX_EXPENSES) {
        Expense new_expense;
        printf("Enter the name of the expense: ");
        scanf("%s", new_expense.name);
        printf("Enter the amount of the expense: ");
        scanf("%f", &new_expense.amount);
        pf->expenses[pf->count++] = new_expense;
        printf("💸 Expense '%s' of $%.2f added successfully!\n\n", new_expense.name, new_expense.amount);
    } else {
        printf("🚫 Unable to add more expenses, maximum limit reached!\n\n");
    }
}

void setBudget(PersonalFinance *pf) {
    printf("Enter your total budget: ");
    scanf("%f", &pf->total_budget);
    printf("🤑 Your total budget of $%.2f has been set!\n\n", pf->total_budget);
}

void viewSummary(PersonalFinance *pf) {
    if (pf->count == 0) {
        printf("📊 No expenses recorded yet! Start adding some!\n\n");
        return;
    }

    float total_expenses = 0.0f;
    printf("💰 Your Expenses Summary:\n");
    for (int i = 0; i < pf->count; i++) {
        printf("- %s: $%.2f\n", pf->expenses[i].name, pf->expenses[i].amount);
        total_expenses += pf->expenses[i].amount;
    }
    
    printf("-----------------------------\n");
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Remaining Budget: $%.2f\n", pf->total_budget - total_expenses);
    printf("💪 Keep managing your finances like a pro!\n\n");
}

void displayMenu() {
    printf("------------- Menu -------------\n");
    printf("1. Set Total Budget\n");
    printf("2. Add Expense\n");
    printf("3. View Summary\n");
    printf("4. Exit\n");
    printf("---------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    PersonalFinance myFinance;
    initializeFinance(&myFinance);
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                setBudget(&myFinance);
                break;
            case 2:
                addExpense(&myFinance);
                break;
            case 3:
                viewSummary(&myFinance);
                break;
            case 4:
                printf("🚀 Thank you for using the Personal Finance Planner! Goodbye! 👋\n");
                break;
            default:
                printf("❌ Invalid option! Please try again.\n\n");
        }
    } while (choice != 4);

    return 0;
}