//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 100

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Oops! Maximum expense limit reached!\n");
        return;
    }
    Expense newExpense;
    printf("Enter expense description: ");
    scanf(" %[^\n]", newExpense.description);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    
    expenses[*count] = newExpense;
    (*count)++;
    printf("🎉 Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded yet!\n");
        return;
    }
    printf("\n🏦 Your Recorded Expenses:\n");
    float total = 0;
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }
    printf("🧾 Total Expenses: $%.2f\n\n", total);
}

void showMenu() {
    printf("Welcome to the Amazing Expense Tracker!\n");
    printf("Choose an option:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printf("Thank you for using the Expense Tracker! 😊\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}