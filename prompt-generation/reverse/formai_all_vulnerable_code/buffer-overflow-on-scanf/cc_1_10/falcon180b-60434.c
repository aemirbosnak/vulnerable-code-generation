//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_EXPENSES 1000

typedef struct {
    char name[50];
    float amount;
    char category[50];
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

typedef struct {
    char name[50];
    float budget;
} category;

category categories[MAX_CATEGORIES];
int num_categories = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    printf("Enter category budget: ");
    scanf("%f", &categories[num_categories].budget);
    num_categories++;
}

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void view_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s - $%.2f\n", categories[i].name, categories[i].budget);
    }
}

void main() {
    int choice;
    char cont = 'y';

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. View categories\n");
        printf("4. View expenses\n");
        printf("5. Quit\n");
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
                view_categories();
                break;
            case 4:
                view_expenses();
                break;
            case 5:
                cont = 'n';
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (cont == 'y');
}