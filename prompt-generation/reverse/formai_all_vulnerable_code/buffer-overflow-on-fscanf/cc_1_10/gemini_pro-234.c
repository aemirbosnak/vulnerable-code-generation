//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of customers and transactions
#define MAX_CUSTOMERS 1000
#define MAX_TRANSACTIONS 10000

// Define the structure of a customer
typedef struct customer {
  int id;
  char name[50];
  int num_transactions;
  int transactions[MAX_TRANSACTIONS];
} customer;

// Define the structure of a transaction
typedef struct transaction {
  int id;
  int customer_id;
  int item_id;
  int quantity;
} transaction;

// Load the customer data from a file
void load_customers(customer* customers, int* num_customers, char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  int id, num_transactions;
  char name[50];

  while (fscanf(fp, "%d %s %d", &id, name, &num_transactions) != EOF) {
    customers[*num_customers].id = id;
    strcpy(customers[*num_customers].name, name);
    customers[*num_customers].num_transactions = num_transactions;
    *num_customers += 1;
  }

  fclose(fp);
}

// Load the transaction data from a file
void load_transactions(transaction* transactions, int* num_transactions, char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  int id, customer_id, item_id, quantity;

  while (fscanf(fp, "%d %d %d %d", &id, &customer_id, &item_id, &quantity) != EOF) {
    transactions[*num_transactions].id = id;
    transactions[*num_transactions].customer_id = customer_id;
    transactions[*num_transactions].item_id = item_id;
    transactions[*num_transactions].quantity = quantity;
    *num_transactions += 1;
  }

  fclose(fp);
}

// Find the most frequent itemsets
void find_frequent_itemsets(customer* customers, int num_customers, transaction* transactions, int num_transactions, int min_support) {
  // Create a hash table to store the itemsets and their support counts
  int itemset_size = 2;
  int max_itemset_size = 10;

  // Iterate over all possible itemsets of size itemset_size
  while (itemset_size <= max_itemset_size) {

    // Create a hash table to store the itemsets and their support counts
    int hash_table_size = 1000;
    int* hash_table = (int*)calloc(hash_table_size, sizeof(int));

    // Iterate over all transactions
    for (int i = 0; i < num_transactions; i++) {

      // Get the customer ID for the current transaction
      int customer_id = transactions[i].customer_id;

      // Get the number of transactions for the current customer
      int num_transactions = customers[customer_id].num_transactions;

      // Iterate over all itemsets of size itemset_size for the current customer
      for (int j = 0; j < num_transactions - itemset_size + 1; j++) {

        // Get the current itemset
        int itemset[itemset_size];
        for (int k = 0; k < itemset_size; k++) {
          itemset[k] = customers[customer_id].transactions[j + k];
        }

        // Hash the itemset
        int hash_value = 0;
        for (int k = 0; k < itemset_size; k++) {
          hash_value += itemset[k] * (k + 1);
        }
        hash_value = hash_value % hash_table_size;

        // Increment the support count for the itemset
        hash_table[hash_value] += 1;
      }
    }

    // Print the frequent itemsets
    for (int i = 0; i < hash_table_size; i++) {
      if (hash_table[i] >= min_support) {
        int itemset[itemset_size];
        int hash_value = i;
        for (int j = itemset_size - 1; j >= 0; j--) {
          itemset[j] = hash_value % (j + 1);
          hash_value = hash_value / (j + 1);
        }
        printf("Frequent itemset: ");
        for (int j = 0; j < itemset_size; j++) {
          printf("%d ", itemset[j]);
        }
        printf("\n");
      }
    }

    // Free the hash table
    free(hash_table);

    // Increment the itemset size
    itemset_size += 1;
  }
}

// Main function
int main(int argc, char** argv) {

  // Check the number of arguments
  if (argc != 4) {
    printf("Usage: %s <customer_data_file> <transaction_data_file> <min_support>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the customer data file name
  char* customer_data_file = argv[1];

  // Get the transaction data file name
  char* transaction_data_file = argv[2];

  // Get the minimum support
  int min_support = atoi(argv[3]);

  // Load the customer data
  customer customers[MAX_CUSTOMERS];
  int num_customers = 0;
  load_customers(customers, &num_customers, customer_data_file);

  // Load the transaction data
  transaction transactions[MAX_TRANSACTIONS];
  int num_transactions = 0;
  load_transactions(transactions, &num_transactions, transaction_data_file);

  // Find the frequent itemsets
  find_frequent_itemsets(customers, num_customers, transactions, num_transactions, min_support);

  return EXIT_SUCCESS;
}