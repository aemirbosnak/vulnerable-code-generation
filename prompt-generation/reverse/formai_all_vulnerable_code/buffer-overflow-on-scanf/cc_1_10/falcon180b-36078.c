//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
    int category;
} Expense;

Expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][MAX_NAME_LEN];
int num_expenses = 0;

void add_expense(void) {
    char name[MAX_NAME_LEN];
    float amount;
    int category;

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter expense amount: $");
    scanf("%f", &amount);

    printf("Enter expense category (1-%d): ", MAX_CATEGORIES - 1);
    scanf("%d", &category);

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].category = category;

    num_expenses++;
}

void display_expenses(int category) {
    int i;

    printf("Expenses in category %d:\n", category);

    for (i = 0; i < num_expenses; i++) {
        if (expenses[i].category == category) {
            printf("- %s: $%.2f\n", expenses[i].name, expenses[i].amount);
        }
    }
}

int main(void) {
    int i, choice;

    for (i = 0; i < MAX_CATEGORIES; i++) {
        printf("Enter category %d name: ", i + 1);
        scanf("%s", categories[i]);
    }

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Display expenses by category\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense();
            break;

        case 2:
            printf("Enter category number: ");
            scanf("%d", &choice);

            if (choice >= 1 && choice <= MAX_CATEGORIES) {
                display_expenses(choice - 1);
            } else {
                printf("Invalid category number.\n");
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}