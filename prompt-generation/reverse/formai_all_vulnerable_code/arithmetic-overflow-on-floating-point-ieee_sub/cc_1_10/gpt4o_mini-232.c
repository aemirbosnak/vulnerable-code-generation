//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
} Expense;

typedef struct {
    float income;
    Expense expenses[MAX_EXPENSES];
    int expenseCount;
    float savingsGoal;
} PersonalFinance;

void addExpense(PersonalFinance *pf) {
    if (pf->expenseCount >= MAX_EXPENSES) {
        printf("Whoa! You've reached the maximum number of expenses! \n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", pf->expenses[pf->expenseCount].name);
    printf("Enter expense amount: ");
    scanf("%f", &pf->expenses[pf->expenseCount].amount);

    pf->expenseCount++;
    printf("Expense added successfully! 🚀\n");
}

void displaySummary(PersonalFinance *pf) {
    printf("\n--- Financial Summary ---\n");
    printf("Income: $%.2f\n", pf->income);
    
    float totalExpenses = 0.0;
    for (int i = 0; i < pf->expenseCount; i++) {
        printf("Expense %d: %s - $%.2f\n", i + 1, pf->expenses[i].name, pf->expenses[i].amount);
        totalExpenses += pf->expenses[i].amount;
    }

    printf("Total Expenses: $%.2f\n", totalExpenses);
    float remaining = pf->income - totalExpenses;
    printf("Remaining Funds: $%.2f\n", remaining);
    
    if (remaining < 0) {
        printf("Uh-oh! You are over budget! 🔴\n");
    } else {
        printf("Great! You are within your budget! 🟢\n");
    }

    printf("Savings Goal: $%.2f\n", pf->savingsGoal);
    if (remaining >= pf->savingsGoal) {
        printf("Congratulations! You can achieve your savings goal! 🎉\n");
    } else {
        printf("You still need to save $%.2f more to achieve your goal! 🏦\n", pf->savingsGoal - remaining);
    }
}

void surpriseMe() {
    printf("Surprise! Here's a financial tip! 🎊\n");
    printf("Always save at least 20% of your income! It's a fantastic way to build a safety net!\n");
}

int main() {
    PersonalFinance pf = {0.0, {}, 0, 0.0};

    printf("Welcome to the Surprising Personal Finance Planner! 💰\n");

    printf("Enter your total monthly income: ");
    scanf("%f", &pf.income);
    printf("Set your savings goal: ");
    scanf("%f", &pf.savingsGoal);

    char choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add Expense\n");
        printf("2. View Summary\n");
        printf("3. Get Financial Surprise Tip\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addExpense(&pf);
                break;
            case '2':
                displaySummary(&pf);
                break;
            case '3':
                surpriseMe();
                break;
            case '4':
                printf("Exiting the planner. Stay financially savvy! 👋\n");
                break;
            default:
                printf("Whoa! That's not a valid option! Try again! 🤔\n");
        }
    } while (choice != '4');

    return 0;
}