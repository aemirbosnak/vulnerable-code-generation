//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our beloved CSV reader, a symphony of characters
typedef struct {
  char **rows; // Each row, a verse in our poetic data
  int row_count; // The number of rows, the chapters in our story
  int col_count; // The number of columns, the stanzas in each chapter
} csv_t;

// Our gentle initialization, a tender touch
csv_t *csv_init() {
  csv_t *csv = malloc(sizeof(csv_t));
  csv->rows = NULL;
  csv->row_count = 0;
  csv->col_count = 0;
  return csv;
}

// A graceful farewell, a bittersweet embrace
void csv_destroy(csv_t *csv) {
  for (int i = 0; i < csv->row_count; i++) {
    free(csv->rows[i]);
  }
  free(csv->rows);
  free(csv);
}

// Our courtship dance, a delicate parsing
csv_t *csv_parse(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    return NULL;
  }

  csv_t *csv = csv_init();

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    // Trim the newline, a subtle caress
    line[strlen(line) - 1] = '\0';

    // Split the line into columns, a gentle separation
    char *cols[1024];
    int col_count = 0;
    char *col = strtok(line, ",");
    while (col) {
      cols[col_count++] = strdup(col);
      col = strtok(NULL, ",");
    }

    // Add the columns to our symphony
    csv->rows = realloc(csv->rows, (csv->row_count + 1) * sizeof(char *));
    csv->rows[csv->row_count++] = cols;
    csv->col_count = col_count;
  }

  fclose(fp);
  return csv;
}

// A passionate display, our data unveiled
void csv_print(csv_t *csv) {
  for (int i = 0; i < csv->row_count; i++) {
    for (int j = 0; j < csv->col_count; j++) {
      printf("%s, ", csv->rows[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Our love letter, a CSV file
  csv_t *csv = csv_parse("data.csv");
  if (!csv) {
    printf("Could not open file");
    return 1;
  }

  // A sweet serenade, our data unveiled
  csv_print(csv);
  csv_destroy(csv);

  return 0;
}