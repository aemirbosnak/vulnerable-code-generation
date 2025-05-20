//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions and items in the dataset
#define MAX_TRANSACTIONS 1000
#define MAX_ITEMS 100

// Define the structure of a transaction
typedef struct transaction {
  int id;
  int num_items;
  int items[MAX_ITEMS];
} transaction_t;

// Define the structure of the dataset
typedef struct dataset {
  int num_transactions;
  transaction_t transactions[MAX_TRANSACTIONS];
} dataset_t;

// Read the dataset from a file
dataset_t* read_dataset(char* filename) {
  // Open the file
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Create the dataset
  dataset_t* dataset = malloc(sizeof(dataset_t));
  if (dataset == NULL) {
    printf("Error allocating memory for dataset\n");
    return NULL;
  }

  // Read the number of transactions
  fscanf(file, "%d\n", &dataset->num_transactions);

  // Read the transactions
  for (int i = 0; i < dataset->num_transactions; i++) {
    // Read the transaction ID
    fscanf(file, "%d ", &dataset->transactions[i].id);

    // Read the number of items in the transaction
    fscanf(file, "%d ", &dataset->transactions[i].num_items);

    // Read the items in the transaction
    for (int j = 0; j < dataset->transactions[i].num_items; j++) {
      fscanf(file, "%d ", &dataset->transactions[i].items[j]);
    }
  }

  // Close the file
  fclose(file);

  return dataset;
}

// Print the dataset
void print_dataset(dataset_t* dataset) {
  for (int i = 0; i < dataset->num_transactions; i++) {
    printf("Transaction ID: %d\n", dataset->transactions[i].id);
    printf("Number of items: %d\n", dataset->transactions[i].num_items);
    for (int j = 0; j < dataset->transactions[i].num_items; j++) {
      printf("%d ", dataset->transactions[i].items[j]);
    }
    printf("\n");
  }
}

// Count the occurrences of each item in the dataset
int* count_occurrences(dataset_t* dataset) {
  // Create an array to store the occurrences of each item
  int* occurrences = calloc(MAX_ITEMS, sizeof(int));
  if (occurrences == NULL) {
    printf("Error allocating memory for occurrences\n");
    return NULL;
  }

  // Count the occurrences of each item
  for (int i = 0; i < dataset->num_transactions; i++) {
    for (int j = 0; j < dataset->transactions[i].num_items; j++) {
      occurrences[dataset->transactions[i].items[j]]++;
    }
  }

  return occurrences;
}

// Print the occurrences of each item in the dataset
void print_occurrences(int* occurrences) {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (occurrences[i] > 0) {
      printf("Item %d occurs %d times\n", i, occurrences[i]);
    }
  }
}

// Find the frequent itemsets in the dataset
int** find_frequent_itemsets(dataset_t* dataset, int min_support) {
  // Create an array to store the frequent itemsets
  int** frequent_itemsets = malloc(sizeof(int*));
  if (frequent_itemsets == NULL) {
    printf("Error allocating memory for frequent itemsets\n");
    return NULL;
  }

  // Count the occurrences of each item
  int* occurrences = count_occurrences(dataset);
  if (occurrences == NULL) {
    printf("Error counting occurrences\n");
    return NULL;
  }

  // Find the frequent items
  int num_frequent_items = 0;
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (occurrences[i] >= min_support) {
      num_frequent_items++;
    }
  }

  // Create the frequent itemsets
  int index = 0;
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (occurrences[i] >= min_support) {
      frequent_itemsets[index] = malloc(sizeof(int));
      if (frequent_itemsets[index] == NULL) {
        printf("Error allocating memory for frequent itemset\n");
        return NULL;
      }
      frequent_itemsets[index][0] = i;
      index++;
    }
  }

  // Return the frequent itemsets
  return frequent_itemsets;
}

// Print the frequent itemsets
void print_frequent_itemsets(int** frequent_itemsets) {
  for (int i = 0; frequent_itemsets[i] != NULL; i++) {
    printf("Frequent itemset: ");
    for (int j = 0; frequent_itemsets[i][j] != 0; j++) {
      printf("%d ", frequent_itemsets[i][j]);
    }
    printf("\n");
  }
}

// Free the memory allocated for the dataset
void free_dataset(dataset_t* dataset) {
  free(dataset);
}

// Free the memory allocated for the occurrences
void free_occurrences(int* occurrences) {
  free(occurrences);
}

// Free the memory allocated for the frequent itemsets
void free_frequent_itemsets(int** frequent_itemsets) {
  for (int i = 0; frequent_itemsets[i] != NULL; i++) {
    free(frequent_itemsets[i]);
  }
  free(frequent_itemsets);
}

int main() {
  // Read the dataset from a file
  dataset_t* dataset = read_dataset("dataset.txt");
  if (dataset == NULL) {
    printf("Error reading dataset\n");
    return EXIT_FAILURE;
  }

  // Print the dataset
  print_dataset(dataset);

  // Count the occurrences of each item in the dataset
  int* occurrences = count_occurrences(dataset);
  if (occurrences == NULL) {
    printf("Error counting occurrences\n");
    return EXIT_FAILURE;
  }

  // Print the occurrences of each item in the dataset
  print_occurrences(occurrences);

  // Find the frequent itemsets in the dataset
  int** frequent_itemsets = find_frequent_itemsets(dataset, 2);
  if (frequent_itemsets == NULL) {
    printf("Error finding frequent itemsets\n");
    return EXIT_FAILURE;
  }

  // Print the frequent itemsets
  print_frequent_itemsets(frequent_itemsets);

  // Free the memory allocated for the dataset
  free_dataset(dataset);

  // Free the memory allocated for the occurrences
  free_occurrences(occurrences);

  // Free the memory allocated for the frequent itemsets
  free_frequent_itemsets(frequent_itemsets);

  return EXIT_SUCCESS;
}