//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char name[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void addExpense() {
    Expense *newExpense = (Expense *)malloc(sizeof(Expense));

    printf("Enter expense name: ");
    scanf("%s", newExpense->name);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense->amount);

    newExpense->next = head;
    head = newExpense;

    printf("Expense added successfully!\n");
}

void displayExpenses() {
    if (head == NULL) {
        printf("No expenses recorded.\n");
        return;
    }

    Expense *current = head;
    printf("Expenses:\n");
    printf("%-20s %-10s\n", "Name", "Amount");
    printf("------------------------------\n");
    while (current != NULL) {
        printf("%-20s $%.2f\n", current->name, current->amount);
        current = current->next;
    }
}

void deleteExpense() {
    char name[50];
    printf("Enter expense name to delete: ");
    scanf("%s", name);

    Expense *current = head;
    Expense *previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Expense not found!\n");
        return;
    }

    if (previous == NULL) {
        head = current->next; // Delete head
    } else {
        previous->next = current->next; // Bypass the current
    }

    free(current);
    printf("Expense deleted successfully!\n");
}

void freeExpenses() {
    Expense *current = head;
    while (current != NULL) {
        Expense *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

void showMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeExpenses();
    return 0;
}