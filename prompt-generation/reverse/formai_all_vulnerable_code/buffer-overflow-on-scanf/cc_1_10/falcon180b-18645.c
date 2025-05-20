//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    char name[50];
    double amount;
    int month;
    int day;
    int year;
} transaction;

typedef struct {
    char name[50];
    double budget;
} budget_item;

void add_transaction(transaction *transactions, int *num_transactions) {
    printf("Enter transaction name: ");
    scanf("%s", &transactions[*num_transactions].name);
    printf("Enter transaction amount: ");
    scanf("%lf", &transactions[*num_transactions].amount);
    printf("Enter transaction date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &transactions[*num_transactions].month, &transactions[*num_transactions].day, &transactions[*num_transactions].year);
    (*num_transactions)++;
}

void add_budget_item(budget_item *budget, int *num_items) {
    printf("Enter budget item name: ");
    scanf("%s", &budget[*num_items].name);
    printf("Enter budget item amount: ");
    scanf("%lf", &budget[*num_items].budget);
    (*num_items)++;
}

void print_transactions(transaction *transactions, int num_transactions) {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: $%.2lf on %d/%d/%d\n", transactions[i].name, transactions[i].amount, transactions[i].month, transactions[i].day, transactions[i].year);
    }
}

void print_budget(budget_item *budget, int num_items) {
    printf("Budget:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: $%.2lf\n", budget[i].name, budget[i].budget);
    }
}

void main() {
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;
    budget_item budget[MAX_BUDGET_ITEMS];
    int num_items = 0;

    add_budget_item(budget, &num_items);
    add_budget_item(budget, &num_items);
    add_budget_item(budget, &num_items);

    add_transaction(transactions, &num_transactions);
    add_transaction(transactions, &num_transactions);
    add_transaction(transactions, &num_transactions);

    print_budget(budget, num_items);
    print_transactions(transactions, num_transactions);
}