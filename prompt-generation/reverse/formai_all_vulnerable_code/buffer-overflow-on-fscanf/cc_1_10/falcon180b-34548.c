//Falcon-180B DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int price;
    int quantity;
    int category;
} item;

typedef struct {
    int frequency;
    double support;
    int items[MAX_ITEMS];
    int num_items;
} association_rule;

void read_items(item* items, int* num_items) {
    FILE* fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open items.txt\n");
        exit(1);
    }

    *num_items = 0;
    while (fscanf(fp, "%s %d %d %d", items[*num_items].name, &items[*num_items].price, &items[*num_items].quantity, &items[*num_items].category)!= EOF) {
        (*num_items)++;
    }

    fclose(fp);
}

void read_transactions(int transactions[MAX_ITEMS][MAX_CATEGORIES], int num_transactions) {
    FILE* fp = fopen("transactions.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open transactions.txt\n");
        exit(1);
    }

    for (int i = 0; i < num_transactions; i++) {
        for (int j = 0; j < MAX_CATEGORIES; j++) {
            fscanf(fp, "%d", &transactions[i][j]);
        }
    }

    fclose(fp);
}

void generate_association_rules(item* items, int num_items, int transactions[MAX_ITEMS][MAX_CATEGORIES], int num_transactions, association_rule* rules, int max_rules, int min_support, int min_confidence) {
    for (int i = 0; i < num_items; i++) {
        for (int j = i + 1; j < num_items; j++) {
            int count = 0;
            for (int k = 0; k < num_transactions; k++) {
                if (transactions[k][i] > 0 && transactions[k][j] > 0) {
                    count++;
                }
            }

            if (count >= min_support) {
                rules[0].frequency = count;
                rules[0].support = (double) count / num_transactions;
                rules[0].num_items = 2;
                rules[0].items[0] = i;
                rules[0].items[1] = j;

                if (rules[0].support >= min_confidence) {
                    printf("Association rule: {%s, %s} -> {%s}\nSupport: %.2f%%\n", items[i].name, items[j].name, items[i].name, rules[0].support * 100);
                }
            }
        }
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items;
    read_items(items, &num_items);

    int transactions[MAX_ITEMS][MAX_CATEGORIES];
    int num_transactions;
    read_transactions(transactions, num_transactions);

    association_rule rules[MAX_ITEMS];
    int max_rules = 10;
    int min_support = 2;
    int min_confidence = 80;

    generate_association_rules(items, num_items, transactions, num_transactions, rules, max_rules, min_support, min_confidence);

    return 0;
}