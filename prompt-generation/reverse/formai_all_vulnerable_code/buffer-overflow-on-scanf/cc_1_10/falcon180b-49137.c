//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRANSACTIONS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

int num_transactions = 0;
Expense transactions[MAX_TRANSACTIONS];

int num_categories = 0;
char categories[MAX_CATEGORIES][50];

void add_transaction() {
    if (num_transactions == MAX_TRANSACTIONS) {
        printf("Maximum number of transactions reached.\n");
        return;
    }

    printf("Enter transaction name: ");
    scanf("%s", transactions[num_transactions].name);

    printf("Enter transaction amount: ");
    if (scanf("%f", &transactions[num_transactions].amount)!= 1) {
        printf("Invalid input. Please enter a valid amount.\n");
        return;
    }

    printf("Enter transaction category: ");
    scanf("%s", transactions[num_transactions].category);

    num_transactions++;
}

void add_category() {
    if (num_categories == MAX_CATEGORIES) {
        printf("Maximum number of categories reached.\n");
        return;
    }

    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);

    num_categories++;
}

void view_transactions() {
    printf("\nTransaction List:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d. %s (%s) - $%.2f\n", i+1, transactions[i].name, transactions[i].category, transactions[i].amount);
    }
}

void view_categories() {
    printf("\nCategory List:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    add_category();
    add_transaction();
    view_transactions();
    view_categories();

    return 0;
}