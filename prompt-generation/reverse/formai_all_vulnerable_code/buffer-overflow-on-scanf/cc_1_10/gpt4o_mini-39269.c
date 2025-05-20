//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int totalExpenses;
    float income;
} PersonalFinance;

void initializeFinance(PersonalFinance *pf) {
    pf->totalExpenses = 0;
    pf->income = 0.0f;
}

void addExpense(PersonalFinance *pf) {
    if (pf->totalExpenses >= MAX_ENTRIES) {
        printf("Expense limit reached! Can't add more expenses.\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter expense name: ");
    scanf("%s", newExpense.name);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    
    pf->expenses[pf->totalExpenses] = newExpense;
    pf->totalExpenses++;
    printf("Expense added successfully!\n");
}

void setIncome(PersonalFinance *pf) {
    printf("Enter your total income: ");
    scanf("%f", &pf->income);
}

void viewExpenses(PersonalFinance *pf) {
    if (pf->totalExpenses == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n--- Expenses List ---\n");
    for (int i = 0; i < pf->totalExpenses; i++) {
        printf("%d. %s: $%.2f\n", i + 1, pf->expenses[i].name, pf->expenses[i].amount);
    }
}

void calculateSavings(PersonalFinance *pf) {
    float totalSpent = 0.0f;
    for (int i = 0; i < pf->totalExpenses; i++) {
        totalSpent += pf->expenses[i].amount;
    }
    
    float savings = pf->income - totalSpent;
    printf("\nTotal Income: $%.2f\n", pf->income);
    printf("Total Spent: $%.2f\n", totalSpent);
    printf("Total Savings: $%.2f\n", savings);
}

void displayMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Set Income\n");
    printf("2. Add Expense\n");
    printf("3. View Expenses\n");
    printf("4. Calculate Savings\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    PersonalFinance pf;
    initializeFinance(&pf);
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                setIncome(&pf);
                break;
            case 2:
                addExpense(&pf);
                break;
            case 3:
                viewExpenses(&pf);
                break;
            case 4:
                calculateSavings(&pf);
                break;
            case 5:
                printf("Exiting the planner. Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);
    
    return 0;
}