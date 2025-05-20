//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter expense amount: ");
    scanf("%s", expenses[num_expenses].amount);

    num_expenses++;
}

void print_expenses() {
    printf("Name\tCategory\tAmount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void calculate_total_expenses() {
    int total_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += atoi(expenses[i].amount);
    }

    printf("Total expenses: %d\n", total_expenses);
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    int choice;
    while (1) {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                calculate_total_expenses();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}