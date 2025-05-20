//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
// csv_reader.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

typedef struct {
  char **fields;
  int num_fields;
} csv_row_t;

csv_row_t *read_csv_row(FILE *file) {
  csv_row_t *row = malloc(sizeof(csv_row_t));
  row->num_fields = 0;
  row->fields = NULL;

  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&line, &len, file)) != -1) {
    char *field = strtok(line, ",");
    while (field != NULL) {
      row->fields = realloc(row->fields, (row->num_fields + 1) * sizeof(char *));
      row->fields[row->num_fields] = strdup(field);
      row->num_fields++;
      field = strtok(NULL, ",");
    }
  }

  return row;
}

void free_csv_row(csv_row_t *row) {
  for (int i = 0; i < row->num_fields; i++) {
    free(row->fields[i]);
  }
  free(row->fields);
  free(row);
}

int main(int argc, char *argv[]) {
  FILE *file = fopen("example.csv", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  csv_row_t *row = read_csv_row(file);
  for (int i = 0; i < row->num_fields; i++) {
    printf("%s\n", row->fields[i]);
  }

  free_csv_row(row);
  fclose(file);

  return 0;
}