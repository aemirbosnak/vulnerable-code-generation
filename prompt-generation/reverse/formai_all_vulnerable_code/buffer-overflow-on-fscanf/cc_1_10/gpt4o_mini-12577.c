//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_TRANSACTIONS 100
#define SUPPORT_THRESHOLD 2

typedef struct {
    int items[MAX_ITEMS];
    int count;
} Transaction;

typedef struct {
    int items[MAX_ITEMS];
    int support;
    int length;
} Itemset;

Transaction transactions[MAX_TRANSACTIONS];
int transaction_count = 0;

void read_transactions(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%d", &transactions[transaction_count].count) != EOF) {
        for (int i = 0; i < transactions[transaction_count].count; i++) {
            fscanf(file, "%d", &transactions[transaction_count].items[i]);
        }
        transaction_count++;
    }
    fclose(file);
}

int is_subset(int *itemset, int itemset_length, Transaction transaction) {
    for (int i = 0; i < itemset_length; i++) {
        int found = 0;
        for (int j = 0; j < transaction.count; j++) {
            if (itemset[i] == transaction.items[j]) {
                found = 1;
                break;
            }
        }
        if (!found) return 0;
    }
    return 1;
}

void find_frequent_itemsets(int length) {
    Itemset itemsets[MAX_ITEMS];
    int unique_items[MAX_ITEMS] = {0};
    int unique_count = 0;

    // Generate unique items
    for (int i = 0; i < transaction_count; i++) {
        for (int j = 0; j < transactions[i].count; j++) {
            int item = transactions[i].items[j];
            if (!unique_items[item]) {
                unique_items[item] = 1;
                unique_count++;
            }
        }
    }

    // Generate itemsets of the given length
    for (int i = 0; i < unique_count; i++) {
        for (int j = i + 1; j < unique_count; j++) {
            int itemset[MAX_ITEMS] = {0};
            itemset[0] = i;
            itemset[1] = j;
            int support_count = 0;

            for (int k = 0; k < transaction_count; k++) {
                if (is_subset(itemset, 2, transactions[k])) {
                    support_count++;
                }
            }

            if (support_count >= SUPPORT_THRESHOLD) {
                itemsets[itemsets[0].length].support = support_count;
                itemsets[itemsets[0].length].length = 2;
                itemsets[itemsets[0].length].items[0] = i;
                itemsets[itemsets[0].length].items[1] = j;
                itemsets[0].length++;
            }
        }
    }

    // Print frequent itemsets
    printf("Frequent Itemsets of length %d:\n", length);
    for (int i = 0; i < itemsets[0].length; i++) {
        printf("{");
        for (int j = 0; j < itemsets[i].length; j++) {
            printf("%d ", itemsets[i].items[j]);
        }
        printf("} Support: %d\n", itemsets[i].support);
    }
}

int main() {
    const char *filename = "transactions.txt";
    read_transactions(filename);
    find_frequent_itemsets(2);
    return 0;
}