//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count);
void viewExpenses(Expense expenses[], int count);
float totalExpenses(Expense expenses[], int count);
void displayMenu();

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (count < MAX_EXPENSES) {
                    addExpense(expenses, &count);
                } else {
                    printf("Expense list is full!\n");
                }
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", totalExpenses(expenses, count));
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addExpense(Expense expenses[], int *count) {
    Expense newExpense;
    
    printf("Enter description of the expense: ");
    getchar(); // clear newline left in the input buffer
    fgets(newExpense.description, MAX_DESC_LEN, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = '\0'; // remove newline

    printf("Enter amount: $");
    scanf("%f", &newExpense.amount);

    expenses[*count] = newExpense; // Store the new expense
    (*count)++; // Increment count
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    
    printf("\nExpenses List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

float totalExpenses(Expense expenses[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Exit\n");
}