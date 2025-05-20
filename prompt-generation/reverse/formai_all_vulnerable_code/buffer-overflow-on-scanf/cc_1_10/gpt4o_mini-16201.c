//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_TRANSACTIONS 100
#define MIN_SUPPORT 2

typedef struct {
    int items[MAX_ITEMS];
    int count;
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int transactionCount = 0;

typedef struct {
    int itemset[MAX_ITEMS];
    int size;
    int supportCount;
} Itemset;

Itemset frequentItemsets[MAX_ITEMS];
int frequentItemsetCount = 0;

// Function to initialize a transaction
void initTransaction(int transactionIndex) {
    transactions[transactionIndex].count = 0;
}

// Function to add an item to a transaction
void addItemToTransaction(int transactionIndex, int item) {
    transactions[transactionIndex].items[transactions[transactionIndex].count++] = item;
}

// Function to read transactions from input
void readTransactions() {
    printf("Enter number of transactions: ");
    scanf("%d", &transactionCount);
    
    for (int i = 0; i < transactionCount; i++) {
        initTransaction(i);
        printf("Enter number of items in transaction %d: ", i + 1);
        int items;
        scanf("%d", &items);
        printf("Enter items (0 to 99): ");
        for (int j = 0; j < items; j++) {
            int item;
            scanf("%d", &item);
            addItemToTransaction(i, item);
        }
    }
}

// Function to generate frequent itemsets of size 1
void generateFrequentItemsets() {
    int itemCount[100] = {0};

    for (int i = 0; i < transactionCount; i++) {
        for (int j = 0; j < transactions[i].count; j++) {
            itemCount[transactions[i].items[j]]++;
        }
    }

    for (int i = 0; i < 100; i++) {
        if (itemCount[i] >= MIN_SUPPORT) {
            frequentItemsets[frequentItemsetCount].itemset[0] = i;
            frequentItemsets[frequentItemsetCount].size = 1;
            frequentItemsets[frequentItemsetCount].supportCount = itemCount[i];
            frequentItemsetCount++;
        }
    }
}

// Function to display frequent itemsets
void displayFrequentItemsets() {
    printf("Frequent Itemsets:\n");
    for (int i = 0; i < frequentItemsetCount; i++) {
        printf("Itemset: { ");
        for (int j = 0; j < frequentItemsets[i].size; j++) {
            printf("%d ", frequentItemsets[i].itemset[j]);
        }
        printf("}, Support Count: %d\n", frequentItemsets[i].supportCount);
    }
}

// Main function
int main() {
    readTransactions();
    generateFrequentItemsets();
    displayFrequentItemsets();
    return 0;
}