//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions and items
#define MAX_TRANSACTIONS 1000
#define MAX_ITEMS 100

// Define the data structure for a transaction
typedef struct transaction {
  int id;
  int num_items;
  int items[MAX_ITEMS];
} transaction;

// Define the data structure for the database
typedef struct database {
  int num_transactions;
  transaction transactions[MAX_TRANSACTIONS];
} database;

// Read the database from a file
database* read_database(char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Allocate memory for the database
  database* db = malloc(sizeof(database));
  if (db == NULL) {
    perror("Error allocating memory for database");
    fclose(fp);
    return NULL;
  }

  // Read the number of transactions
  fscanf(fp, "%d", &db->num_transactions);

  // Read the transactions
  for (int i = 0; i < db->num_transactions; i++) {
    // Read the transaction ID
    fscanf(fp, "%d", &db->transactions[i].id);

    // Read the number of items in the transaction
    fscanf(fp, "%d", &db->transactions[i].num_items);

    // Read the items in the transaction
    for (int j = 0; j < db->transactions[i].num_items; j++) {
      fscanf(fp, "%d", &db->transactions[i].items[j]);
    }
  }

  // Close the file
  fclose(fp);

  // Return the database
  return db;
}

// Print the database
void print_database(database* db) {
  for (int i = 0; i < db->num_transactions; i++) {
    printf("Transaction %d: ", db->transactions[i].id);
    for (int j = 0; j < db->transactions[i].num_items; j++) {
      printf("%d ", db->transactions[i].items[j]);
    }
    printf("\n");
  }
}

// Find the frequent itemsets in the database
void find_frequent_itemsets(database* db, float min_support) {
  // Create a list of all the items in the database
  int num_items = 0;
  int items[MAX_ITEMS];
  for (int i = 0; i < db->num_transactions; i++) {
    for (int j = 0; j < db->transactions[i].num_items; j++) {
      int item = db->transactions[i].items[j];
      if (!contains(items, num_items, item)) {
        items[num_items++] = item;
      }
    }
  }

  // Create a list of all the frequent itemsets
  int num_frequent_itemsets = 0;
  int frequent_itemsets[MAX_ITEMS][MAX_ITEMS];
  for (int i = 0; i < num_items; i++) {
    // Create a candidate itemset
    int candidate_itemset[MAX_ITEMS];
    candidate_itemset[0] = items[i];
    int num_candidate_items = 1;

    // Find the support for the candidate itemset
    int support = 0;
    for (int j = 0; j < db->num_transactions; j++) {
      if (contains(db->transactions[j].items, db->transactions[j].num_items, candidate_itemset[0])) {
        support++;
      }
    }

    // If the support for the candidate itemset is greater than or equal to the minimum support, then add it to the list of frequent itemsets
    if (support >= min_support * db->num_transactions) {
      frequent_itemsets[num_frequent_itemsets][0] = items[i];
      num_frequent_itemsets++;

      // Generate all of the subsets of the candidate itemset
      for (int k = 1; k < num_candidate_items; k++) {
        for (int l = 0; l < k; l++) {
          int subset[MAX_ITEMS];
          for (int m = 0; m < l; m++) {
            subset[m] = candidate_itemset[m];
          }
          for (int m = l + 1; m < k; m++) {
            subset[m - 1] = candidate_itemset[m];
          }

          // Find the support for the subset
          int support = 0;
          for (int j = 0; j < db->num_transactions; j++) {
            if (contains(db->transactions[j].items, db->transactions[j].num_items, subset)) {
              support++;
            }
          }

          // If the support for the subset is greater than or equal to the minimum support, then add it to the list of frequent itemsets
          if (support >= min_support * db->num_transactions) {
            for (int n = 0; n < k - 1; n++) {
              frequent_itemsets[num_frequent_itemsets][n] = subset[n];
            }
            frequent_itemsets[num_frequent_itemsets][k - 1] = candidate_itemset[k - 1];
            num_frequent_itemsets++;
          }
        }
      }
    }
  }

  // Print the frequent itemsets
  for (int i = 0; i < num_frequent_itemsets; i++) {
    printf("Frequent itemset %d: ", i);
    for (int j = 0; j < frequent_itemsets[i][0]; j++) {
      printf("%d ", frequent_itemsets[i][j]);
    }
    printf("\n");
  }
}

// Check if an item is contained in an array
int contains(int* array, int num_elements, int item) {
  for (int i = 0; i < num_elements; i++) {
    if (array[i] == item) {
      return 1;
    }
  }
  return 0;
}

// Main function
int main() {
  // Read the database from a file
  database* db = read_database("database.txt");
  if (db == NULL) {
    return 1;
  }

  // Print the database
  print_database(db);

  // Find the frequent itemsets in the database
  find_frequent_itemsets(db, 0.5);

  // Free the memory allocated for the database
  free(db);

  return 0;
}