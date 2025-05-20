//Falcon-180B DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 100
#define MAX_TRANSACTIONS 100000

typedef struct {
    char name[50];
    int count;
} Item;

typedef struct {
    char name[50];
    int count;
} Category;

typedef struct {
    int numItems;
    Item *items;
} Transaction;

int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateRandomData(Transaction *transactions, int numTransactions) {
    srand(time(NULL));
    for (int i = 0; i < numTransactions; i++) {
        int numItems = getRandomInt(1, MAX_ITEMS);
        transactions[i].numItems = numItems;
        transactions[i].items = malloc(numItems * sizeof(Item));
        for (int j = 0; j < numItems; j++) {
            transactions[i].items[j].count = getRandomInt(1, MAX_CATEGORIES);
        }
    }
}

void printTransaction(Transaction transaction) {
    printf("Transaction:\n");
    for (int i = 0; i < transaction.numItems; i++) {
        printf("Item %d: %s\n", i+1, transaction.items[i].name);
    }
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = getRandomInt(1, MAX_TRANSACTIONS);

    generateRandomData(transactions, numTransactions);

    for (int i = 0; i < numTransactions; i++) {
        printTransaction(transactions[i]);
    }

    return 0;
}