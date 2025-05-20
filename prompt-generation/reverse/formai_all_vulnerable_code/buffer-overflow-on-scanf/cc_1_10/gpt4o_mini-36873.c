//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char name[50];
    float amount;
    struct Expense* next;
} Expense;

Expense* head = NULL;

void addExpense(char* name, float amount) {
    Expense* new_expense = (Expense*)malloc(sizeof(Expense));
    strcpy(new_expense->name, name);
    new_expense->amount = amount;
    new_expense->next = head;
    head = new_expense;
    printf("Expense added: %s - %.2f\n", name, amount);
}

void viewExpenses() {
    Expense* current = head;
    if (current == NULL) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("Expenses:\n");
    while (current != NULL) {
        printf(" - %s: %.2f\n", current->name, current->amount);
        current = current->next;
    }
}

void deleteExpense(char* name) {
    Expense* current = head;
    Expense* prev = NULL;
    
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Expense not found: %s\n", name);
        return;
    }

    if (prev == NULL) {
        // Deleting the head
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Expense deleted: %s\n", name);
}

void displayTotalExpenses() {
    float total = 0.0;
    Expense* current = head;
    
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    printf("Total Expenses: %.2f\n", total);
}

void clearExpenses() {
    Expense* current = head;
    Expense* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All expenses cleared.\n");
}

int main() {
    int choice;
    char name[50];
    float amount;

    while (1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Display Total Expenses\n");
        printf("5. Clear All Expenses\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(name, amount);
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                printf("Enter expense name to delete: ");
                scanf("%s", name);
                deleteExpense(name);
                break;
            case 4:
                displayTotalExpenses();
                break;
            case 5:
                clearExpenses();
                break;
            case 6:
                clearExpenses();
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}