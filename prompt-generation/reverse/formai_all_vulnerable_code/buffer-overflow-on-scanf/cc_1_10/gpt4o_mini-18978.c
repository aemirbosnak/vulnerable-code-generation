//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    printf("Enter expense description: ");
    scanf(" %[^\n]", expenses[*count].description);
    
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);
    
    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\nExpenses List:\n");
    printf("-------------------------------------------------\n");
    printf("| %-30s | %-10s |\n", "Description", "Amount");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-30s | %-10.2f |\n", expenses[i].description, expenses[i].amount);
    }
    printf("-------------------------------------------------\n");
}

void deleteExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    
    int index;
    printf("Enter the index of the expense to delete (0 to %d): ", *count - 1);
    scanf("%d", &index);
    
    if (index < 0 || index >= *count) {
        printf("Invalid index. Please try again.\n");
        return;
    }
    
    for (int i = index; i < (*count) - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*count)--;
    printf("Expense deleted successfully!\n");
}

void summarizeExpenses(Expense expenses[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    
    printf("\nTotal Expenses: %.2f\n", total);
}

void displayMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Summarize Expenses\n");
    printf("5. Exit\n");
    printf("Please select an option: ");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                deleteExpense(expenses, &count);
                break;
            case 4:
                summarizeExpenses(expenses, count);
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}