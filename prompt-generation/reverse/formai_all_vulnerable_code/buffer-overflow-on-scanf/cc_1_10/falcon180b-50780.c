//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
char categories[MAX_CATEGORIES][50];
int num_transactions;
int num_categories;

void add_transaction() {
    printf("Enter transaction name: ");
    scanf("%s", transactions[num_transactions].name);
    printf("Enter transaction amount: ");
    scanf("%f", &transactions[num_transactions].amount);
    printf("Enter transaction category: ");
    scanf("%s", transactions[num_transactions].category);
    num_transactions++;
}

void view_transactions() {
    printf("Transaction Name\tAmount\tCategory\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s\t%.2f\t%s\n", transactions[i].name, transactions[i].amount, transactions[i].category);
    }
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);
    num_categories++;
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    num_transactions = 0;
    num_categories = 0;

    add_category();
    add_category();
    add_category();

    add_transaction();
    add_transaction();

    view_categories();
    view_transactions();

    return 0;
}