//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    int id;
} Category;

typedef struct {
    char description[100];
    Category category;
    double amount;
    char date[20];
} Transaction;

Category categories[MAX_CATEGORIES];
Transaction transactions[MAX_TRANSACTIONS];

int num_categories = 0;
int num_transactions = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].id = num_categories + 1;
    num_categories++;
}

void add_transaction() {
    printf("Enter transaction description: ");
    scanf("%s", transactions[num_transactions].description);
    printf("Enter category ID: ");
    scanf("%d", &transactions[num_transactions].category.id);
    transactions[num_transactions].category.id--;
    strcpy(transactions[num_transactions].category.name, categories[transactions[num_transactions].category.id].name);
    printf("Enter transaction amount: ");
    scanf("%lf", &transactions[num_transactions].amount);
    printf("Enter transaction date (YYYY-MM-DD): ");
    scanf("%s", transactions[num_transactions].date);
    num_transactions++;
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", categories[i].id, categories[i].name);
    }
}

void view_transactions() {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - %.2lf - %s - %s\n", transactions[i].description, transactions[i].amount, transactions[i].category.name, transactions[i].date);
    }
}

void main() {
    printf("Welcome to Personal Finance Planner\n");
    printf("===============================\n");

    add_category();
    add_category();

    view_categories();

    add_transaction();
    add_transaction();

    view_transactions();
}