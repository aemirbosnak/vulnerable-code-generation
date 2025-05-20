//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 200

typedef struct {
    char name[NAME_LENGTH];
    float amount;
    char description[DESCRIPTION_LENGTH];
} Expense;

typedef struct {
    char name[NAME_LENGTH];
    float amount;
    char description[DESCRIPTION_LENGTH];
} Income;

typedef struct {
    Income incomes[MAX_ENTRIES];
    Expense expenses[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
} PersonalFinance;

void initFinance(PersonalFinance *pf) {
    pf->incomeCount = 0;
    pf->expenseCount = 0;
}

void addIncome(PersonalFinance *pf) {
    if (pf->incomeCount >= MAX_ENTRIES) {
        printf("Income list is full!\n");
        return;
    }
    
    Income newIncome;
    printf("Enter income source name: ");
    scanf("%s", newIncome.name);
    printf("Enter income amount: ");
    scanf("%f", &newIncome.amount);
    printf("Enter income description: ");
    scanf(" %[^\n]s", newIncome.description);
    
    pf->incomes[pf->incomeCount++] = newIncome;
    printf("Income added successfully!\n");
}

void addExpense(PersonalFinance *pf) {
    if (pf->expenseCount >= MAX_ENTRIES) {
        printf("Expense list is full!\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter expense name: ");
    scanf("%s", newExpense.name);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    printf("Enter expense description: ");
    scanf(" %[^\n]s", newExpense.description);
    
    pf->expenses[pf->expenseCount++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewIncomes(PersonalFinance *pf) {
    printf("\n--- Incomes ---\n");
    for (int i = 0; i < pf->incomeCount; i++) {
        printf("Source: %s, Amount: %.2f, Description: %s\n", 
               pf->incomes[i].name, pf->incomes[i].amount, pf->incomes[i].description);
    }
}

void viewExpenses(PersonalFinance *pf) {
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < pf->expenseCount; i++) {
        printf("Name: %s, Amount: %.2f, Description: %s\n", 
               pf->expenses[i].name, pf->expenses[i].amount, pf->expenses[i].description);
    }
}

void calculateNetIncome(PersonalFinance *pf) {
    float totalIncome = 0, totalExpenses = 0;

    for (int i = 0; i < pf->incomeCount; i++) {
        totalIncome += pf->incomes[i].amount;
    }
    for (int i = 0; i < pf->expenseCount; i++) {
        totalExpenses += pf->expenses[i].amount;
    }
    
    printf("\nTotal Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Net Income: %.2f\n", totalIncome - totalExpenses);
}

int main() {
    PersonalFinance pf;
    initFinance(&pf);
    
    int choice;
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Incomes\n");
        printf("4. View Expenses\n");
        printf("5. Calculate Net Income\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addIncome(&pf);
                break;
            case 2:
                addExpense(&pf);
                break;
            case 3:
                viewIncomes(&pf);
                break;
            case 4:
                viewExpenses(&pf);
                break;
            case 5:
                calculateNetIncome(&pf);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}