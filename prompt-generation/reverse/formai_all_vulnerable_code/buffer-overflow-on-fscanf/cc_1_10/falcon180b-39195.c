//Falcon-180B DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 1000

struct item {
    char name[50];
    int category;
    double price;
};

struct transaction {
    int num_items;
    struct item *items;
};

struct category {
    char name[50];
    int num_transactions;
    double total_price;
};

void read_items(struct item *items) {
    FILE *fp = fopen("items.txt", "r");
    int i = 0;
    while (fscanf(fp, "%s %d %lf", items[i].name, &items[i].category, &items[i].price) == 3 && i < MAX_ITEMS) {
        i++;
    }
    fclose(fp);
}

void read_transactions(struct transaction *transactions) {
    FILE *fp = fopen("transactions.txt", "r");
    int i = 0;
    while (fscanf(fp, "%d", &transactions[i].num_items) == 1 && i < MAX_TRANSACTIONS) {
        transactions[i].items = malloc(transactions[i].num_items * sizeof(struct item));
        for (int j = 0; j < transactions[i].num_items; j++) {
            fscanf(fp, "%s %d %lf", transactions[i].items[j].name, &transactions[i].items[j].category, &transactions[i].items[j].price);
        }
        i++;
    }
    fclose(fp);
}

void calculate_categories(struct transaction *transactions, struct category *categories) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        categories[i].num_transactions = 0;
        categories[i].total_price = 0;
    }
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        for (int j = 0; j < transactions[i].num_items; j++) {
            categories[transactions[i].items[j].category].num_transactions++;
            categories[transactions[i].items[j].category].total_price += transactions[i].items[j].price;
        }
    }
}

void print_categories(struct category *categories) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        if (categories[i].num_transactions > 0) {
            printf("%s: %d transactions, total price: $%.2f\n", categories[i].name, categories[i].num_transactions, categories[i].total_price);
        }
    }
}

int main() {
    struct item items[MAX_ITEMS];
    read_items(items);

    struct transaction transactions[MAX_TRANSACTIONS];
    read_transactions(transactions);

    struct category categories[MAX_CATEGORIES];
    calculate_categories(transactions, categories);

    print_categories(categories);

    return 0;
}