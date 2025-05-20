//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Entry;

Entry expenses[MAX_ENTRIES];
Entry incomes[MAX_ENTRIES];
int expenseCount = 0;
int incomeCount = 0;

void addExpense();
void addIncome();
void viewExpenses();
void viewIncomes();
void calculateBalance();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                addIncome();
                break;
            case 3:
                viewExpenses();
                break;
            case 4:
                viewIncomes();
                break;
            case 5:
                calculateBalance();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Expense\n");
    printf("2. Add Income\n");
    printf("3. View Expenses\n");
    printf("4. View Incomes\n");
    printf("5. Calculate Balance\n");
    printf("6. Exit\n");
}

void addExpense() {
    if (expenseCount >= MAX_ENTRIES) {
        printf("Maximum expense entries reached.\n");
        return;
    }
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    printf("Enter expense description: ");
    scanf(" %[^\n]", description);
    printf("Enter expense amount: ");
    scanf("%f", &amount);

    strcpy(expenses[expenseCount].description, description);
    expenses[expenseCount].amount = amount;
    expenseCount++;

    printf("Expense added successfully!\n");
}

void addIncome() {
    if (incomeCount >= MAX_ENTRIES) {
        printf("Maximum income entries reached.\n");
        return;
    }
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    printf("Enter income description: ");
    scanf(" %[^\n]", description);
    printf("Enter income amount: ");
    scanf("%f", &amount);

    strcpy(incomes[incomeCount].description, description);
    incomes[incomeCount].amount = amount;
    incomeCount++;

    printf("Income added successfully!\n");
}

void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void viewIncomes() {
    if (incomeCount == 0) {
        printf("No incomes recorded.\n");
        return;
    }
    printf("\n--- Incomes ---\n");
    for (int i = 0; i < incomeCount; i++) {
        printf("%d. %s: $%.2f\n", i + 1, incomes[i].description, incomes[i].amount);
    }
}

void calculateBalance() {
    float totalExpenses = 0;
    float totalIncomes = 0;

    for (int i = 0; i < expenseCount; i++) {
        totalExpenses += expenses[i].amount;
    }
    for (int i = 0; i < incomeCount; i++) {
        totalIncomes += incomes[i].amount;
    }

    printf("\n--- Financial Overview ---\n");
    printf("Total Incomes: $%.2f\n", totalIncomes);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Balance: $%.2f\n", totalIncomes - totalExpenses);
}