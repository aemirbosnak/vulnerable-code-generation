//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_EXPENSES 1000

typedef struct {
    char name[100];
    int total_expenses;
} Category;

typedef struct {
    char name[100];
    float price;
} Item;

typedef struct {
    int category_id;
    char name[100];
    float price;
} Expense;

Category categories[MAX_CATEGORIES];
Item items[MAX_ITEMS];
Expense expenses[MAX_EXPENSES];

int num_categories = 0;
int num_items = 0;
int num_expenses = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void add_expense() {
    printf("Enter category ID: ");
    scanf("%d", &expenses[num_expenses].category_id);
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense price: ");
    scanf("%f", &expenses[num_expenses].price);
    num_expenses++;
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void view_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
}

void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f (%d)\n", expenses[i].name, expenses[i].price, expenses[i].category_id);
    }
}

int main() {
    printf("Welcome to Expense Tracker!\n");
    printf("Enter 1 to add a category\n");
    printf("Enter 2 to add an item\n");
    printf("Enter 3 to add an expense\n");
    printf("Enter 4 to view categories\n");
    printf("Enter 5 to view items\n");
    printf("Enter 6 to view expenses\n");
    printf("Enter 0 to exit\n");

    int choice;
    while (true) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_item();
                break;
            case 3:
                add_expense();
                break;
            case 4:
                view_categories();
                break;
            case 5:
                view_items();
                break;
            case 6:
                view_expenses();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}