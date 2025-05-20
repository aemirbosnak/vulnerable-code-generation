//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

typedef struct Expense {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Max number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    num_expenses++;
}

void list_expenses() {
    printf("\nExpense List:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s - %s - %.2f\n", i+1, expenses[i].name, expenses[i].description, expenses[i].amount);
    }
}

void search_expense() {
    char search_name[MAX_NAME_LEN];
    float search_amount;
    int found = 0;

    printf("Enter name to search for: ");
    scanf("%s", search_name);

    printf("Enter expense amount to search for: ");
    scanf("%f", &search_amount);

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, search_name) == 0 && expenses[i].amount == search_amount) {
            printf("Expense found: %s - %s - %.2f\n", expenses[i].name, expenses[i].description, expenses[i].amount);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Expense not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Search Expense\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                list_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}