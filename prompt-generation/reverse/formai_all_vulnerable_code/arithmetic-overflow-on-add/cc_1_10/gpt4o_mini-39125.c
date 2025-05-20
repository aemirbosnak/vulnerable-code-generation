//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void welcomeMessage() {
    printf("=====================================\n");
    printf("      Welcome to Expense Tracker!    \n");
    printf("=====================================\n");
    printf("Track your expenses easily and efficiently!\n");
    printf("Let's get started!\n\n");
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Oh no! You've reached the maximum number of expenses!\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense description: ");
    scanf(" %[^\n]", newExpense.description);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully! 🎉\n\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("You have no expenses recorded yet! 📅\n");
        return;
    }

    printf("Your Expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("\n");
}

void deleteExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete! 📅\n");
        return;
    }

    viewExpenses(tracker);
    int index;
    printf("Enter the expense number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > tracker->count) {
        printf("Invalid expense number! Please try again. ❌\n\n");
        return;
    }

    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully! 🙌\n\n");
}

void saveToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Error opening file for saving! 🚫\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s $%.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }

    fclose(file);
    printf("Expenses saved to expenses.txt! 📂\n\n");
}

void loadFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No previous records found! 📁\n");
        return;
    }

    while (fscanf(file, " %[^\n] $%f\n", tracker->expenses[tracker->count].description, &tracker->expenses[tracker->count].amount) != EOF) {
        tracker->count++;
        if (tracker->count >= MAX_EXPENSES) break;
    }

    fclose(file);
    printf("Expenses loaded successfully! 🚀\n\n");
}

int main() {
    ExpenseTracker tracker = {.count = 0};
    welcomeMessage();
    loadFromFile(&tracker);

    int choice;
    do {
        printf("Choose an option: \n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Save Expenses\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                deleteExpense(&tracker);
                break;
            case 4:
                saveToFile(&tracker);
                break;
            case 5:
                printf("Thanks for using the Expense Tracker! 🎊\n");
                break;
            default:
                printf("Invalid choice! Please try again. ❗\n\n");
        }
    } while (choice != 5);

    return 0;
}