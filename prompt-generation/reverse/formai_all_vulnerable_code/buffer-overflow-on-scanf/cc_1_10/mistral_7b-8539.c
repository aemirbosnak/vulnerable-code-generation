//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char *name, const char *description, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Cannot add expense. Max number of expenses reached.\n");
        return;
    }
    strncpy(expenses[num_expenses].name, name, MAX_NAME_LENGTH);
    strncpy(expenses[num_expenses].description, description, MAX_DESCRIPTION_LENGTH);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void display_expenses() {
    int i;
    printf("\nExpenses:\n");
    printf("--------------------------------------------------\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%d. %s - %s: %.2f\n", i+1, expenses[i].name, expenses[i].description, expenses[i].amount);
    }
    printf("--------------------------------------------------\n");
}

int main() {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", name);
                name[strcspn(name, "\n")] = '\0';

                printf("Enter expense description: ");
                scanf("%[^\n]%*c", description);

                printf("Enter expense amount: ");
                scanf("%f", &amount);

                add_expense(name, description, amount);
                break;

            case 2:
                display_expenses();
                break;

            case 3:
                printf("Quitting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}