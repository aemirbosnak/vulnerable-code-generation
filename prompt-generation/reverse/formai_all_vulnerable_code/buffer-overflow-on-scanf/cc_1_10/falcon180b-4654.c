//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];
int num_categories = 0;

void add_category() {
    char input[MAX_NAME_LENGTH];

    printf("Enter category name: ");
    scanf("%s", input);

    strcpy(categories[num_categories], input);
    num_categories++;
}

void add_expense() {
    char input[MAX_NAME_LENGTH];
    float amount;
    int category_index;

    printf("Enter expense name: ");
    scanf("%s", input);

    printf("Enter expense amount: ");
    scanf("%f", &amount);

    printf("Enter expense category (0 for none): ");
    scanf("%d", &category_index);

    strcpy(expenses[num_expenses].name, input);
    expenses[num_expenses].amount = amount;

    if (category_index > 0 && category_index <= num_categories) {
        strcpy(expenses[num_expenses].category, categories[category_index - 1]);
    } else {
        strcpy(expenses[num_expenses].category, "");
    }

    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    printf("--------------------\n");
    printf("Name\tAmount\tCategory\n");
    printf("--------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s $%.2f %-20s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void display_categories() {
    printf("\nCategories:\n");
    printf("--------------------\n");

    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    int choice;

    printf("Welcome to the Expense Tracker!\n");
    printf("--------------------\n");

    while (1) {
        printf("\n1. Add Expense\n2. Add Category\n3. Display Expenses\n4. Display Categories\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense();
            break;
        case 2:
            add_category();
            break;
        case 3:
            display_expenses();
            break;
        case 4:
            display_categories();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}