//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a transaction
typedef struct transaction {
    int id;
    int num_items;
    int *items;
} transaction;

// Data structure to store a set of transactions
typedef struct dataset {
    int num_transactions;
    transaction *transactions;
} dataset;

// Function to read a dataset from a file
dataset *read_dataset(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the number of transactions
    int num_transactions;
    fscanf(fp, "%d", &num_transactions);

    // Allocate memory for the dataset
    dataset *ds = malloc(sizeof(dataset));
    ds->num_transactions = num_transactions;
    ds->transactions = malloc(sizeof(transaction) * num_transactions);

    // Read each transaction
    for (int i = 0; i < num_transactions; i++) {
        // Read the transaction ID
        fscanf(fp, "%d", &ds->transactions[i].id);

        // Read the number of items in the transaction
        fscanf(fp, "%d", &ds->transactions[i].num_items);

        // Allocate memory for the items in the transaction
        ds->transactions[i].items = malloc(sizeof(int) * ds->transactions[i].num_items);

        // Read the items in the transaction
        for (int j = 0; j < ds->transactions[i].num_items; j++) {
            fscanf(fp, "%d", &ds->transactions[i].items[j]);
        }
    }

    // Close the file
    fclose(fp);

    return ds;
}

// Function to free the memory allocated for a dataset
void free_dataset(dataset *ds) {
    for (int i = 0; i < ds->num_transactions; i++) {
        free(ds->transactions[i].items);
    }
    free(ds->transactions);
    free(ds);
}

// Function to print a dataset
void print_dataset(dataset *ds) {
    for (int i = 0; i < ds->num_transactions; i++) {
        printf("Transaction %d: ", ds->transactions[i].id);
        for (int j = 0; j < ds->transactions[i].num_items; j++) {
            printf("%d ", ds->transactions[i].items[j]);
        }
        printf("\n");
    }
}

// Function to find the frequent itemsets in a dataset using the Apriori algorithm
void apriori(dataset *ds, float min_support) {
    // Create a list of all the items in the dataset
    int num_items = 0;
    for (int i = 0; i < ds->num_transactions; i++) {
        for (int j = 0; j < ds->transactions[i].num_items; j++) {
            if (ds->transactions[i].items[j] > num_items) {
                num_items = ds->transactions[i].items[j];
            }
        }
    }

    // Create a list of all the frequent 1-itemsets
    int num_frequent_1_itemsets = 0;
    int *frequent_1_itemsets = malloc(sizeof(int) * num_items);
    for (int i = 0; i < num_items; i++) {
        int count = 0;
        for (int j = 0; j < ds->num_transactions; j++) {
            for (int k = 0; k < ds->transactions[j].num_items; k++) {
                if (ds->transactions[j].items[k] == i) {
                    count++;
                    break;
                }
            }
        }
        if (count >= min_support * ds->num_transactions) {
            frequent_1_itemsets[num_frequent_1_itemsets++] = i;
        }
    }

    // Create a list of all the frequent k-itemsets
    int k = 2;
    while (num_frequent_1_itemsets > 0) {
        // Generate all the candidate k-itemsets
        int num_candidate_k_itemsets = 0;
        int **candidate_k_itemsets = malloc(sizeof(int *) * num_frequent_1_itemsets * num_frequent_1_itemsets);
        for (int i = 0; i < num_frequent_1_itemsets; i++) {
            for (int j = i + 1; j < num_frequent_1_itemsets; j++) {
                candidate_k_itemsets[num_candidate_k_itemsets++] = malloc(sizeof(int) * k);
                for (int l = 0; l < k - 1; l++) {
                    candidate_k_itemsets[num_candidate_k_itemsets - 1][l] = frequent_1_itemsets[i];
                }
                candidate_k_itemsets[num_candidate_k_itemsets - 1][k - 1] = frequent_1_itemsets[j];
            }
        }

        // Count the support for each candidate k-itemset
        int *support_counts = malloc(sizeof(int) * num_candidate_k_itemsets);
        for (int i = 0; i < num_candidate_k_itemsets; i++) {
            support_counts[i] = 0;
            for (int j = 0; j < ds->num_transactions; j++) {
                int count = 0;
                for (int l = 0; l < k; l++) {
                    int found = 0;
                    for (int m = 0; m < ds->transactions[j].num_items; m++) {
                        if (ds->transactions[j].items[m] == candidate_k_itemsets[i][l]) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        break;
                    }
                }
                if (count == k) {
                    support_counts[i]++;
                }
            }
        }

        // Find the frequent k-itemsets
        int num_frequent_k_itemsets = 0;
        int *frequent_k_itemsets = malloc(sizeof(int) * num_candidate_k_itemsets);
        for (int i = 0; i < num_candidate_k_itemsets; i++) {
            if (support_counts[i] >= min_support * ds->num_transactions) {
                frequent_k_itemsets[num_frequent_k_itemsets++] = i;
            }
        }

        // Free the memory allocated for the candidate k-itemsets and support counts
        for (int i = 0; i < num_candidate_k_itemsets; i++) {
            free(candidate_k_itemsets[i]);
        }
        free(candidate_k_itemsets);
        free(support_counts);

        // Increment k
        k++;
    }
}

// Main function
int main() {
    // Read the dataset from a file
    dataset *ds = read_dataset("dataset.txt");

    // Print the dataset
    print_dataset(ds);

    // Find the frequent itemsets in the dataset using the Apriori algorithm
    apriori(ds, 0.5);

    // Free the memory allocated for the dataset
    free_dataset(ds);

    return 0;
}