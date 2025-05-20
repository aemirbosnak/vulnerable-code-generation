//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for a transaction
typedef struct {
  int tid;
  int num_items;
  int *items;
} transaction;

// Define the data structure for a database
typedef struct {
  int num_transactions;
  transaction *transactions;
} database;

// Read a database from a file
database *read_database(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  // Read the number of transactions
  int num_transactions;
  fscanf(fp, "%d", &num_transactions);

  // Allocate memory for the database
  database *db = malloc(sizeof(database));
  db->num_transactions = num_transactions;
  db->transactions = malloc(num_transactions * sizeof(transaction));

  // Read each transaction
  for (int i = 0; i < num_transactions; i++) {
    // Read the transaction ID
    fscanf(fp, "%d", &db->transactions[i].tid);

    // Read the number of items
    fscanf(fp, "%d", &db->transactions[i].num_items);

    // Allocate memory for the items
    db->transactions[i].items = malloc(db->transactions[i].num_items * sizeof(int));

    // Read the items
    for (int j = 0; j < db->transactions[i].num_items; j++) {
      fscanf(fp, "%d", &db->transactions[i].items[j]);
    }
  }

  // Close the file
  fclose(fp);

  return db;
}

// Print a database
void print_database(database *db) {
  for (int i = 0; i < db->num_transactions; i++) {
    printf("Transaction %d: ", db->transactions[i].tid);
    for (int j = 0; j < db->transactions[i].num_items; j++) {
      printf("%d ", db->transactions[i].items[j]);
    }
    printf("\n");
  }
}

// Free the memory allocated for a database
void free_database(database *db) {
  for (int i = 0; i < db->num_transactions; i++) {
    free(db->transactions[i].items);
  }
  free(db->transactions);
  free(db);
}

// Main function
int main(int argc, char **argv) {
  // Read the database from a file
  database *db = read_database(argv[1]);

  // Print the database
  print_database(db);

  // Free the memory allocated for the database
  free_database(db);

  return 0;
}