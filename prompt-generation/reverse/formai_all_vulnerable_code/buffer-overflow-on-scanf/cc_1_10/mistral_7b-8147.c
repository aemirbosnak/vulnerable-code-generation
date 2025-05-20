//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50

typedef struct {
    int id;
    char description[50];
    float amount;
    char date[11];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(Expense new_expense) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    expenses[num_expenses] = new_expense;
    num_expenses++;
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("Error: No expenses to display.\n");
        return;
    }
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s: %.2f %s\n", i+1, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void delete_expense(int index) {
    if (index < 1 || index > num_expenses) {
        printf("Error: Invalid expense index.\n");
        return;
    }
    for (int i = index; i < num_expenses; i++) {
        expenses[i-1] = expenses[i];
    }
    num_expenses--;
}

void get_date_input(char date[]) {
    scanf("%s", date);
}

int main() {
    char command[5], description[50], temp_date[11];
    int id, index;
    float amount;

    while (1) {
        printf("\nExpense Tracker > ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            Expense new_expense;
            get_date_input(temp_date);
            strcpy(new_expense.date, temp_date);
            printf("Description: ");
            scanf("%s", description);
            strcpy(new_expense.description, description);
            printf("Amount: ");
            scanf("%f", &amount);
            new_expense.amount = amount;
            add_expense(new_expense);
        } else if (strcmp(command, "view") == 0) {
            view_expenses();
        } else if (strcmp(command, "delete") == 0) {
            printf("Index: ");
            scanf("%d", &index);
            delete_expense(index);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}