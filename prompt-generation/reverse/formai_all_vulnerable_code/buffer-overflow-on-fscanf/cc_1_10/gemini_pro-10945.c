//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions and items
#define MAX_TRANSACTIONS 1000
#define MAX_ITEMS 100

// Define the data structure for a transaction
typedef struct {
  int num_items;
  int items[MAX_ITEMS];
} transaction;

// Define the data structure for a set of transactions
typedef struct {
  int num_transactions;
  transaction transactions[MAX_TRANSACTIONS];
} dataset;

// Read a dataset from a file
dataset* read_dataset(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Read the number of transactions and items
  int num_transactions, num_items;
  fscanf(file, "%d %d\n", &num_transactions, &num_items);

  // Allocate memory for the dataset
  dataset* data = (dataset*)malloc(sizeof(dataset));
  data->num_transactions = num_transactions;

  // Read each transaction
  for (int i = 0; i < num_transactions; i++) {
    // Read the number of items in the transaction
    int num_items;
    fscanf(file, "%d ", &num_items);

    // Read the items in the transaction
    transaction* trans = &data->transactions[i];
    trans->num_items = num_items;
    for (int j = 0; j < num_items; j++) {
      fscanf(file, "%d ", &trans->items[j]);
    }
  }

  // Close the file
  fclose(file);

  return data;
}

// Find the frequent itemsets in a dataset
void find_frequent_itemsets(dataset* data, float min_support) {
  // Create a list of all possible itemsets
  int num_itemsets = 1 << data->transactions[0].num_items;
  int* itemsets = (int*)malloc(sizeof(int) * num_itemsets);
  for (int i = 0; i < num_itemsets; i++) {
    itemsets[i] = 0;
  }

  // Count the frequency of each itemset
  for (int i = 0; i < data->num_transactions; i++) {
    transaction* trans = &data->transactions[i];
    for (int j = 0; j < num_itemsets; j++) {
      // Check if the itemset is a subset of the transaction
      int subset = 1;
      for (int k = 0; k < trans->num_items; k++) {
        if ((itemsets[j] & (1 << trans->items[k])) == 0) {
          subset = 0;
          break;
        }
      }

      // Increment the frequency of the itemset if it is a subset of the transaction
      if (subset) {
        itemsets[j]++;
      }
    }
  }

  // Print the frequent itemsets
  for (int i = 0; i < num_itemsets; i++) {
    if (itemsets[i] >= min_support * data->num_transactions) {
      printf("Frequent itemset: ");
      for (int j = 0; j < data->transactions[0].num_items; j++) {
        if ((itemsets[i] & (1 << j)) != 0) {
          printf("%d ", j);
        }
      }
      printf("\n");
    }
  }

  // Free the memory allocated for the itemsets
  free(itemsets);
}

// Main function
int main() {
  // Read the dataset from a file
  dataset* data = read_dataset("dataset.txt");

  // Find the frequent itemsets in the dataset
  find_frequent_itemsets(data, 0.5);

  // Free the memory allocated for the dataset
  free(data);

  return 0;
}