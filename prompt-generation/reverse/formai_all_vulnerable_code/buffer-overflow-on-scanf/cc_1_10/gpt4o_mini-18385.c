//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void addExpense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Oh no! You've reached your maximum expense limit! Can't add more!\n");
        return;
    }

    Expense new_expense;
    printf("\n🎉 Add a new expense 🎉\n");
    printf("Enter the name of the expense: ");
    getchar(); // Consume any trailing newline character from previous input
    fgets(new_expense.name, NAME_LENGTH, stdin);
    new_expense.name[strcspn(new_expense.name, "\n")] = 0; // Remove trailing newline

    printf("Enter the amount spent: ");
    scanf("%f", &new_expense.amount);

    expenses[expense_count] = new_expense;
    expense_count++;

    printf("💰 Wow! You've added %s costing $%.2f!\n", new_expense.name, new_expense.amount);
}

void viewExpenses() {
    if (expense_count == 0) {
        printf("😱 You don't have any expenses recorded! Start adding now!\n");
        return;
    }

    printf("\n📊 Here are your recorded expenses:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }
}

void calculateTotal() {
    if (expense_count == 0) {
        printf("🤔 Can't calculate total! You need expenses to calculate!\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }

    printf("💸 Surprise! Your total expenses are $%.2f!\n", total);
}

void displayMenu() {
    printf("\n====================\n");
    printf("🎈 Expense Tracker 🎈\n");
    printf("====================\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total\n");
    printf("4. Exit\n");
    printf("====================\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Pick an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                calculateTotal();
                break;
            case 4:
                printf("🎆 Thank you for using the Expense Tracker! Goodbye! 🎆\n");
                break;
            default:
                printf("😕 Oops! That's not a valid choice! Please select again!\n");
        }
    } while (choice != 4);

    return 0;
}