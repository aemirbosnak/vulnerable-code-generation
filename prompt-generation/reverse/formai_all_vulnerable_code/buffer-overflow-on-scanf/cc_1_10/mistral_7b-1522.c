//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define EXPENSE_NAME_LENGTH 50
#define EXPENSE_AMOUNT_PRECISION 10

typedef struct Expense {
    char name[EXPENSE_NAME_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void print_menu() {
    printf("\nExpense Tracker\n");
    printf("-----------------------\n");
    printf("1. Add Expense\n");
    printf("2. List Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Search Expenses\n");
    printf("5. Quit\n");
}

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    fgets(expenses[num_expenses].name, EXPENSE_NAME_LENGTH, stdin);
    expenses[num_expenses].name[strcspn(expenses[num_expenses].name, "\n")] = '\0';

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    num_expenses++;
}

void list_expenses() {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("\nExpense List\n");
    printf("-----------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s: %.2f\n", i+1, expenses[i].name, expenses[i].amount);
    }
}

void delete_expense() {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("Enter expense index to delete: ");
    int index;
    scanf("%d", &index);

    if (index < 1 || index > num_expenses) {
        printf("Invalid expense index.\n");
        return;
    }

    memmove(expenses + index - 1, expenses + index, (num_expenses - index) * sizeof(Expense));
    num_expenses--;

    printf("Expense deleted successfully.\n");
}

void search_expenses() {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("Enter expense name to search: ");
    char search_name[EXPENSE_NAME_LENGTH];
    fgets(search_name, EXPENSE_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcasecmp(expenses[i].name, search_name) == 0) {
            printf("Expense found: %s: %.2f\n", expenses[i].name, expenses[i].amount);
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
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                list_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                search_expenses();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}