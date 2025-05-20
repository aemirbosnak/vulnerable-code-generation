//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_DATA {
  char **data;
  int rows;
  int cols;
} CSV_DATA;

CSV_DATA *csv_read(char *filename) {
  CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Read the number of rows and columns
  fscanf(file, "%d, %d", &csv_data->rows, &csv_data->cols);

  // Allocate memory for the data
  csv_data->data = malloc(sizeof(char *) * csv_data->rows);
  for (int i = 0; i < csv_data->rows; i++) {
    csv_data->data[i] = malloc(sizeof(char) * csv_data->cols);
  }

  // Read the CSV data
  char line[MAX_ROWS][MAX_COLS];
  int row = 0;
  while (fgets(line[row], MAX_COLS, file) != NULL) {
    row++;
  }

  // Copy the data into the CSV structure
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < csv_data->cols; j++) {
      csv_data->data[i][j] = line[i][j];
    }
  }

  fclose(file);

  return csv_data;
}

int main() {
  char *filename = "example.csv";
  CSV_DATA *csv_data = csv_read(filename);

  if (csv_data) {
    // Print the CSV data
    for (int i = 0; i < csv_data->rows; i++) {
      for (int j = 0; j < csv_data->cols; j++) {
        printf("%s ", csv_data->data[i][j]);
      }
      printf("\n");
    }

    // Free the CSV data
    for (int i = 0; i < csv_data->rows; i++) {
      free(csv_data->data[i]);
    }
    free(csv_data->data);
    free(csv_data);
  } else {
    printf("Error reading CSV file.\n");
  }

  return 0;
}