//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 50
#define MAX_CATEGORIES 10

typedef struct {
    char name[20];
    double amount;
    char category[20];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses;

char categories[MAX_CATEGORIES][20];
int num_categories;

void add_category() {
    char category[20];
    printf("Enter category name: ");
    scanf("%s", category);
    strcpy(categories[num_categories], category);
    num_categories++;
}

void add_expense() {
    Expense expense;
    printf("Enter expense name: ");
    scanf("%s", expense.name);
    printf("Enter expense amount: $");
    scanf("%lf", &expense.amount);
    printf("Enter expense category: ");
    scanf("%s", expense.category);
    strcpy(expenses[num_expenses].name, expense.name);
    expenses[num_expenses].amount = expense.amount;
    strcpy(expenses[num_expenses].category, expense.category);
    num_expenses++;
}

void view_expenses() {
    printf("\nExpense Report\n");
    printf("--------------------\n");
    printf("Name\tAmount\tCategory\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t$%.2lf\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void view_categories() {
    printf("\nCategories\n");
    printf("----------\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    char choice;
    int i;
    num_expenses = 0;
    num_categories = 0;
    add_category();
    do {
        printf("\nExpense Tracker\n");
        printf("--------------------\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Add category\n");
        printf("4. View categories\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                add_expense();
                break;
            case '2':
                view_expenses();
                break;
            case '3':
                add_category();
                break;
            case '4':
                view_categories();
                break;
            case '5':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= '5');
    return 0;
}