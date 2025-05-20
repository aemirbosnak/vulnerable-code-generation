//FormAI DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPENT_AMOUNT 1000
#define MAX_DESCRIPTION_LENGTH 50

typedef struct expense {
    float amount;
    char description[MAX_DESCRIPTION_LENGTH];
    struct expense *next;
} Expense;

Expense *head = NULL;

// Function to add a new expense to the list
void add_expense() {
    Expense *new_expense = (Expense*) malloc(sizeof(Expense));
    printf("\nEnter spent amount: ");
    scanf("%f", &new_expense->amount);
    printf("Enter description: ");
    scanf(" %[^\n]", new_expense->description);
    new_expense->next = head;
    head = new_expense;
}

// Function to print the list of expenses
void print_list() {
    printf("\nExpense List:\n");
    Expense *temp = head;
    while (temp != NULL) {
        printf("- $%0.2f - %s\n", temp->amount, temp->description);
        temp = temp->next;
    }
}

// Function to calculate the total amount spent
float total_spent() {
    float total = 0;
    Expense *temp = head;
    while (temp != NULL) {
        total += temp->amount;
        temp = temp->next;
    }
    return total;
}

int main() {
    int choice = 0;
    while (choice != 4) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Print Expense List\n");
        printf("3. Total Spent\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                print_list();
                break;
            case 3:
                printf("\nTotal spent so far: $%0.2f\n", total_spent());
                break;
            case 4:
                printf("\nExiting Expense Tracker.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}