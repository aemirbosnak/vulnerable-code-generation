//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_CATEGORIES 20
#define MAX_CATEGORY_NAME_LENGTH 50
#define MAX_TRANSACTION_NAME_LENGTH 100

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int budget;
} category_t;

typedef struct {
    char name[MAX_TRANSACTION_NAME_LENGTH];
    char category[MAX_CATEGORY_NAME_LENGTH];
    double amount;
} transaction_t;

category_t categories[MAX_CATEGORIES];
transaction_t transactions[MAX_BUDGET_ITEMS];
int num_categories = 0;
int num_transactions = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    printf("Enter budget for %s: ", categories[num_categories].name);
    scanf("%d", &categories[num_categories].budget);
    num_categories++;
}

void add_transaction() {
    printf("Enter transaction name: ");
    scanf("%s", transactions[num_transactions].name);
    printf("Enter category for %s: ", transactions[num_transactions].name);
    scanf("%s", transactions[num_transactions].category);
    printf("Enter amount for %s: ", transactions[num_transactions].name);
    scanf("%lf", &transactions[num_transactions].amount);
    num_transactions++;
}

void print_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: $%d\n", categories[i].name, categories[i].budget);
    }
}

void print_transactions() {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: $%.2f in %s\n", transactions[i].name, transactions[i].amount, transactions[i].category);
    }
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your categories and their budgets:\n");

    while (num_categories < MAX_CATEGORIES) {
        add_category();
    }

    printf("\nPlease enter your transactions:\n");

    while (num_transactions < MAX_BUDGET_ITEMS) {
        add_transaction();
    }

    print_categories();
    print_transactions();

    return 0;
}