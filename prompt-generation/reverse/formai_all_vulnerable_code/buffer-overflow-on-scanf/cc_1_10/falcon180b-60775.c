//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_NAME_LEN];
    double amount;
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int num_transactions;

char categories[MAX_CATEGORIES][MAX_NAME_LEN];
int num_categories;

void add_category() {
    char name[MAX_NAME_LEN];
    printf("Enter category name: ");
    scanf("%s", name);

    for(int i = 0; i < num_categories; i++) {
        if(strcmp(name, categories[i]) == 0) {
            printf("Category already exists.\n");
            return;
        }
    }

    strcpy(categories[num_categories], name);
    num_categories++;
}

void add_transaction() {
    char name[MAX_NAME_LEN];
    char category[MAX_NAME_LEN];
    double amount;

    printf("Enter transaction name: ");
    scanf("%s", name);

    printf("Enter category: ");
    scanf("%s", category);

    printf("Enter amount: ");
    scanf("%lf", &amount);

    for(int i = 0; i < num_categories; i++) {
        if(strcmp(category, categories[i]) == 0) {
            strcpy(transactions[num_transactions].category, category);
            break;
        }
    }

    strcpy(transactions[num_transactions].name, name);
    transactions[num_transactions].amount = amount;

    num_transactions++;
}

void view_transactions() {
    for(int i = 0; i < num_transactions; i++) {
        printf("%s - %s - $%.2f\n", transactions[i].name, transactions[i].category, transactions[i].amount);
    }
}

int main() {
    num_categories = 0;
    num_transactions = 0;

    add_category();
    add_category();

    add_transaction();
    add_transaction();

    view_transactions();

    return 0;
}