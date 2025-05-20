//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
// CSV Reader

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COLUMNS 100
#define MAX_ROW_LENGTH 1000

typedef struct {
  char **data;
  int num_columns;
  int num_rows;
} CSV;

CSV* create_csv(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  CSV *csv = malloc(sizeof(CSV));
  csv->num_columns = 0;
  csv->num_rows = 0;
  csv->data = NULL;

  char line[MAX_ROW_LENGTH];
  while (fgets(line, MAX_ROW_LENGTH, file) != NULL) {
    csv->num_rows++;
    char *token = strtok(line, ",");
    while (token != NULL) {
      csv->num_columns++;
      token = strtok(NULL, ",");
    }
  }

  csv->data = malloc(sizeof(char*) * csv->num_rows * csv->num_columns);
  rewind(file);

  int row = 0;
  while (fgets(line, MAX_ROW_LENGTH, file) != NULL) {
    int col = 0;
    char *token = strtok(line, ",");
    while (token != NULL) {
      csv->data[row][col] = token;
      col++;
      token = strtok(NULL, ",");
    }
    row++;
  }

  fclose(file);
  return csv;
}

void print_csv(CSV *csv) {
  for (int row = 0; row < csv->num_rows; row++) {
    for (int col = 0; col < csv->num_columns; col++) {
      printf("%s ", csv->data[row][col]);
    }
    printf("\n");
  }
}

int main() {
  CSV *csv = create_csv("data.csv");
  print_csv(csv);
  return 0;
}