//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
// csv_reader.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100
#define DELIMITER ','

typedef struct {
  char** data;
  int num_columns;
  int num_rows;
} csv_table_t;

csv_table_t* csv_read(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Allocate memory for the table
  csv_table_t* table = malloc(sizeof(csv_table_t));
  table->num_columns = 0;
  table->num_rows = 0;
  table->data = malloc(MAX_COLUMNS * sizeof(char*));

  // Read the file line by line
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&line, &len, file)) != -1) {
    // Ignore empty lines
    if (read == 1) {
      continue;
    }

    // Split the line into columns
    char* token = strtok(line, DELIMITER);
    int column = 0;
    while (token != NULL) {
      // Store the column data in the table
      table->data[column] = malloc(strlen(token) + 1);
      strcpy(table->data[column], token);
      column++;

      // Get the next token
      token = strtok(NULL, DELIMITER);
    }

    // Add the row to the table
    table->num_columns = column;
    table->num_rows++;
  }

  // Close the file
  fclose(file);

  return table;
}

void csv_print(csv_table_t* table) {
  for (int i = 0; i < table->num_rows; i++) {
    for (int j = 0; j < table->num_columns; j++) {
      printf("%s,", table->data[j][i]);
    }
    printf("\n");
  }
}

int main(int argc, char* argv[]) {
  csv_table_t* table = csv_read("data.csv");
  if (table == NULL) {
    printf("Error reading file\n");
    return 1;
  }

  csv_print(table);

  // Free the table
  for (int i = 0; i < table->num_columns; i++) {
    free(table->data[i]);
  }
  free(table->data);
  free(table);

  return 0;
}