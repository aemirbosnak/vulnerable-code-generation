//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10

typedef struct {
    char description[50];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char *description, float amount);
void remove_expense(int index);
void list_expenses();

int main() {
    int choice;
    char input_desc[50];
    float input_amount;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Remove Expense\n");
        printf("3. List Expenses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter description: ");
                scanf("%s", input_desc);
                printf("Enter amount: ");
                scanf("%f", &input_amount);
                add_expense(input_desc, input_amount);
                break;
            case 2:
                if (num_expenses > 0) {
                    printf("Enter index to remove: ");
                    int index;
                    scanf("%d", &index);
                    remove_expense(index);
                } else {
                    printf("No expenses to remove.\n");
                }
                break;
            case 3:
                list_expenses();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void add_expense(const char *description, float amount) {
    if (num_expenses < MAX_EXPENSES) {
        strcpy(expenses[num_expenses].description, description);
        expenses[num_expenses].amount = amount;
        num_expenses++;
    } else {
        printf("Maximum number of expenses reached.\n");
    }
}

void remove_expense(int index) {
    if (index >= 0 && index < num_expenses) {
        memmove(&expenses[index], &expenses[index + 1],
                (num_expenses - index - 1) * sizeof(Expense));
        num_expenses--;
    } else {
        printf("Invalid index.\n");
    }
}

void list_expenses() {
    if (num_expenses > 0) {
        printf("\nExpenses:\n");
        for (int i = 0; i < num_expenses; i++) {
            printf("%d. %s: %.2f\n", i + 1, expenses[i].description,
                  expenses[i].amount);
        }
    } else {
        printf("No expenses to list.\n");
    }
}