//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
  char **data;
  int rows;
  int cols;
} CSV;

CSV *read_csv(FILE *fp) {
  CSV *csv = (CSV *)malloc(sizeof(CSV));
  csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));
  csv->rows = 0;
  csv->cols = 0;

  char line[1024];
  while (fgets(line, sizeof(line), fp)!= NULL) {
    char *token = strtok(line, ",");
    int col_count = 0;

    while (token!= NULL) {
      if (col_count >= MAX_COLS) {
        printf("Error: Maximum number of columns exceeded.\n");
        exit(1);
      }

      csv->data[csv->rows] = (char *)malloc((strlen(token) + 1) * sizeof(char));
      strcpy(csv->data[csv->rows], token);

      if (col_count == 0) {
        csv->cols = csv->rows + 1;
      }

      col_count++;
      token = strtok(NULL, ",");
    }

    csv->rows++;
  }

  return csv;
}

void free_csv(CSV *csv) {
  for (int i = 0; i < csv->rows; i++) {
    free(csv->data[i]);
  }
  free(csv->data);
  free(csv);
}

void print_csv(CSV *csv) {
  for (int i = 0; i < csv->rows; i++) {
    for (int j = 0; j < csv->cols; j++) {
      printf("%s\t", csv->data[i]);
    }
    printf("\n");
  }
}

int main() {
  FILE *fp = fopen("example.csv", "r");
  if (fp == NULL) {
    printf("Error: File not found.\n");
    exit(1);
  }

  CSV *csv = read_csv(fp);
  fclose(fp);

  print_csv(csv);

  free_csv(csv);

  return 0;
}