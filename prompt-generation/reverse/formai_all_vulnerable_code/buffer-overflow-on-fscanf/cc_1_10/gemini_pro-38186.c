//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions and items
#define MAX_TRANSACTIONS 1000
#define MAX_ITEMS 100

// Define the transaction data structure
typedef struct transaction {
  int num_items;
  int items[MAX_ITEMS];
} transaction;

// Define the itemset data structure
typedef struct itemset {
  int num_items;
  int items[MAX_ITEMS];
} itemset;

// Read the transaction data from a file
int read_transactions(transaction transactions[], int max_transactions, char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return -1;
  }

  int num_transactions = 0;
  while (fscanf(fp, "%d", &transactions[num_transactions].num_items) != EOF) {
    for (int i = 0; i < transactions[num_transactions].num_items; i++) {
      fscanf(fp, "%d", &transactions[num_transactions].items[i]);
    }
    num_transactions++;
  }

  fclose(fp);
  return num_transactions;
}

// Generate all frequent itemsets of size k
int generate_frequent_itemsets(itemset frequent_itemsets[], int max_frequent_itemsets, transaction transactions[], int num_transactions, int k) {
  // Initialize the frequent itemsets to be empty
  for (int i = 0; i < max_frequent_itemsets; i++) {
    frequent_itemsets[i].num_items = 0;
  }

  // Generate all possible itemsets of size k
  int num_itemsets = 0;
  for (int i = 0; i < num_transactions; i++) {
    for (int j = 0; j < transactions[i].num_items; j++) {
      for (int l = j + 1; l < transactions[i].num_items; l++) {
        // Check if the itemset is frequent
        int count = 0;
        for (int m = 0; m < num_transactions; m++) {
          int found = 1;
          for (int n = 0; n < k; n++) {
            if (transactions[m].items[n] != frequent_itemsets[num_itemsets].items[n]) {
              found = 0;
              break;
            }
          }
          count += found;
        }

        // Add the frequent itemset to the list
        if (count > num_transactions / 2) {
          frequent_itemsets[num_itemsets].items[k] = transactions[i].items[l];
          frequent_itemsets[num_itemsets].num_items++;
          num_itemsets++;
        }
      }
    }
  }

  return num_itemsets;
}

// Print the frequent itemsets
void print_frequent_itemsets(itemset frequent_itemsets[], int num_frequent_itemsets) {
  for (int i = 0; i < num_frequent_itemsets; i++) {
    printf("{");
    for (int j = 0; j < frequent_itemsets[i].num_items; j++) {
      printf("%d, ", frequent_itemsets[i].items[j]);
    }
    printf("}\n");
  }
}

// Main function
int main() {
  // Read the transaction data from a file
  transaction transactions[MAX_TRANSACTIONS];
  int num_transactions = read_transactions(transactions, MAX_TRANSACTIONS, "transactions.txt");

  // Generate all frequent itemsets of size 2
  itemset frequent_itemsets[MAX_ITEMS];
  int num_frequent_itemsets = generate_frequent_itemsets(frequent_itemsets, MAX_ITEMS, transactions, num_transactions, 2);

  // Print the frequent itemsets
  print_frequent_itemsets(frequent_itemsets, num_frequent_itemsets);

  return 0;
}