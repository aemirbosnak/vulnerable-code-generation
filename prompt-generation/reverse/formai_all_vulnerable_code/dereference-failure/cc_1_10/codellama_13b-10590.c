//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSV_BUF_SIZE 1024
#define CSV_MAX_COLS 10

typedef struct {
  char *data[CSV_MAX_COLS];
  int num_cols;
} csv_row_t;

typedef struct {
  csv_row_t *rows[CSV_BUF_SIZE];
  int num_rows;
} csv_table_t;

csv_row_t *csv_read_row(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  read = getline(&line, &len, fp);
  if (read == -1) {
    return NULL;
  }

  char *row_data[CSV_MAX_COLS];
  int num_cols = 0;

  char *col = strtok(line, ",");
  while (col != NULL && num_cols < CSV_MAX_COLS) {
    row_data[num_cols++] = col;
    col = strtok(NULL, ",");
  }

  csv_row_t *row = malloc(sizeof(csv_row_t));
  row->num_cols = num_cols;
  memcpy(row->data, row_data, num_cols * sizeof(char *));

  return row;
}

csv_table_t *csv_read_table(FILE *fp) {
  csv_table_t *table = malloc(sizeof(csv_table_t));
  table->num_rows = 0;

  csv_row_t *row;
  while ((row = csv_read_row(fp)) != NULL) {
    table->rows[table->num_rows++] = row;
  }

  return table;
}

int main() {
  FILE *fp = fopen("data.csv", "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  csv_table_t *table = csv_read_table(fp);
  for (int i = 0; i < table->num_rows; i++) {
    csv_row_t *row = table->rows[i];
    for (int j = 0; j < row->num_cols; j++) {
      printf("%s ", row->data[j]);
    }
    printf("\n");
  }

  fclose(fp);
  return 0;
}