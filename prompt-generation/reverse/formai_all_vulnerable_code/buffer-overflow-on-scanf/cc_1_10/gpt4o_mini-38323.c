//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float amount;
} Transaction;

typedef struct {
    Transaction income[50];
    Transaction expenses[50];
    int incomeCount;
    int expenseCount;
} Finances;

void displayMenu() {
    printf("Oh, what a tangled web of finance we weave!\n");
    printf("Choose thy fate, noble user:\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Summary\n");
    printf("4. Exit this tragic tale\n");
}

void addIncome(Finances *finances) {
    if (finances->incomeCount < 50) {
        printf("Enter the name of your income source (Alas!): ");
        scanf("%s", finances->income[finances->incomeCount].name);
        printf("Enter the amount earned (Alas!): ");
        scanf("%f", &finances->income[finances->incomeCount].amount);
        finances->incomeCount++;
    } else {
        printf("Ah, but the coffers are full! Cannot add more incomes!\n");
    }
}

void addExpense(Finances *finances) {
    if (finances->expenseCount < 50) {
        printf("Enter the name of your expense source (Forsooth!): ");
        scanf("%s", finances->expenses[finances->expenseCount].name);
        printf("Enter the amount spent (Forsooth!): ");
        scanf("%f", &finances->expenses[finances->expenseCount].amount);
        finances->expenseCount++;
    } else {
        printf("Ah, but the scrolls of expense are overflowing! No more can be added!\n");
    }
}

void viewSummary(const Finances *finances) {
    float totalIncome = 0;
    float totalExpenses = 0;

    printf("\n--- The Ledger of Finances ---\n");
    printf("Income:\n");
    for (int i = 0; i < finances->incomeCount; i++) {
        printf("%s: %.2f\n", finances->income[i].name, finances->income[i].amount);
        totalIncome += finances->income[i].amount;
    }

    printf("Expenses:\n");
    for (int i = 0; i < finances->expenseCount; i++) {
        printf("%s: %.2f\n", finances->expenses[i].name, finances->expenses[i].amount);
        totalExpenses += finances->expenses[i].amount;
    }

    printf("\nTotal Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Net Balance: %.2f\n", totalIncome - totalExpenses);
}

int main() {
    Finances myFinances;
    myFinances.incomeCount = 0;
    myFinances.expenseCount = 0;

    int choice;
    while (1) {
        displayMenu();
        printf("Enter thy choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&myFinances);
                break;
            case 2:
                addExpense(&myFinances);
                break;
            case 3:
                viewSummary(&myFinances);
                break;
            case 4:
                printf("Fare thee well, until we meet again in financial bliss!\n");
                exit(0);
            default:
                printf("Enter a valid choice, dear friend.\n");
                break;
        }
    }
    return 0;
}