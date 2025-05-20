//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
} expense;

void add_expense(expense expenses[], int num_expenses, char* name, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Sorry, you can only track up to %d expenses.\n", MAX_EXPENSES);
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void print_expenses(expense expenses[], int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    expense expenses[MAX_EXPENSES] = {0};
    int num_expenses = 0;

    char input[100];
    while (1) {
        printf("Enter an expense (name:amount) or type 'quit' to exit: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        char* name;
        float amount;
        if (sscanf(input, "%s:%f", &name, &amount)!= 2) {
            printf("Invalid input. Please enter an expense in the format 'name:amount'.\n");
            continue;
        }

        add_expense(expenses, num_expenses, name, amount);
    }

    print_expenses(expenses, num_expenses);

    return 0;
}