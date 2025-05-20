#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 118

int main() {
  FILE* file = fopen("periodic_table.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char** table = NULL;
  int tableSize = 0;

  // Load data from the CSV file
  loadPeriodicTable(file, &table, &tableSize);

  // Free memory allocated for the table
  free(table);

  return 0;
}

void loadPeriodicTable(FILE* file, char**** table, int* tableSize) {
  int lineNumber = 0;
  char line[MAX_TABLE_SIZE];

  // Allocate memory for the table
  *table = malloc(MAX_TABLE_SIZE * sizeof(char*));
  *tableSize = 0;

  // Read lines from the file until the end is reached
  while (fgets(line, MAX_TABLE_SIZE, file) != NULL) {
    // Increment the table size if necessary
    if (strlen(line) > 0) {
      (*tableSize)++;
      *table = realloc(*table, MAX_TABLE_SIZE * (*tableSize) * sizeof(char*));
    }

    (*table)[lineNumber] = strdup(line);
    lineNumber++;
  }
}
