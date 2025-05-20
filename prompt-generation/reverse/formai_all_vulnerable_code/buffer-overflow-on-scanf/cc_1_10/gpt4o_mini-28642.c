//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("🎉 Maximum expense limit reached! Can't add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("✨ Enter the description for your expense: ");
    scanf(" %[^\n]s", newExpense.description);
    printf("💰 Enter the amount for your expense: ");
    scanf("%f", &newExpense.amount);

    expenses[expenseCount] = newExpense;
    expenseCount++;
    printf("✅ Your expense has been added! 🎊\n");
}

void viewExpenses() {
    if (expenseCount == 0) {
        printf("😞 No expenses to show yet! Start adding some!\n");
        return;
    }

    printf("\n📊 Here are your recorded expenses:\n");
    printf("===================================\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("📋 %d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
    printf("===================================\n");
}

void totalExpenses() {
    if (expenseCount == 0) {
        printf("😞 No expenses available to calculate total!\n");
        return;
    }

    float total = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    printf("🎉 Your total expenses are: $%.2f\n", total);
}

void displayMenu() {
    printf("\n💡 Welcome to your Expense Tracker! 💡\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                totalExpenses();
                break;
            case 4:
                printf("🚪 Thank you for using the Expense Tracker! Goodbye! 🎈\n");
                break;
            default:
                printf("⚠️ Invalid choice! Please choose a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}