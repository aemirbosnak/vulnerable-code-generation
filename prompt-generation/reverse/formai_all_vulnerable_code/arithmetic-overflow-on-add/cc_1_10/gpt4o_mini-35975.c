//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
} FinancePlanner;

void addIncome(FinancePlanner *planner) {
    if (planner->incomeCount < MAX_ENTRIES) {
        printf("Enter income source: ");
        scanf("%s", planner->income[planner->incomeCount].name);
        printf("Enter amount: ");
        scanf("%f", &planner->income[planner->incomeCount].amount);
        planner->incomeCount++;
        printf("Income added successfully!\n");
    } else {
        printf("Income entries full.\n");
    }
}

void addExpense(FinancePlanner *planner) {
    if (planner->expenseCount < MAX_ENTRIES) {
        printf("Enter expense name: ");
        scanf("%s", planner->expenses[planner->expenseCount].name);
        printf("Enter amount: ");
        scanf("%f", &planner->expenses[planner->expenseCount].amount);
        planner->expenseCount++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense entries full.\n");
    }
}

void viewSummary(FinancePlanner *planner) {
    float totalIncome = 0, totalExpenses = 0;

    printf("\n---- Income Summary ----\n");
    for (int i = 0; i < planner->incomeCount; i++) {
        printf("%s: %.2f\n", planner->income[i].name, planner->income[i].amount);
        totalIncome += planner->income[i].amount;
    }

    printf("\n---- Expense Summary ----\n");
    for (int i = 0; i < planner->expenseCount; i++) {
        printf("%s: %.2f\n", planner->expenses[i].name, planner->expenses[i].amount);
        totalExpenses += planner->expenses[i].amount;
    }

    printf("\nTotal Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Balance: %.2f\n", totalIncome - totalExpenses);
}

void saveToFile(FinancePlanner *planner) {
    FILE *file = fopen("finance_summary.txt", "w");
    if (file) {
        fprintf(file, "---- Finance Summary ----\n");
        fprintf(file, "Income:\n");
        for (int i = 0; i < planner->incomeCount; i++) {
            fprintf(file, "%s: %.2f\n", planner->income[i].name, planner->income[i].amount);
        }
        fprintf(file, "Expenses:\n");
        for (int i = 0; i < planner->expenseCount; i++) {
            fprintf(file, "%s: %.2f\n", planner->expenses[i].name, planner->expenses[i].amount);
        }
        fprintf(file, "End of summary.\n");
        fclose(file);
        printf("Summary saved to finance_summary.txt\n");
    } else {
        printf("Error saving to file.\n");
    }
}

int main() {
    FinancePlanner planner;
    planner.incomeCount = 0;
    planner.expenseCount = 0;

    int choice;
    do {
        printf("\n**** Personal Finance Planner ****\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Save to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&planner);
                break;
            case 2:
                addExpense(&planner);
                break;
            case 3:
                viewSummary(&planner);
                break;
            case 4:
                saveToFile(&planner);
                break;
            case 5:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}