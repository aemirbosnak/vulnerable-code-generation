//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a single transaction
typedef struct {
    int transaction_id;
    char items[100][50]; // array of items in a transaction
    int item_count;
} Transaction;

// Function prototypes
void load_transactions(const char *filename, Transaction **transactions, int *count);
void print_transactions(Transaction *transactions, int count);
void find_frequent_items(Transaction *transactions, int count, int min_support);

int main() {
    Transaction *transactions = NULL;
    int transaction_count = 0;
    const char *filename = "transactions.txt"; // Should contain transaction data
    
    load_transactions(filename, &transactions, &transaction_count);
    printf("Loaded %d transactions:\n", transaction_count);
    print_transactions(transactions, transaction_count);

    int min_support = 2; // Minimum support count for frequent itemset
    find_frequent_items(transactions, transaction_count, min_support);

    // Clean up memory
    free(transactions);
    return 0;
}

// Load transactions from a file
void load_transactions(const char *filename, Transaction **transactions, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Allocate initial space for transactions
    int capacity = 10;
    *transactions = malloc(capacity * sizeof(Transaction));
    if (*transactions == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%d", &(*transactions)[*count].transaction_id) != EOF) {
        (*transactions)[*count].item_count = 0;
        char item[50];
        
        while (fscanf(file, "%s", item) == 1) {
            strcpy((*transactions)[*count].items[(*transactions)[*count].item_count++], item);
        }
        
        (*count)++;
        
        // Resize if capacity is reached
        if (*count >= capacity) {
            capacity *= 2;
            *transactions = realloc(*transactions, capacity * sizeof(Transaction));
            if (*transactions == NULL) {
                perror("Failed to reallocate memory");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}

// Print transactions to the console
void print_transactions(Transaction *transactions, int count) {
    for (int i = 0; i < count; i++) {
        printf("Transaction ID: %d\nItems: ", transactions[i].transaction_id);
        for (int j = 0; j < transactions[i].item_count; j++) {
            printf("%s ", transactions[i].items[j]);
        }
        printf("\n");
    }
}

// Find and print frequent items
void find_frequent_items(Transaction *transactions, int count, int min_support) {
    int item_frequency[100][2] = {0}; // Array to hold item and its frequency
    int total_items = 0;

    // Count frequencies
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < transactions[i].item_count; j++) {
            int found = 0;
            for (int k = 0; k < total_items; k++) {
                if (strcmp(item_frequency[k][0], transactions[i].items[j]) == 0) {
                    item_frequency[k][1]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(item_frequency[total_items][0], transactions[i].items[j]);
                item_frequency[total_items][1] = 1;
                total_items++;
            }
        }
    }

    // Print frequent items
    printf("\nFrequent items (support >= %d):\n", min_support);
    for (int i = 0; i < total_items; i++) {
        if (item_frequency[i][1] >= min_support) {
            printf("%s: %d\n", item_frequency[i][0], item_frequency[i][1]);
        }
    }
}