//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 100
#define MAX_EXPENSES 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} Category;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int category_id;
    float amount;
    char date[10];
} Expense;

Category categories[MAX_CATEGORIES];
Expense expenses[MAX_EXPENSES];
int num_categories = 0;
int num_expenses = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].id = num_categories + 1;
    num_categories++;
}

void add_expense() {
    int i, found = 0;
    printf("Enter expense category: ");
    scanf("%d", &i);
    for (int j = 0; j < num_categories; j++) {
        if (categories[j].id == i) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Invalid category.\n");
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    strcpy(expenses[num_expenses].date, __DATE__);
    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    printf("ID\tCategory\tExpense Name\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d\t%s\t%s\t%.2f\t%s\n", i + 1, categories[expenses[i].category_id - 1].name, expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

void view_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d\t%s\n", i + 1, categories[i].name);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("\nOptions:\n1. Add category\n2. Add expense\n3. View expenses\n4. View categories\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_category();
            break;
        case 2:
            add_expense();
            break;
        case 3:
            view_expenses();
            break;
        case 4:
            view_categories();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }
    return 0;
}