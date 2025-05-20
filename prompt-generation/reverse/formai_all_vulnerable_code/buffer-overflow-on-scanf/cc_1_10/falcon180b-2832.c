//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int expenses[MAX_EXPENSES];
} category;

typedef struct {
    char name[50];
    int id;
} expense;

category categories[MAX_CATEGORIES];
expense expenses[MAX_EXPENSES];
int num_categories = 0;
int num_expenses = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void add_expense() {
    int category_id;
    printf("Enter category ID: ");
    scanf("%d", &category_id);
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%d", &expenses[num_expenses].id);
    expenses[num_expenses].id = category_id;
    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %d\n", expenses[i].name, expenses[i].id);
    }
}

void view_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

int main() {
    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. View categories\n");
        printf("4. View expenses\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_expense();
                break;
            case 3:
                view_categories();
                break;
            case 4:
                view_expenses();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);
    return 0;
}