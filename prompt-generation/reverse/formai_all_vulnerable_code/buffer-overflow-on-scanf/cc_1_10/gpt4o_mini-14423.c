//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold expense details
typedef struct Expense {
    char name[50];
    float amount;
    struct Expense *next;
} Expense;

// Function prototypes
void addExpense(Expense **head);
void viewExpenses(Expense *head);
void deleteExpense(Expense **head);
void freeExpenses(Expense *head);

int main() {
    Expense *head = NULL;
    int choice;

    do {
        printf("\n--- Expense Tracker ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&head);
                break;
            case 2:
                viewExpenses(head);
                break;
            case 3:
                deleteExpense(&head);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeExpenses(head);
    return 0;
}

void addExpense(Expense **head) {
    Expense *newExpense = (Expense *)malloc(sizeof(Expense));
    if (newExpense == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", newExpense->name);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense->amount);
    newExpense->next = *head;
    *head = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense *head) {
    if (head == NULL) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- List of Expenses ---\n");
    Expense *current = head;
    while (current != NULL) {
        printf("Expense Name: %s, Amount: %.2f\n", current->name, current->amount);
        current = current->next;
    }
}

void deleteExpense(Expense **head) {
    if (*head == NULL) {
        printf("No expenses to delete.\n");
        return;
    }

    char name[50];
    printf("Enter the name of the expense to delete: ");
    scanf("%s", name);

    Expense *current = *head;
    Expense *previous = NULL;
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Expense not found.\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next; // Deleting first expense
    } else {
        previous->next = current->next; // Deleting middle or last expense
    }

    free(current);
    printf("Expense deleted successfully!\n");
}

void freeExpenses(Expense *head) {
    Expense *current = head;
    while (current != NULL) {
        Expense *next = current->next;
        free(current);
        current = next;
    }
}