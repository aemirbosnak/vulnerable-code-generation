//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a transaction
typedef struct transaction {
    int num_items;
    int *items;
} transaction_t;

// Data structure to store a set of transactions
typedef struct transaction_set {
    int num_transactions;
    transaction_t *transactions;
} transaction_set_t;

// Function to read a transaction set from a file
transaction_set_t *read_transaction_set(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int num_transactions;
    fscanf(fp, "%d", &num_transactions);

    transaction_set_t *transaction_set = malloc(sizeof(transaction_set_t));
    transaction_set->num_transactions = num_transactions;
    transaction_set->transactions = malloc(num_transactions * sizeof(transaction_t));

    for (int i = 0; i < num_transactions; i++) {
        int num_items;
        fscanf(fp, "%d", &num_items);

        transaction_set->transactions[i].num_items = num_items;
        transaction_set->transactions[i].items = malloc(num_items * sizeof(int));

        for (int j = 0; j < num_items; j++) {
            fscanf(fp, "%d", &transaction_set->transactions[i].items[j]);
        }
    }

    fclose(fp);

    return transaction_set;
}

// Function to print a transaction set
void print_transaction_set(transaction_set_t *transaction_set) {
    for (int i = 0; i < transaction_set->num_transactions; i++) {
        printf("Transaction %d: ", i + 1);
        for (int j = 0; j < transaction_set->transactions[i].num_items; j++) {
            printf("%d ", transaction_set->transactions[i].items[j]);
        }
        printf("\n");
    }
}

// Function to find the frequent itemsets in a transaction set
void find_frequent_itemsets(transaction_set_t *transaction_set, int min_support) {
    // Create a map to store the support count of each item
    int num_items = 0;
    for (int i = 0; i < transaction_set->num_transactions; i++) {
        for (int j = 0; j < transaction_set->transactions[i].num_items; j++) {
            num_items = fmax(num_items, transaction_set->transactions[i].items[j]);
        }
    }
    int *item_support_counts = calloc(num_items, sizeof(int));

    for (int i = 0; i < transaction_set->num_transactions; i++) {
        for (int j = 0; j < transaction_set->transactions[i].num_items; j++) {
            item_support_counts[transaction_set->transactions[i].items[j]]++;
        }
    }

    // Create a list to store the frequent itemsets
    int num_frequent_itemsets = 0;
    int **frequent_itemsets = malloc(sizeof(int *));

    // Iterate over all possible itemsets
    for (int i = 1; i <= num_items; i++) {
        for (int j = 0; j < num_items; j++) {
            if (item_support_counts[j] >= min_support) {
                // Create a new itemset
                int *itemset = malloc((i + 1) * sizeof(int));
                itemset[0] = i;
                for (int k = 1; k < i; k++) {
                    itemset[k] = j;
                }

                // Add the itemset to the list of frequent itemsets
                frequent_itemsets[num_frequent_itemsets++] = itemset;
            }
        }
    }

    // Print the frequent itemsets
    for (int i = 0; i < num_frequent_itemsets; i++) {
        printf("Frequent itemset %d: ", i + 1);
        for (int j = 0; j < frequent_itemsets[i][0]; j++) {
            printf("%d ", frequent_itemsets[i][j + 1]);
        }
        printf("\n");
    }
}

int main() {
    // Read the transaction set from a file
    transaction_set_t *transaction_set = read_transaction_set("transactions.txt");
    if (transaction_set == NULL) {
        return 1;
    }

    // Print the transaction set
    print_transaction_set(transaction_set);

    // Find the frequent itemsets in the transaction set
    find_frequent_itemsets(transaction_set, 2);

    // Free the memory allocated for the transaction set
    for (int i = 0; i < transaction_set->num_transactions; i++) {
        free(transaction_set->transactions[i].items);
    }
    free(transaction_set->transactions);
    free(transaction_set);

    return 0;
}