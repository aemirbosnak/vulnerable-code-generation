//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} Expense;

void addExpense(Expense* expenses, int count, char* name, char* amount) {
    if (count >= MAX_ITEMS) {
        printf("Error: Expense tracker is full.\n");
        return;
    }

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            printf("Error: Duplicate expense name.\n");
            return;
        }
    }

    strcpy(expenses[count].name, name);
    strcpy(expenses[count].amount, amount);
    count++;
}

void displayExpenses(Expense* expenses, int count) {
    printf("Expenses:\n");
    printf("Name\tAmount\n");

    int i;
    for (i = 0; i < count; i++) {
        printf("%s\t%s\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    Expense expenses[MAX_ITEMS];
    int count = 0;

    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];

    while (1) {
        printf("Enter expense name (or type 'display' to show expenses): ");
        scanf("%s", name);

        if (strcmp(name, "display") == 0) {
            displayExpenses(expenses, count);
        } else {
            printf("Enter expense amount: ");
            scanf("%s", amount);

            addExpense(expenses, count, name, amount);
        }
    }

    return 0;
}