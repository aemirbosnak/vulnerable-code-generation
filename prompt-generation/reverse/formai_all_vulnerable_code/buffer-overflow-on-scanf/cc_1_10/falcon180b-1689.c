//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
} expense_t;

expense_t expenses[MAX_ITEMS];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_ITEMS) {
        printf("Error: Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter expense amount: ");
    scanf("%s", expenses[num_expenses].amount);

    num_expenses++;
    printf("Expense added successfully.\n");
}

void view_expenses() {
    printf("Expense Name | Expense Category | Expense Amount\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-50s | %-50s | %s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\n1. Add expense\n2. View expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense();
            break;

        case 2:
            view_expenses();
            break;

        case 3:
            printf("Thank you for using the Expense Tracker!\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}