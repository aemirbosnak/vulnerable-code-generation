//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define DESC_LENGTH 50

struct Expense {
    char name[NAME_LENGTH];
    float amount;
    char description[DESC_LENGTH];
};

struct Income {
    char name[NAME_LENGTH];
    float amount;
    char description[DESC_LENGTH];
};

struct Budget {
    struct Expense expenses[MAX_ENTRIES];
    struct Income incomes[MAX_ENTRIES];
    int expenseCount;
    int incomeCount;
    float totalIncome;
    float totalExpense;
};

void addExpense(struct Budget *budget) {
    if (budget->expenseCount >= MAX_ENTRIES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    
    struct Expense newExpense;
    
    printf("Enter expense name: ");
    scanf("%s", newExpense.name);
    
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    
    printf("Enter expense description: ");
    scanf("%s", newExpense.description);
    
    budget->expenses[budget->expenseCount] = newExpense;
    budget->expenseCount++;
    
    budget->totalExpense += newExpense.amount;
    
    printf("Expense added successfully!\n");
}

void addIncome(struct Budget *budget) {
    if (budget->incomeCount >= MAX_ENTRIES) {
        printf("Income limit reached! Cannot add more income entries.\n");
        return;
    }
    
    struct Income newIncome;
    
    printf("Enter income source name: ");
    scanf("%s", newIncome.name);
    
    printf("Enter income amount: ");
    scanf("%f", &newIncome.amount);
    
    printf("Enter income description: ");
    scanf("%s", newIncome.description);
    
    budget->incomes[budget->incomeCount] = newIncome;
    budget->incomeCount++;
    
    budget->totalIncome += newIncome.amount;
    
    printf("Income added successfully!\n");
}

void displaySummary(struct Budget *budget) {
    printf("\n--- Personal Finance Summary ---\n");
    printf("Total Income: $%.2f\n", budget->totalIncome);
    printf("Total Expenses: $%.2f\n", budget->totalExpense);
    printf("Net Savings: $%.2f\n", budget->totalIncome - budget->totalExpense);
    printf("--------------------------------\n");
}

void displayExpenses(const struct Budget *budget) {
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < budget->expenseCount; i++) {
        printf("Name: %s, Amount: $%.2f, Description: %s\n", 
               budget->expenses[i].name, 
               budget->expenses[i].amount, 
               budget->expenses[i].description);
    }
    printf("----------------\n");
}

void displayIncomes(const struct Budget *budget) {
    printf("\n--- Incomes ---\n");
    for (int i = 0; i < budget->incomeCount; i++) {
        printf("Source: %s, Amount: $%.2f, Description: %s\n", 
               budget->incomes[i].name, 
               budget->incomes[i].amount, 
               budget->incomes[i].description);
    }
    printf("----------------\n");
}

int main() {
    struct Budget budget;
    budget.expenseCount = 0;
    budget.incomeCount = 0;
    budget.totalIncome = 0.0;
    budget.totalExpense = 0.0;
    
    int choice;
    
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Expense\n");
        printf("2. Add Income\n");
        printf("3. Display Summary\n");
        printf("4. Display Expenses\n");
        printf("5. Display Incomes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&budget);
                break;
            case 2:
                addIncome(&budget);
                break;
            case 3:
                displaySummary(&budget);
                break;
            case 4:
                displayExpenses(&budget);
                break;
            case 5:
                displayIncomes(&budget);
                break;
            case 0:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}