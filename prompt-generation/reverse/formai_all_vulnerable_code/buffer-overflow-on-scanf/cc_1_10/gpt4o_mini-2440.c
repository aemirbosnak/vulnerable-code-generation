//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
} Expense;

Expense *expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense(const char *description, float amount) {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense list is full, unable to add new expense.\n");
        return;
    }
    
    Expense *new_expense = (Expense*) malloc(sizeof(Expense));
    if (new_expense == NULL) {
        perror("Failed to allocate memory for new expense");
        return;
    }

    strncpy(new_expense->description, description, sizeof(new_expense->description) - 1);
    new_expense->description[sizeof(new_expense->description) - 1] = '\0';  // Ensure null termination
    new_expense->amount = amount;
    
    expenses[expense_count++] = new_expense;
    printf("Added expense: %s - $%.2f\n", description, amount);
}

void list_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < expense_count; ++i) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i]->description, expenses[i]->amount);
    }
}

void remove_expense(int index) {
    if (index < 1 || index > expense_count) {
        printf("Invalid expense index: %d\n", index);
        return;
    }

    index--; // Convert to zero-based index
    free(expenses[index]);
    
    for (int i = index; i < expense_count - 1; ++i) {
        expenses[i] = expenses[i + 1];
    }
    
    expenses[--expense_count] = NULL; // Avoid dangling pointer
    printf("Removed expense at index %d.\n", index + 1);
}

void cleanup_expenses() {
    for (int i = 0; i < expense_count; ++i) {
        free(expenses[i]);
    }
    expense_count = 0;
}

int main() {
    int option;
    char description[50];
    float amount;

    while (1) {
        printf("\nExpense Tracker:\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Remove Expense\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter description: ");
                scanf("%s", description);
                printf("Enter amount: ");
                scanf("%f", &amount);
                add_expense(description, amount);
                break;
            case 2:
                list_expenses();
                break;
            case 3:
                printf("Enter expense index to remove: ");
                int index;
                scanf("%d", &index);
                remove_expense(index);
                break;
            case 4:
                cleanup_expenses();
                printf("Exiting Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}