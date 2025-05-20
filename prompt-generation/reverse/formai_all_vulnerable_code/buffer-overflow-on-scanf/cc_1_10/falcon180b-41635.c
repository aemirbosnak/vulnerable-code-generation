//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    int category;
} expense;

typedef struct {
    char name[50];
    int id;
} category;

int num_expenses = 0;
int num_categories = 0;

category categories[MAX_CATEGORIES];
expense expenses[MAX_EXPENSES];

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].id = num_categories;
    num_categories++;
}

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense category: ");
    int category_id;
    scanf("%d", &category_id);
    expenses[num_expenses].category = category_id;
    num_expenses++;
}

void display_categories() {
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
}

void display_expenses() {
    for (int i = 0; i < num_expenses; i++) {
        printf("Expense %d: %s - $%.2f - Category: %s\n", i+1, expenses[i].name, expenses[i].amount, categories[expenses[i].category].name);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. Display categories\n");
        printf("4. Display expenses\n");
        printf("5. Exit\n");
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
                display_categories();
                break;
            case 4:
                display_expenses();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}