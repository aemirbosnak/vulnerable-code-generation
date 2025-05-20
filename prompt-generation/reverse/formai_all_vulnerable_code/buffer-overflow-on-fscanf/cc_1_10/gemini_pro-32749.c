//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the dataset
#define MAX_RECORDS 1000

// Define the maximum number of attributes in the dataset
#define MAX_ATTRIBUTES 100

// Define the data structure for a record
typedef struct {
  char *attributes[MAX_ATTRIBUTES];
  int label;
} Record;

// Define the data structure for the dataset
typedef struct {
  Record records[MAX_RECORDS];
  int num_records;
  int num_attributes;
} Dataset;

// Load the dataset from a file
Dataset *load_dataset(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  // Create the dataset
  Dataset *dataset = malloc(sizeof(Dataset));
  if (dataset == NULL) {
    fprintf(stderr, "Error allocating memory for dataset\n");
    return NULL;
  }

  // Read the number of records and attributes from the file
  fscanf(file, "%d %d", &dataset->num_records, &dataset->num_attributes);

  // Read the records from the file
  for (int i = 0; i < dataset->num_records; i++) {
    // Read the attributes of the record
    for (int j = 0; j < dataset->num_attributes; j++) {
      char *attribute = malloc(100);
      fscanf(file, "%s ", attribute);
      dataset->records[i].attributes[j] = attribute;
    }

    // Read the label of the record
    fscanf(file, "%d", &dataset->records[i].label);
  }

  // Close the file
  fclose(file);

  // Return the dataset
  return dataset;
}

// Free the memory allocated for the dataset
void free_dataset(Dataset *dataset) {
  // Free the memory allocated for the records
  for (int i = 0; i < dataset->num_records; i++) {
    for (int j = 0; j < dataset->num_attributes; j++) {
      free(dataset->records[i].attributes[j]);
    }
  }

  // Free the memory allocated for the dataset
  free(dataset);
}

// Print the dataset
void print_dataset(Dataset *dataset) {
  // Print the number of records and attributes in the dataset
  printf("Number of records: %d\n", dataset->num_records);
  printf("Number of attributes: %d\n", dataset->num_attributes);

  // Print the records in the dataset
  for (int i = 0; i < dataset->num_records; i++) {
    // Print the attributes of the record
    for (int j = 0; j < dataset->num_attributes; j++) {
      printf("%s ", dataset->records[i].attributes[j]);
    }

    // Print the label of the record
    printf("%d\n", dataset->records[i].label);
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a filename
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Load the dataset from the file
  Dataset *dataset = load_dataset(argv[1]);
  if (dataset == NULL) {
    return 1;
  }

  // Print the dataset
  print_dataset(dataset);

  // Free the memory allocated for the dataset
  free_dataset(dataset);

  return 0;
}