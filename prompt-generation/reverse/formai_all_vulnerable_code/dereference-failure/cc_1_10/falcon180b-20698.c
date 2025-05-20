//Falcon-180B DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a transaction
typedef struct Transaction {
    int id;
    char *items;
    float amount;
} Transaction;

// Function to read transactions from a file
void readTransactions(Transaction **transactions, FILE *file) {
    int count = 0;
    rewind(file);
    while (fscanf(file, "%d %s %f\n", &((*transactions)[count].id), (*transactions)[count].items, &((*transactions)[count].amount)) == 3) {
        count++;
        (*transactions) = realloc(*transactions, sizeof(Transaction) * count);
    }
}

// Function to perform association rule mining
void associationRuleMining(Transaction *transactions, int numTransactions) {
    int i, j, k;
    int **itemSets;
    int numItemSets;

    // Create an array to store the item sets
    itemSets = malloc(sizeof(int *) * numTransactions);
    for (i = 0; i < numTransactions; i++) {
        itemSets[i] = malloc(sizeof(int) * 100);
        memset(itemSets[i], 0, sizeof(int) * 100);
    }

    // Create the item sets
    for (i = 0; i < numTransactions; i++) {
        char *token = strtok((transactions + i)->items, " ");
        while (token!= NULL) {
            for (j = 0; j < numTransactions; j++) {
                if (strstr((transactions + j)->items, token)!= NULL) {
                    itemSets[i][k++] = j;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    // Perform association rule mining
    for (i = 0; i < numTransactions; i++) {
        for (j = 0; j < numTransactions; j++) {
            if (i!= j) {
                int intersectionCount = 0;
                for (k = 0; k < 100 && itemSets[i][k]!= -1; k++) {
                    if (itemSets[j][k]!= -1) {
                        intersectionCount++;
                    }
                }
                if (intersectionCount > 0) {
                    printf("%d and %d are associated with support %f\n", i, j, (float)intersectionCount / numTransactions);
                }
            }
        }
    }

    // Free memory
    for (i = 0; i < numTransactions; i++) {
        free(itemSets[i]);
    }
    free(itemSets);
}

// Main function
int main() {
    FILE *file;
    Transaction *transactions;
    int numTransactions;

    // Open the file containing transactions
    file = fopen("transactions.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read transactions from the file
    readTransactions(&transactions, file);
    numTransactions = sizeof(transactions) / sizeof(Transaction);

    // Perform association rule mining
    associationRuleMining(transactions, numTransactions);

    // Free memory
    for (int i = 0; i < numTransactions; i++) {
        free(transactions[i].items);
    }
    free(transactions);

    return 0;
}