//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOME 100
#define MAX_LEN 50

typedef struct {
    char description[MAX_LEN];
    float amount;
} Expense;

typedef struct {
    char description[MAX_LEN];
    float amount;
} Income;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    Income incomes[MAX_INCOME];
    int expenseCount;
    int incomeCount;
} PersonalFinance;

void addExpense(PersonalFinance* pf) {
    if (pf->expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense exp;
    printf("Enter expense description: ");
    scanf("%s", exp.description);
    printf("Enter expense amount: ");
    scanf("%f", &exp.amount);

    pf->expenses[pf->expenseCount] = exp;
    pf->expenseCount++;
    printf("Expense added successfully!\n");
}

void addIncome(PersonalFinance* pf) {
    if (pf->incomeCount >= MAX_INCOME) {
        printf("Income limit reached. Cannot add more incomes.\n");
        return;
    }

    Income inc;
    printf("Enter income description: ");
    scanf("%s", inc.description);
    printf("Enter income amount: ");
    scanf("%f", &inc.amount);

    pf->incomes[pf->incomeCount] = inc;
    pf->incomeCount++;
    printf("Income added successfully!\n");
}

void displayExpenses(PersonalFinance* pf) {
    printf("\nExpenses:\n");
    for (int i = 0; i < pf->expenseCount; i++) {
        printf("%d. %s: $%.2f\n", i + 1, pf->expenses[i].description, pf->expenses[i].amount);
    }
}

void displayIncomes(PersonalFinance* pf) {
    printf("\nIncomes:\n");
    for (int i = 0; i < pf->incomeCount; i++) {
        printf("%d. %s: $%.2f\n", i + 1, pf->incomes[i].description, pf->incomes[i].amount);
    }
}

void calculateBalance(PersonalFinance* pf) {
    float totalExpenses = 0, totalIncomes = 0;

    for (int i = 0; i < pf->expenseCount; i++) {
        totalExpenses += pf->expenses[i].amount;
    }

    for (int i = 0; i < pf->incomeCount; i++) {
        totalIncomes += pf->incomes[i].amount;
    }

    float balance = totalIncomes - totalExpenses;
    printf("\nTotal Incomes: $%.2f\n", totalIncomes);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Balance: $%.2f\n", balance);
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Expense\n");
    printf("2. Add Income\n");
    printf("3. Display Expenses\n");
    printf("4. Display Incomes\n");
    printf("5. Calculate Balance\n");
    printf("6. Exit\n");
}

int main() {
    PersonalFinance pf;
    pf.expenseCount = 0;
    pf.incomeCount = 0;

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&pf);
                break;
            case 2:
                addIncome(&pf);
                break;
            case 3:
                displayExpenses(&pf);
                break;
            case 4:
                displayIncomes(&pf);
                break;
            case 5:
                calculateBalance(&pf);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}