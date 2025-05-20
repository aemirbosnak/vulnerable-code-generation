//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    int category;
} Expense;

Expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][50];
int num_expenses = 0;
int num_categories = 0;

void add_category() {
    if (num_categories == MAX_CATEGORIES) {
        printf("Sorry, maximum number of categories reached.\n");
        return;
    }
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);
    num_categories++;
}

void add_expense() {
    if (num_expenses == MAX_EXPENSES) {
        printf("Sorry, maximum number of expenses reached.\n");
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense category (0-%d): ", num_categories - 1);
    scanf("%d", &expenses[num_expenses].category);
    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%.2f - %s (%s)\n", expenses[i].amount, expenses[i].name, categories[expenses[i].category]);
    }
}

int main() {
    srand(time(0));
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        categories[i][0] = '\0';
    }
    num_categories = 0;
    num_expenses = 0;

    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. Display expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_category();
            break;
        case 2:
            add_expense();
            break;
        case 3:
            display_expenses();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 4);

    return 0;
}