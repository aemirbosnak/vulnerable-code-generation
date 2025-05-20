//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for a transaction
typedef struct {
    int item_id;
    int quantity;
} transaction_item;

// Define the data structure for a transaction list
typedef struct {
    int num_items;
    transaction_item *items;
} transaction_list;

// Read the transaction data from a file
transaction_list *read_transactions(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the number of transactions
    int num_transactions;
    fscanf(file, "%d", &num_transactions);

    // Allocate memory for the transaction list
    transaction_list *transactions = malloc(sizeof(transaction_list));
    transactions->num_items = 0;
    transactions->items = NULL;

    // Read each transaction
    for (int i = 0; i < num_transactions; i++) {
        // Read the number of items in the transaction
        int num_items;
        fscanf(file, "%d", &num_items);

        // Allocate memory for the transaction items
        transactions->items = realloc(transactions->items, (transactions->num_items + num_items) * sizeof(transaction_item));

        // Read each item in the transaction
        for (int j = 0; j < num_items; j++) {
            fscanf(file, "%d %d", &transactions->items[transactions->num_items + j].item_id, &transactions->items[transactions->num_items + j].quantity);
        }

        transactions->num_items += num_items;
    }

    // Close the file
    fclose(file);

    return transactions;
}

// Print the transaction data
void print_transactions(transaction_list *transactions) {
    for (int i = 0; i < transactions->num_items; i++) {
        printf("%d %d\n", transactions->items[i].item_id, transactions->items[i].quantity);
    }
}

// Find the frequent itemsets
int main() {
    // Read the transaction data from a file
    transaction_list *transactions = read_transactions("transactions.txt");

    // Print the transaction data
    print_transactions(transactions);

    return 0;
}