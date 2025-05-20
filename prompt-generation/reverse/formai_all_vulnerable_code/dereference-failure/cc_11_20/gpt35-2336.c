//FormAI DATASET v1.0 Category: Data mining ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for storing a transaction
struct Transaction {
    char *customerName;
    float amount;

    struct Transaction *next;
};

// Data structure for storing frequent itemsets
struct FrequentItemset {
    int *items;
    int length;

    struct FrequentItemset *next;
};

// Function for generating frequent itemsets
void generateFrequentItemsets(struct Transaction **transactions, int numTransactions, int minSupport) {
    // Initialize array for counting occurrence of items
    int itemCounts[26] = {0};

    // Count the number of occurrences of each item in all transactions
    for (int i = 0; i < numTransactions; i++) {
        struct Transaction *current = transactions[i];
        while (current != NULL) {
            char *customerName = current->customerName;
            for (int j = 0; j < strlen(customerName); j++) {
                int itemIndex = customerName[j] - 'a';
                itemCounts[itemIndex]++;
            }
            current = current->next;
        }
    }

    // Initialize array of frequent itemsets
    struct FrequentItemset *frequentItemsets = NULL;

    // Find frequent itemsets of length 1
    for (int i = 0; i < 26; i++) {
        if (itemCounts[i] >= minSupport) {
            int *items = malloc(sizeof(int));
            items[0] = i;
            struct FrequentItemset *frequentItemset = malloc(sizeof(struct FrequentItemset));
            frequentItemset->items = items;
            frequentItemset->length = 1;
            frequentItemset->next = frequentItemsets;
            frequentItemsets = frequentItemset;
        }
    }

    // Find frequent itemsets of length 2 or greater through iteration
    int numIterations = 2;
    while (frequentItemsets != NULL) {
        // Initialize array for counting occurrence of itemsets
        int itemsetCounts[26][26] = {0};

        // Count the number of occurrences of each itemset in all transactions
        for (int i = 0; i < numTransactions; i++) {
            struct Transaction *current = transactions[i];
            while (current != NULL) {
                char *customerName = current->customerName;
                int itemsetLength = frequentItemsets->length;
                int *itemset = frequentItemsets->items;
                for (int j = 0; j < strlen(customerName) - itemsetLength + 1; j++) {
                    int itemsetIndex = 0;
                    for (int k = 0; k < itemsetLength; k++) {
                        int itemIndex = customerName[j+k] - 'a';
                        if (itemIndex == itemset[k]) {
                            itemsetIndex++;
                        }
                    }
                    if (itemsetIndex == itemsetLength) {
                        itemsetCounts[itemset[0]][itemset[1]]++;
                    }
                }
                current = current->next;
            }
        }

        // Generate frequent itemsets of length numIterations
        struct FrequentItemset *previousFrequentItemset = frequentItemsets;
        frequentItemsets = NULL;
        while (previousFrequentItemset != NULL) {
            for (int i = 0; i < 26; i++) {
                if (itemCounts[i] >= minSupport) {
                    for (int j = i+1; j < 26; j++) {
                        if (itemCounts[j] >= minSupport) {
                            if (previousFrequentItemset->length == 1 || (i == previousFrequentItemset->items[0] && j > previousFrequentItemset->items[1])) {
                                int *items = malloc(numIterations * sizeof(int));
                                memcpy(items, previousFrequentItemset->items, (numIterations-1) * sizeof(int));
                                items[numIterations-1] = j;
                                struct FrequentItemset *frequentItemset = malloc(sizeof(struct FrequentItemset));
                                frequentItemset->items = items;
                                frequentItemset->length = numIterations;
                                frequentItemset->next = frequentItemsets;
                                frequentItemsets = frequentItemset;
                            }
                        }
                    }
                }
            }
            previousFrequentItemset = previousFrequentItemset->next;
        }

        // Remove infrequent itemsets
        struct FrequentItemset *current = frequentItemsets;
        struct FrequentItemset *previous = NULL;
        while (current != NULL) {
            int *itemset = current->items;
            int itemsetLength = current->length;
            int itemsetCount = itemsetCounts[itemset[0]][itemset[1]];
            for (int i = 2; i < itemsetLength; i++) {
                itemsetCount = itemsetCounts[itemset[i-1]][itemset[i]];
                if (itemsetCount < minSupport) {
                    break;
                }
            }
            if (itemsetCount < minSupport) {
                if (previous == NULL) {
                    frequentItemsets = current->next;
                } else {
                    previous->next = current->next;
                }
                struct FrequentItemset *temp = current;
                current = current->next;
                free(temp->items);
                free(temp);
            } else {
                previous = current;
                current = current->next;
            }
        }

        numIterations++;
    }

    // Print frequent itemsets
    struct FrequentItemset *current = frequentItemsets;
    while (current != NULL) {
        printf("{");
        for (int i = 0; i < current->length - 1; i++) {
            printf("%c, ", current->items[i] + 'a');
        }
        printf("%c}", current->items[current->length - 1] + 'a');
        printf("\n");
        current = current->next;
    }
}

// Driver program for testing the function
int main() {
    // Build array of transactions
    struct Transaction *transactions[4];
    struct Transaction *transaction1 = malloc(sizeof(struct Transaction));
    transaction1->customerName = "acd";
    transaction1->amount = 19.55;
    transaction1->next = NULL;
    transactions[0] = transaction1;
    struct Transaction *transaction2 = malloc(sizeof(struct Transaction));
    transaction2->customerName = "abe";
    transaction2->amount = 7.21;
    transaction2->next = NULL;
    transactions[1] = transaction2;
    struct Transaction *transaction3 = malloc(sizeof(struct Transaction));
    transaction3->customerName = "bc";
    transaction3->amount = 3.99;
    transaction3->next = NULL;
    transactions[2] = transaction3;
    struct Transaction *transaction4 = malloc(sizeof(struct Transaction));
    transaction4->customerName = "be";
    transaction4->amount = 12.34;
    transaction4->next = NULL;
    transactions[3] = transaction4;

    // Generate frequent itemsets
    generateFrequentItemsets(transactions, 4, 2);

    return 0;
}