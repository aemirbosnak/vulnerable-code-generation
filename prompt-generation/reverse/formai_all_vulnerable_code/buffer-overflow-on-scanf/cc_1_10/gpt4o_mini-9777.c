//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    double amount;
} Expense;

typedef struct {
    double totalIncome;
    Expense expenses[MAX_ENTRIES];
    int expenseCount;
} PersonalFinance;

void addExpense(PersonalFinance *finance) {
    if (finance->expenseCount >= MAX_ENTRIES) {
        printf("Cannot add more expenses, limit reached.\n");
        return;
    }

    Expense newExpense;
    printf("Enter the expense name: ");
    scanf("%s", newExpense.name);
    printf("Enter the amount: ");
    scanf("%lf", &newExpense.amount);

    finance->expenses[finance->expenseCount] = newExpense;
    finance->expenseCount++;
    printf("Expense added successfully!\n");
}

void displayExpenses(PersonalFinance *finance) {
    if (finance->expenseCount == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < finance->expenseCount; i++) {
        printf("%d. %s: $%.2lf\n", i + 1, finance->expenses[i].name, finance->expenses[i].amount);
    }
}

double calculateTotalExpenses(PersonalFinance *finance) {
    double total = 0.0;
    for (int i = 0; i < finance->expenseCount; i++) {
        total += finance->expenses[i].amount;
    }
    return total;
}

void displayFinanceSummary(PersonalFinance *finance) {
    double totalExpenses = calculateTotalExpenses(finance);
    double remainingBalance = finance->totalIncome - totalExpenses;

    printf("\nFinancial Summary:\n");
    printf("Total Income: $%.2lf\n", finance->totalIncome);
    printf("Total Expenses: $%.2lf\n", totalExpenses);
    printf("Remaining Balance: $%.2lf\n", remainingBalance);
}

void inputIncome(PersonalFinance *finance) {
    printf("Enter your total income: $");
    scanf("%lf", &finance->totalIncome);
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Input Income\n");
    printf("2. Add Expense\n");
    printf("3. Display Expenses\n");
    printf("4. Display Financial Summary\n");
    printf("5. Exit\n");
}

int main() {
    PersonalFinance finance;
    finance.totalIncome = 0.0;
    finance.expenseCount = 0;

    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputIncome(&finance);
                break;
            case 2:
                addExpense(&finance);
                break;
            case 3:
                displayExpenses(&finance);
                break;
            case 4:
                displayFinanceSummary(&finance);
                break;
            case 5:
                printf("Exiting the planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}