//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 20
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];
int num_categories = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    num_expenses++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);

    num_categories++;
}

void view_expenses() {
    printf("Expense Name | Expense Amount | Category\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-50s | $%.2f | %-20s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. Add category\n");
        printf("3. View expenses\n");
        printf("4. View categories\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                add_category();
                break;
            case 3:
                view_expenses();
                break;
            case 4:
                view_categories();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}