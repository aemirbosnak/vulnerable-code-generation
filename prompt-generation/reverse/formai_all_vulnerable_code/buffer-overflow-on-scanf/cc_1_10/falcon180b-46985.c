//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 20
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    double amount;
} expense;

int num_expenses = 0;
int num_categories = 0;

expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);
    
    num_expenses++;
}

void view_expenses() {
    for (int i = 0; i < num_expenses; i++) {
        printf("Name: %s\nCategory: %s\nAmount: %.2lf\n\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);
    
    num_categories++;
}

void main() {
    add_expense();
    add_expense();
    add_category();
    add_category();
    
    view_expenses();
    
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}