//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_SIZE 50

typedef struct {
    char description[DESCRIPTION_SIZE];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("\nOops! You've reached the maximum number of expenses you can track.\n");
        return;
    }
    
    printf("\nLet's add an expense!\n");
    printf("Enter description: ");
    getchar(); // to consume the newline character after previous input
    fgets(expenses[*count].description, DESCRIPTION_SIZE, stdin);
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = 0; // remove newline

    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("Expense added successfully! 🎉\n");
}

void viewExpenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("\nNo expenses recorded yet! 📅\n");
        return;
    }

    printf("\nHere are your recorded expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

float calculateTotal(const Expense expenses[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int expenseCount = 0;
    int choice;

    printf("Welcome to the Expense Tracker! 🌟 Let's manage your expenses efficiently!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &expenseCount);
                break;
            case 2:
                viewExpenses(expenses, expenseCount);
                break;
            case 3:
                {
                    float total = calculateTotal(expenses, expenseCount);
                    printf("\nYour total expenses so far is: $%.2f\n", total);
                }
                break;
            case 4:
                printf("Thank you for using the Expense Tracker! Goodbye! 👋\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}