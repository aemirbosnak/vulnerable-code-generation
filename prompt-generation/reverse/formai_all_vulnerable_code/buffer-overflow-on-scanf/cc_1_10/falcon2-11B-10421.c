//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPENSE 100
#define MAX_NAME_LENGTH 20
#define MAX_AMOUNT_LENGTH 10

struct Expense {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
};

struct Expense expenses[MAX_EXPENSE];
int num_expenses = 0;

void add_expense(const char* name, const char* amount) {
    struct Expense e;
    strncpy(e.name, name, MAX_NAME_LENGTH);
    strncpy(e.amount, amount, MAX_AMOUNT_LENGTH);
    expenses[num_expenses] = e;
    num_expenses++;
}

void display_expenses() {
    int i;
    printf("Expense Tracker\n");
    printf("Name\t\tAmount\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%s\t\t%s\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    char name[MAX_NAME_LENGTH], amount[MAX_AMOUNT_LENGTH];
    int choice;

    printf("Welcome to the Expense Tracker!\n");
    printf("1. Add an expense\n");
    printf("2. Display expenses\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the name of the expense: ");
            fgets(name, MAX_NAME_LENGTH, stdin);
            printf("Enter the amount of the expense: ");
            fgets(amount, MAX_AMOUNT_LENGTH, stdin);
            add_expense(name, amount);
            break;
        case 2:
            display_expenses();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}