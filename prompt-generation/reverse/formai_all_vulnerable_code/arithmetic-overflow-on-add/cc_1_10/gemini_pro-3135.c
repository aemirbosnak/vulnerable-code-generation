//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in a CSV row.
#define MAX_COLUMNS 10

// Define the maximum length of a CSV row.
#define MAX_ROW_LENGTH 1024

// Define the delimiter used to separate columns in a CSV row.
#define DELIMITER ','

// Define the newline character used to separate rows in a CSV file.
#define NEWLINE '\n'

// Define the structure of a CSV row.
typedef struct {
  char *columns[MAX_COLUMNS];
  int num_columns;
} CSVRow;

// Define the structure of a CSV file.
typedef struct {
  CSVRow *rows;
  int num_rows;
} CSVFile;

// Read a CSV file into a CSVFile struct.
CSVFile *read_csv_file(const char *filename) {
  // Open the CSV file.
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening CSV file");
    return NULL;
  }

  // Create a new CSVFile struct.
  CSVFile *csv_file = malloc(sizeof(CSVFile));
  if (csv_file == NULL) {
    perror("Error allocating memory for CSV file");
    fclose(fp);
    return NULL;
  }

  // Read the CSV file line by line.
  char line[MAX_ROW_LENGTH];
  while (fgets(line, MAX_ROW_LENGTH, fp) != NULL) {
    // Create a new CSVRow struct.
    CSVRow *row = malloc(sizeof(CSVRow));
    if (row == NULL) {
      perror("Error allocating memory for CSV row");
      fclose(fp);
      free(csv_file);
      return NULL;
    }

    // Split the CSV row into columns.
    char *column = strtok(line, DELIMITER);
    int column_index = 0;
    while (column != NULL) {
      row->columns[column_index] = strdup(column);
      if (row->columns[column_index] == NULL) {
        perror("Error allocating memory for CSV column");
        fclose(fp);
        free(csv_file);
        free(row);
        return NULL;
      }
      column_index++;
      column = strtok(NULL, DELIMITER);
    }

    // Set the number of columns in the CSV row.
    row->num_columns = column_index;

    // Add the CSV row to the CSV file.
    csv_file->rows = realloc(csv_file->rows, (csv_file->num_rows + 1) * sizeof(CSVRow));
    if (csv_file->rows == NULL) {
      perror("Error allocating memory for CSV rows");
      fclose(fp);
      free(csv_file);
      free(row);
      return NULL;
    }
    csv_file->rows[csv_file->num_rows] = *row;
    csv_file->num_rows++;
  }

  // Close the CSV file.
  fclose(fp);

  // Return the CSVFile struct.
  return csv_file;
}

// Free the memory allocated for a CSV file.
void free_csv_file(CSVFile *csv_file) {
  // Free the memory allocated for each CSV row.
  for (int i = 0; i < csv_file->num_rows; i++) {
    for (int j = 0; j < csv_file->rows[i].num_columns; j++) {
      free(csv_file->rows[i].columns[j]);
    }
    free(csv_file->rows[i].columns);
  }

  // Free the memory allocated for the array of CSV rows.
  free(csv_file->rows);

  // Free the memory allocated for the CSV file.
  free(csv_file);
}

// Print a CSV file to the console.
void print_csv_file(CSVFile *csv_file) {
  // Print the CSV file header.
  printf("CSV File:\n");

  // Print each CSV row.
  for (int i = 0; i < csv_file->num_rows; i++) {
    printf("Row %d:\n", i + 1);
    for (int j = 0; j < csv_file->rows[i].num_columns; j++) {
      printf("\tColumn %d: %s\n", j + 1, csv_file->rows[i].columns[j]);
    }
  }
}

// Main function.
int main() {
  // Read a CSV file into a CSVFile struct.
  CSVFile *csv_file = read_csv_file("data.csv");
  if (csv_file == NULL) {
    return EXIT_FAILURE;
  }

  // Print the CSV file to the console.
  print_csv_file(csv_file);

  // Free the memory allocated for the CSV file.
  free_csv_file(csv_file);

  return EXIT_SUCCESS;
}