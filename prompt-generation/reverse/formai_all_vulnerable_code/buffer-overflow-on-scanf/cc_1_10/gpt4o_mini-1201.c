//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: innovative
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
    if (!newExpense) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", newExpense->name);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense->amount);
    
    newExpense->next = head;
    head = newExpense;

    printf("Expense added successfully!\n");
}

void viewExpenses() {
    if (head == NULL) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    Expense *current = head;
    while (current != NULL) {
        printf("Name: %s, Amount: %.2f\n", current->name, current->amount);
        current = current->next;
    }
    printf("---------------------\n");
}

void deleteExpense() {
    if (head == NULL) {
        printf("No expenses to delete.\n");
        return;
    }
    
    char name[50];
    printf("Enter the name of the expense to delete: ");
    scanf("%s", name);
    
    Expense *current = head;
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
        head = current->next;
    } else {
        previous->next = current->next;
    }
    
    free(current);
    printf("Expense deleted successfully!\n");
}

void totalExpenses() {
    float total = 0.0;
    Expense *current = head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    printf("Total Expenses: %.2f\n", total);
}

void freeMemory() {
    Expense *current = head;
    Expense *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Expense Tracker ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Total Expenses\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                totalExpenses();
                break;
            case 5:
                freeMemory();
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}