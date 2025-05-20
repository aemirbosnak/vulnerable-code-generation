//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    char category[MAX_NAME_LENGTH];
} Expense;

typedef struct {
    double income;
    double totalExpenses;
    double budget;
    Expense expenses[MAX_ENTRIES];
    int expenseCount;
} PersonalFinance;

void initFinance(PersonalFinance *pf) {
    pf->income = 0.0;
    pf->totalExpenses = 0.0;
    pf->budget = 0.0;
    pf->expenseCount = 0;
    printf("Surprisingly initialized financial structure!\n");
}

void addIncome(PersonalFinance *pf) {
    printf("What was your income this month? \n$ ");
    scanf("%lf", &pf->income);
    printf("Income added: $%.2f\n", pf->income);
}

void setBudget(PersonalFinance *pf) {
    printf("What is your budget for this month? \n$ ");
    scanf("%lf", &pf->budget);
    printf("Budget set at: $%.2f\n", pf->budget);
}

void addExpense(PersonalFinance *pf) {
    if (pf->expenseCount >= MAX_ENTRIES) {
        printf("Oh no! Can't add more expenses, maximum reached!\n");
        return;
    }

    Expense *exp = &pf->expenses[pf->expenseCount];
    printf("Enter expense name (e.g., Rent, Groceries): ");
    scanf("%s", exp->name);
    printf("Enter amount for %s: \n$ ", exp->name);
    scanf("%lf", &exp->amount);
    printf("Enter expense category (e.g., Housing, Food): ");
    scanf("%s", exp->category);

    pf->totalExpenses += exp->amount;
    pf->expenseCount++;
    printf("Expense recorded: %s - $%.2f, Category: %s\n", exp->name, exp->amount, exp->category);
}

void displaySummary(const PersonalFinance *pf) {
    printf("\n--- Financial Summary ---\n");
    printf("Income: $%.2f\n", pf->income);
    printf("Total Expenses: $%.2f\n", pf->totalExpenses);
    printf("Remaining Budget: $%.2f\n", pf->budget - pf->totalExpenses);
  
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < pf->expenseCount; i++) {
        printf("%s - $%.2f (Category: %s)\n", pf->expenses[i].name, pf->expenses[i].amount, pf->expenses[i].category);
    }

    if (pf->totalExpenses > pf->budget) {
        printf("WARNING: You've overspent your budget by $%.2f!🤯\n", pf->totalExpenses - pf->budget);
    } else {
        printf("Great job! You are within your budget. 🎉\n");
    }
}

void displayMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Income\n");
    printf("2. Set Budget\n");
    printf("3. Add Expense\n");
    printf("4. Display Summary\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    PersonalFinance pf;
    initFinance(&pf);
    
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addIncome(&pf);
                break;
            case 2:
                setBudget(&pf);
                break;
            case 3:
                addExpense(&pf);
                break;
            case 4:
                displaySummary(&pf);
                break;
            case 5:
                printf("Exiting. Stay financially savvy! 💸\n");
                exit(0);
                break;
            default:
                printf("Uh-oh! That's not a valid option! 😲\n");
                break;
        }
    }
    
    return 0;
}