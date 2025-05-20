//Falcon-180B DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

struct item {
    char name[50];
    float price;
    int category;
};

struct transaction {
    int num_items;
    struct item items[MAX_ITEMS];
};

int main() {
    int num_transactions, i, j, k;
    struct transaction transactions[MAX_ITEMS];
    struct item items[MAX_ITEMS];
    float total_sales;
    int category_sales[MAX_CATEGORIES] = {0};

    // Read in transactions
    printf("Enter number of transactions: ");
    scanf("%d", &num_transactions);

    for (i = 0; i < num_transactions; i++) {
        printf("Enter transaction %d:\n", i+1);
        scanf("%d", &transactions[i].num_items);

        for (j = 0; j < transactions[i].num_items; j++) {
            scanf("%s %f %d", transactions[i].items[j].name, &transactions[i].items[j].price, &transactions[i].items[j].category);
        }
    }

    // Calculate total sales
    total_sales = 0.0;

    for (i = 0; i < num_transactions; i++) {
        for (j = 0; j < transactions[i].num_items; j++) {
            total_sales += transactions[i].items[j].price;
        }
    }

    printf("Total sales: $%.2f\n", total_sales);

    // Calculate sales by category
    for (i = 0; i < num_transactions; i++) {
        for (j = 0; j < transactions[i].num_items; j++) {
            category_sales[transactions[i].items[j].category-1] += transactions[i].items[j].price;
        }
    }

    printf("Sales by category:\n");

    for (i = 0; i < MAX_CATEGORIES; i++) {
        if (category_sales[i] > 0) {
            printf("%d: $%.2f\n", i+1, category_sales[i]);
        }
    }

    return 0;
}