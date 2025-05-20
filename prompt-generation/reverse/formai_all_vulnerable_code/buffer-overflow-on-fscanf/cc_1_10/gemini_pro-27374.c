//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions and items
#define MAX_TRANSACTIONS 1000
#define MAX_ITEMS 100

// Define the transaction structure
typedef struct {
    int num_items;
    int items[MAX_ITEMS];
} transaction;

// Define the database structure
typedef struct {
    int num_transactions;
    transaction transactions[MAX_TRANSACTIONS];
} database;

// Read the database from a file
database *read_database(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the database
    database *db = malloc(sizeof(database));
    if (db == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read the number of transactions
    fscanf(file, "%d", &db->num_transactions);

    // Read the transactions
    for (int i = 0; i < db->num_transactions; i++) {
        // Read the number of items in the transaction
        fscanf(file, "%d", &db->transactions[i].num_items);

        // Read the items in the transaction
        for (int j = 0; j < db->transactions[i].num_items; j++) {
            fscanf(file, "%d", &db->transactions[i].items[j]);
        }
    }

    // Close the file
    fclose(file);

    // Return the database
    return db;
}

// Print the database
void print_database(database *db) {
    // Print the number of transactions
    printf("Number of transactions: %d\n", db->num_transactions);

    // Print the transactions
    for (int i = 0; i < db->num_transactions; i++) {
        // Print the number of items in the transaction
        printf("Transaction %d: %d items\n", i, db->transactions[i].num_items);

        // Print the items in the transaction
        for (int j = 0; j < db->transactions[i].num_items; j++) {
            printf("%d ", db->transactions[i].items[j]);
        }

        printf("\n");
    }
}

// Find the frequent itemsets in the database
int *find_frequent_itemsets(database *db, float min_support) {
    // Allocate memory for the frequent itemsets
    int *frequent_itemsets = malloc(sizeof(int) * MAX_ITEMS);
    if (frequent_itemsets == NULL) {
        perror("Error allocating memory");
        return NULL;
    }

    // Initialize the frequent itemsets to 0
    for (int i = 0; i < MAX_ITEMS; i++) {
        frequent_itemsets[i] = 0;
    }

    // For each transaction in the database
    for (int i = 0; i < db->num_transactions; i++) {
        // For each item in the transaction
        for (int j = 0; j < db->transactions[i].num_items; j++) {
            // Increment the count of the item
            frequent_itemsets[db->transactions[i].items[j]]++;
        }
    }

    // For each item in the frequent itemsets
    for (int i = 0; i < MAX_ITEMS; i++) {
        // If the count of the item is less than the minimum support
        if (frequent_itemsets[i] < db->num_transactions * min_support) {
            // Remove the item from the frequent itemsets
            frequent_itemsets[i] = 0;
        }
    }

    // Return the frequent itemsets
    return frequent_itemsets;
}

// Print the frequent itemsets
void print_frequent_itemsets(int *frequent_itemsets) {
    // For each item in the frequent itemsets
    for (int i = 0; i < MAX_ITEMS; i++) {
        // If the item is frequent
        if (frequent_itemsets[i] > 0) {
            // Print the item
            printf("%d ", i);
        }
    }

    printf("\n");
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s <filename> <min_support>\n", argv[0]);
        return 1;
    }

    // Read the database from a file
    database *db = read_database(argv[1]);
    if (db == NULL) {
        return 1;
    }

    // Print the database
    print_database(db);

    // Find the frequent itemsets in the database
    int *frequent_itemsets = find_frequent_itemsets(db, atof(argv[2]));
    if (frequent_itemsets == NULL) {
        return 1;
    }

    // Print the frequent itemsets
    print_frequent_itemsets(frequent_itemsets);

    // Free the memory allocated for the database and the frequent itemsets
    free(db);
    free(frequent_itemsets);

    return 0;
}