//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

typedef struct Expense {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char* name, const char* category, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Expense tracker is full.\n");
        return;
    }

    strncpy(expenses[num_expenses].name, name, MAX_NAME_LENGTH);
    strncpy(expenses[num_expenses].category, category, MAX_CATEGORY_LENGTH);
    expenses[num_expenses].amount = amount;

    num_expenses++;
}

void print_expenses() {
    printf("\nExpenses:\n");
    printf("%-30s %-20s %-10s\n", "Name", "Category", "Amount");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-30s %-20s $%.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void search_expenses(const char* keyword) {
    printf("\nExpenses matching '%s':\n", keyword);

    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].name, keyword) || strstr(expenses[i].category, keyword)) {
            printf("%-30s %-20s $%.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
        }
    }
}

int main() {
    char command[10];
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;

    while (1) {
        printf("\nExpense Tracker>\n");
        printf("Command (add/print/search/quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        switch (*command) {
            case 'a':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter category: ");
                scanf("%s", category);
                printf("Enter amount: ");
                scanf("%f", &amount);
                add_expense(name, category, amount);
                break;

            case 'p':
                print_expenses();
                break;

            case 's':
                printf("Enter keyword: ");
                scanf("%s", command);
                search_expenses(command);
                break;

            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}