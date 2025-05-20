//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGETS 100
#define MAX_CATEGORIES 50
#define MAX_TRANSACTIONS 1000

typedef struct {
    char name[50];
    float amount;
} Budget;

typedef struct {
    char name[50];
    int id;
} Category;

typedef struct {
    Category category;
    char description[100];
    float amount;
} Transaction;

int num_budgets = 0;
Budget budgets[MAX_BUDGETS];

int num_categories = 0;
Category categories[MAX_CATEGORIES];

int num_transactions = 0;
Transaction transactions[MAX_TRANSACTIONS];

void add_budget() {
    printf("Enter budget name: ");
    scanf("%s", budgets[num_budgets].name);
    printf("Enter budget amount: ");
    scanf("%f", &budgets[num_budgets].amount);
    num_budgets++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    printf("Enter category ID: ");
    scanf("%d", &categories[num_categories].id);
    num_categories++;
}

void add_transaction() {
    printf("Enter transaction category ID: ");
    int category_id;
    scanf("%d", &category_id);
    Category* category = &categories[category_id];
    transactions[num_transactions].category = *category;

    printf("Enter transaction description: ");
    scanf("%s", transactions[num_transactions].description);

    printf("Enter transaction amount: ");
    scanf("%f", &transactions[num_transactions].amount);

    num_transactions++;
}

void print_budgets() {
    printf("Budgets:\n");
    for (int i = 0; i < num_budgets; i++) {
        printf("%s: $%.2f\n", budgets[i].name, budgets[i].amount);
    }
}

void print_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s (%d):\n", categories[i].name, categories[i].id);
    }
}

void print_transactions() {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - $%.2f (%s)\n", transactions[i].category.name, transactions[i].amount, transactions[i].description);
    }
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add budget\n");
        printf("2. Add category\n");
        printf("3. Add transaction\n");
        printf("4. Print budgets\n");
        printf("5. Print categories\n");
        printf("6. Print transactions\n");
        printf("7. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_budget();
            break;
        case 2:
            add_category();
            break;
        case 3:
            add_transaction();
            break;
        case 4:
            print_budgets();
            break;
        case 5:
            print_categories();
            break;
        case 6:
            print_transactions();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}