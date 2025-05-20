//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC_LENGTH 100

typedef struct Expense {
    char description[MAX_DESC_LENGTH];
    float amount;
    struct Expense* next;
} Expense;

Expense* head = NULL;

void addExpense(const char* description, float amount) {
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    if (newExpense == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;

    printf("Expense added: %s - $%.2f\n", description, amount);
}

void viewExpenses() {
    if (head == NULL) {
        printf("No expenses recorded.\n");
        return;
    }

    float total = 0.0;
    printf("\nExpenses:\n");
    Expense* current = head;
    while (current != NULL) {
        printf("%s - $%.2f\n", current->description, current->amount);
        total += current->amount;
        current = current->next;
    }
    printf("Total expenses: $%.2f\n", total);
}

void deleteExpenses() {
    Expense* current = head;
    Expense* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All expenses deleted.\n");
}

void menu() {
    printf("\nExpense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete All Expenses\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char description[MAX_DESC_LENGTH];
    float amount;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter description: ");
                getchar();  // Consume newline character left by previous input
                fgets(description, MAX_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                printf("Enter amount: ");
                scanf("%f", &amount);
                addExpense(description, amount);
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                deleteExpenses();
                break;
            case 4:
                deleteExpenses(); // Clean up on exit
                printf("Exiting Expense Tracker. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}