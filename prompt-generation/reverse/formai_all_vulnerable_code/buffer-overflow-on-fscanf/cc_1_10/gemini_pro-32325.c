//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of attributes and records in the dataset
#define MAX_ATTRIBUTES 100
#define MAX_RECORDS 1000

// Define the attribute types
typedef enum {
  NUMERIC,
  CATEGORICAL
} attribute_type;

// Define the attribute structure
typedef struct {
  char *name;
  attribute_type type;
  union {
    double numeric_value;
    char *categorical_value;
  };
} attribute;

// Define the record structure
typedef struct {
  attribute *attributes;
  int num_attributes;
} record;

// Define the dataset structure
typedef struct {
  record *records;
  int num_records;
  int num_attributes;
} dataset;

// Read a dataset from a file
dataset *read_dataset(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the number of attributes and records
  int num_attributes, num_records;
  fscanf(fp, "%d %d", &num_attributes, &num_records);

  // Allocate memory for the dataset
  dataset *ds = malloc(sizeof(dataset));
  ds->num_attributes = num_attributes;
  ds->num_records = num_records;
  ds->records = malloc(sizeof(record) * num_records);

  // Read the attributes
  for (int i = 0; i < num_attributes; i++) {
    // Allocate memory for the attribute
    attribute *attr = malloc(sizeof(attribute));

    // Read the attribute name
    char name[100];
    fscanf(fp, "%s", name);
    attr->name = strdup(name);

    // Read the attribute type
    char type[100];
    fscanf(fp, "%s", type);
    if (strcmp(type, "NUMERIC") == 0) {
      attr->type = NUMERIC;
    } else if (strcmp(type, "CATEGORICAL") == 0) {
      attr->type = CATEGORICAL;
    } else {
      perror("Error reading attribute type");
      return NULL;
    }

    // Store the attribute in the dataset
    ds->records[i].attributes = attr;
    ds->records[i].num_attributes = num_attributes;
  }

  // Read the records
  for (int i = 0; i < num_records; i++) {
    // Read the record
    for (int j = 0; j < num_attributes; j++) {
      if (ds->records[i].attributes[j].type == NUMERIC) {
        fscanf(fp, "%lf", &ds->records[i].attributes[j].numeric_value);
      } else if (ds->records[i].attributes[j].type == CATEGORICAL) {
        char value[100];
        fscanf(fp, "%s", value);
        ds->records[i].attributes[j].categorical_value = strdup(value);
      }
    }
  }

  // Close the file
  fclose(fp);

  // Return the dataset
  return ds;
}

// Print a dataset
void print_dataset(dataset *ds) {
  // Print the number of attributes and records
  printf("Number of attributes: %d\n", ds->num_attributes);
  printf("Number of records: %d\n", ds->num_records);

  // Print the attributes
  for (int i = 0; i < ds->num_attributes; i++) {
    printf("Attribute %d:\n", i);
    printf("  Name: %s\n", ds->records[i].attributes[i].name);
    printf("  Type: %s\n", ds->records[i].attributes[i].type == NUMERIC ? "NUMERIC" : "CATEGORICAL");
    if (ds->records[i].attributes[i].type == NUMERIC) {
      printf("  Value: %lf\n", ds->records[i].attributes[i].numeric_value);
    } else if (ds->records[i].attributes[i].type == CATEGORICAL) {
      printf("  Value: %s\n", ds->records[i].attributes[i].categorical_value);
    }
  }

  // Print the records
  for (int i = 0; i < ds->num_records; i++) {
    printf("Record %d:\n", i);
    for (int j = 0; j < ds->num_attributes; j++) {
      if (ds->records[i].attributes[j].type == NUMERIC) {
        printf("  %s: %lf\n", ds->records[i].attributes[j].name, ds->records[i].attributes[j].numeric_value);
      } else if (ds->records[i].attributes[j].type == CATEGORICAL) {
        printf("  %s: %s\n", ds->records[i].attributes[j].name, ds->records[i].attributes[j].categorical_value);
      }
    }
  }
}

// Free the memory allocated for a dataset
void free_dataset(dataset *ds) {
  // Free the attributes
  for (int i = 0; i < ds->num_attributes; i++) {
    free(ds->records[i].attributes[i].name);
    if (ds->records[i].attributes[i].type == CATEGORICAL) {
      free(ds->records[i].attributes[i].categorical_value);
    }
  }

  // Free the records
  free(ds->records);

  // Free the dataset
  free(ds);
}

// Main function
int main() {
  // Read the dataset from a file
  dataset *ds = read_dataset("dataset.csv");
  if (ds == NULL) {
    return 1;
  }

  // Print the dataset
  print_dataset(ds);

  // Free the memory allocated for the dataset
  free_dataset(ds);

  return 0;
}