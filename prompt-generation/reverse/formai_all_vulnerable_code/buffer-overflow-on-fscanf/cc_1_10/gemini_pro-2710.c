//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple data structure to represent a transaction
typedef struct transaction {
  int id;
  int num_items;
  int *items;
} transaction;

// A simple data structure to represent a set of transactions
typedef struct transaction_set {
  int num_transactions;
  transaction *transactions;
} transaction_set;

// A simple function to print a transaction
void print_transaction(transaction *t) {
  printf("Transaction %d: ", t->id);
  for (int i = 0; i < t->num_items; i++) {
    printf("%d ", t->items[i]);
  }
  printf("\n");
}

// A simple function to print a set of transactions
void print_transaction_set(transaction_set *ts) {
  for (int i = 0; i < ts->num_transactions; i++) {
    print_transaction(&ts->transactions[i]);
  }
}

// A simple function to read a set of transactions from a file
transaction_set *read_transaction_set(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  int num_transactions;
  fscanf(fp, "%d", &num_transactions);

  transaction_set *ts = malloc(sizeof(transaction_set));
  ts->num_transactions = num_transactions;
  ts->transactions = malloc(sizeof(transaction) * num_transactions);

  for (int i = 0; i < num_transactions; i++) {
    int num_items;
    fscanf(fp, "%d", &num_items);

    transaction *t = &ts->transactions[i];
    t->id = i;
    t->num_items = num_items;
    t->items = malloc(sizeof(int) * num_items);

    for (int j = 0; j < num_items; j++) {
      fscanf(fp, "%d", &t->items[j]);
    }
  }

  fclose(fp);

  return ts;
}

// A simple function to free a set of transactions
void free_transaction_set(transaction_set *ts) {
  for (int i = 0; i < ts->num_transactions; i++) {
    free(ts->transactions[i].items);
  }
  free(ts->transactions);
  free(ts);
}

// A simple function to find the frequent itemsets in a set of transactions
void find_frequent_itemsets(transaction_set *ts, int min_support) {
  // Create a map to store the support of each item
  int num_items = 0;
  for (int i = 0; i < ts->num_transactions; i++) {
    for (int j = 0; j < ts->transactions[i].num_items; j++) {
      num_items = fmax(num_items, ts->transactions[i].items[j]);
    }
  }
  int *item_support = calloc(num_items + 1, sizeof(int));

  // Calculate the support of each item
  for (int i = 0; i < ts->num_transactions; i++) {
    for (int j = 0; j < ts->transactions[i].num_items; j++) {
      item_support[ts->transactions[i].items[j]]++;
    }
  }

  // Create a set to store the frequent itemsets
  transaction_set *frequent_itemsets = malloc(sizeof(transaction_set));
  frequent_itemsets->num_transactions = 0;
  frequent_itemsets->transactions = NULL;

  // Add the frequent items to the set
  for (int i = 1; i <= num_items; i++) {
    if (item_support[i] >= min_support) {
      transaction t;
      t.id = i;
      t.num_items = 1;
      t.items = malloc(sizeof(int));
      t.items[0] = i;
      frequent_itemsets->transactions = realloc(frequent_itemsets->transactions,
                                                (frequent_itemsets->num_transactions + 1) * sizeof(transaction));
      frequent_itemsets->transactions[frequent_itemsets->num_transactions] = t;
      frequent_itemsets->num_transactions++;
    }
  }

  // Free the memory allocated for the item support map
  free(item_support);

  // Print the frequent itemsets
  print_transaction_set(frequent_itemsets);

  // Free the memory allocated for the frequent itemsets
  free_transaction_set(frequent_itemsets);
}

int main() {
  // Read the set of transactions from a file
  transaction_set *ts = read_transaction_set("transactions.txt");
  if (ts == NULL) {
    return 1;
  }

  // Find the frequent itemsets in the set of transactions
  find_frequent_itemsets(ts, 2);

  // Free the memory allocated for the set of transactions
  free_transaction_set(ts);

  return 0;
}