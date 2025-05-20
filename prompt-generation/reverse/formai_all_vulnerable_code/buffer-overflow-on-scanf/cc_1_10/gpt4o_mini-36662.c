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

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Oh no! You've reached the maximum limit of %d expenses.\n", MAX_EXPENSES);
        return;
    }

    Expense newExpense;
    printf("Let's add a new expense!\n");
    printf("Enter a brief description: ");
    getchar(); // consume newline from previous input
    fgets(newExpense.description, MAX_DESC_LEN, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // remove newline

    printf("Enter the amount spent: ");
    scanf("%f", &newExpense.amount);

    expenses[*count] = newExpense;
    (*count)++;
    printf("Yay! You've added the expense successfully!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded yet! Let's start tracking!\n");
        return;
    }

    printf("\nHere are your recorded expenses:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
    printf("--------------------------------------------------\n");
}

void calculateTotal(Expense expenses[], int count) {
    float total = 0.0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    printf("Your total expenses amount to: $%.2f\n", total);
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    printf("Welcome to your Expense Tracker! 🎉\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                calculateTotal(expenses, count);
                break;
            case 4:
                printf("Thank you for using the Expense Tracker! Have a great day! 😊\n");
                break;
            default:
                printf("Oops! That's not a valid option! Please choose again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}