//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} expense_t;

expense_t expenses[MAX_ITEMS];
int num_expenses = 0;

void add_expense() {
    char name[MAX_NAME_LENGTH];
    float amount;

    printf("Enter expense name: ");
    scanf("%s", name);
    printf("Enter expense amount: ");
    scanf("%f", &amount);

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            expenses[i].amount += amount;
            printf("Expense '%s' already exists. Amount updated.\n", name);
            return;
        }
    }

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    num_expenses++;

    printf("Expense '%s' added successfully.\n", name);
}

void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void delete_expense() {
    char name[MAX_NAME_LENGTH];

    printf("Enter expense name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            for (int j = i; j < num_expenses - 1; j++) {
                strcpy(expenses[j].name, expenses[j + 1].name);
                expenses[j].amount = expenses[j + 1].amount;
            }
            num_expenses--;
            printf("Expense '%s' deleted successfully.\n", name);
            return;
        }
    }

    printf("Expense not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("Expense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Delete expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense();
            break;
        case 2:
            view_expenses();
            break;
        case 3:
            delete_expense();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}