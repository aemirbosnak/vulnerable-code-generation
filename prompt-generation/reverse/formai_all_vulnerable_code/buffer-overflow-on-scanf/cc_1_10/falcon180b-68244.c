//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char description[MAX_NAME_LENGTH];
    int date;
} Expense;

void add_expense(Expense* expenses, int num_expenses, char* name, float amount, char* description) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Cannot add more than %d expenses.\n", MAX_EXPENSES);
        return;
    }

    strncpy(expenses[num_expenses].name, name, MAX_NAME_LENGTH);
    expenses[num_expenses].amount = amount;
    strncpy(expenses[num_expenses].description, description, MAX_NAME_LENGTH);
    expenses[num_expenses].date = time(NULL);
    num_expenses++;
}

void print_expenses(Expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f (%s)\n", expenses[i].name, expenses[i].amount, expenses[i].description);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    char name[MAX_NAME_LENGTH];
    float amount;
    char description[MAX_NAME_LENGTH];

    while (1) {
        printf("Enter name (leave blank to exit): ");
        scanf("%s", name);
        if (name[0] == '\0') {
            break;
        }

        printf("Enter amount: ");
        scanf("%f", &amount);

        printf("Enter description: ");
        scanf("%s", description);

        add_expense(expenses, num_expenses, name, amount, description);
    }

    print_expenses(expenses, num_expenses);

    return 0;
}