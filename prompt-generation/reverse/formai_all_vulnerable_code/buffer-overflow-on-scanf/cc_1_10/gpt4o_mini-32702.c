//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[50];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
} Finance;

void initializeFinance(Finance *finance) {
    finance->incomeCount = 0;
    finance->expenseCount = 0;
}

void addIncome(Finance *finance) {
    if (finance->incomeCount < MAX_ENTRIES) {
        printf("Enter income description: ");
        scanf("%s", finance->income[finance->incomeCount].description);
        printf("Enter income amount: ");
        scanf("%f", &finance->income[finance->incomeCount].amount);
        finance->incomeCount++;
        printf("Income added successfully!\n");
    } else {
        printf("Income entries are full!\n");
    }
}

void addExpense(Finance *finance) {
    if (finance->expenseCount < MAX_ENTRIES) {
        printf("Enter expense description: ");
        scanf("%s", finance->expenses[finance->expenseCount].description);
        printf("Enter expense amount: ");
        scanf("%f", &finance->expenses[finance->expenseCount].amount);
        finance->expenseCount++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense entries are full!\n");
    }
}

float calculateTotalIncome(Finance *finance) {
    float total = 0;
    for (int i = 0; i < finance->incomeCount; i++) {
        total += finance->income[i].amount;
    }
    return total;
}

float calculateTotalExpenses(Finance *finance) {
    float total = 0;
    for (int i = 0; i < finance->expenseCount; i++) {
        total += finance->expenses[i].amount;
    }
    return total;
}

void printSummary(Finance *finance) {
    float totalIncome = calculateTotalIncome(finance);
    float totalExpenses = calculateTotalExpenses(finance);
    float netSavings = totalIncome - totalExpenses;

    printf("\n---------- Financial Summary ----------\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Savings: $%.2f\n", netSavings);
    printf("---------------------------------------\n");
}

void viewIncome(Finance *finance) {
    printf("\n---------- Income Entries ----------\n");
    for (int i = 0; i < finance->incomeCount; i++) {
        printf("%d. %s: $%.2f\n", i + 1, finance->income[i].description, finance->income[i].amount);
    }
    printf("------------------------------------\n");
}

void viewExpenses(Finance *finance) {
    printf("\n---------- Expense Entries ----------\n");
    for (int i = 0; i < finance->expenseCount; i++) {
        printf("%d. %s: $%.2f\n", i + 1, finance->expenses[i].description, finance->expenses[i].amount);
    }
    printf("-------------------------------------\n");
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Income\n");
    printf("4. View Expenses\n");
    printf("5. View Summary\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    Finance finance;
    initializeFinance(&finance);
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&finance);
                break;
            case 2:
                addExpense(&finance);
                break;
            case 3:
                viewIncome(&finance);
                break;
            case 4:
                viewExpenses(&finance);
                break;
            case 5:
                printSummary(&finance);
                break;
            case 6:
                printf("Exiting... Thank you for using the Personal Finance Planner!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 6);

    return 0;
}