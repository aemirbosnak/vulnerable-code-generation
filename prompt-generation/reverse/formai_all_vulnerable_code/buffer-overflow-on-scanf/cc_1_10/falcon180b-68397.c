//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct expense {
    char category[MAX_CATEGORIES];
    float amount;
    char description[100];
    int date;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char input[100];

    while (1) {
        printf("Enter expense category (e.g. food, rent, bills, etc.): ");
        scanf("%s", input);
        strcpy(expenses[num_expenses].category, input);

        printf("Enter expense amount: ");
        scanf("%f", &expenses[num_expenses].amount);

        printf("Enter expense description: ");
        scanf("%s", expenses[num_expenses].description);

        printf("Enter expense date (YYYY-MM-DD): ");
        scanf("%d", &expenses[num_expenses].date);

        num_expenses++;

        if (num_expenses == MAX_EXPENSES) {
            printf("Maximum number of expenses reached.\n");
            break;
        }

        printf("\nDo you want to enter another expense? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("Category: %s\nAmount: %.2f\nDescription: %s\nDate: %d\n",
                expenses[i].category, expenses[i].amount, expenses[i].description, expenses[i].date);
    }

    return 0;
}