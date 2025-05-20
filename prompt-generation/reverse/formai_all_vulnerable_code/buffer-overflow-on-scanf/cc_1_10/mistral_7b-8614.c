//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DEFAULT_CATEGORY "General"

typedef struct {
    char category[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void add_expense(char *category, float amount) {
    Expense *new_expense = (Expense *)malloc(sizeof(Expense));
    strcpy(new_expense->category, category);
    new_expense->amount = amount;
    new_expense->next = head;
    head = new_expense;
}

void print_expenses() {
    Expense *current = head;
    printf("\nExpenses:\n");
    while (current != NULL) {
        printf("%s: %.2f\n", current->category, current->amount);
        current = current->next;
    }
}

void configure_tracker() {
    char category[50];
    float amount;
    int choice;

    printf("\nWelcome to the Expense Tracker!\n");
    printf("Press 1 to add an expense, 2 to print all expenses, or 3 to quit:\n");

    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter category: ");
                scanf("%s", category);
                printf("Enter amount: ");
                scanf("%f", &amount);
                add_expense(category, amount);
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("Press 1 to add another expense, or any other key to go back to the main menu:\n");
        getchar();
    }
}

int main() {
    configure_tracker();

    return 0;
}