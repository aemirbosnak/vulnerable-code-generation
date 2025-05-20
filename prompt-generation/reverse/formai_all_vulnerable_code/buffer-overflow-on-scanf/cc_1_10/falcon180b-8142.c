//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[30];
    float amount;
    char category[30];
} Expense;

Expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][30];
int num_expenses = 0;
int num_categories = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: $");
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

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

void display_menu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add expense\n");
    printf("2. Add category\n");
    printf("3. Display expenses\n");
    printf("4. Display categories\n");
    printf("5. Exit\n");
}

int main() {
    display_menu();
    int choice;
    while (choice!= 5) {
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
            default:
                printf("Invalid choice. Please try again.\n");
        }
        display_menu();
    }
    return 0;
}