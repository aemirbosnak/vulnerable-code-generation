//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: single-threaded
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

// Define the data mining function
void data_mining(transaction *transactions, int num_transactions) {
  // Create a 2D array to store the co-occurrence matrix
  int co_occurrence_matrix[MAX_ITEMS][MAX_ITEMS];

  // Initialize the co-occurrence matrix to 0
  for (int i = 0; i < MAX_ITEMS; i++) {
    for (int j = 0; j < MAX_ITEMS; j++) {
      co_occurrence_matrix[i][j] = 0;
    }
  }

  // Calculate the co-occurrence matrix
  for (int i = 0; i < num_transactions; i++) {
    for (int j = 0; j < transactions[i].num_items; j++) {
      for (int k = j + 1; k < transactions[i].num_items; k++) {
        co_occurrence_matrix[transactions[i].items[j]][transactions[i].items[k]]++;
        co_occurrence_matrix[transactions[i].items[k]][transactions[i].items[j]]++;
      }
    }
  }

  // Print the co-occurrence matrix
  for (int i = 0; i < MAX_ITEMS; i++) {
    for (int j = 0; j < MAX_ITEMS; j++) {
      printf("%d ", co_occurrence_matrix[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create an array of transactions
  transaction transactions[MAX_TRANSACTIONS];

  // Read the transactions from a file
  FILE *fp = fopen("transactions.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  int num_transactions = 0;
  while (fscanf(fp, "%d", &transactions[num_transactions].num_items) != EOF) {
    for (int i = 0; i < transactions[num_transactions].num_items; i++) {
      fscanf(fp, "%d", &transactions[num_transactions].items[i]);
    }
    num_transactions++;
  }
  fclose(fp);

  // Perform data mining
  data_mining(transactions, num_transactions);

  return EXIT_SUCCESS;
}