//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_NUM_FIELDS 100

struct csv_field {
  char *value;
  int len;
};

struct csv_row {
  struct csv_field fields[MAX_NUM_FIELDS];
  int num_fields;
};

struct csv_file {
  struct csv_row rows[MAX_NUM_FIELDS];
  int num_rows;
};

void csv_read(FILE *fp, struct csv_file *csv) {
  int i, j;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  char *field;
  int field_len;
  struct csv_row *row;
  struct csv_field *field_info;

  while ((read = getline(&line, &len, fp)) != -1) {
    row = &csv->rows[csv->num_rows++];
    field = strtok(line, ",");
    field_info = &row->fields[0];
    field_info->value = field;
    field_info->len = strlen(field);
    for (i = 1; i < MAX_NUM_FIELDS; i++) {
      field = strtok(NULL, ",");
      if (field == NULL) break;
      field_info = &row->fields[i];
      field_info->value = field;
      field_info->len = strlen(field);
    }
    row->num_fields = i;
  }
}

void csv_print(struct csv_file *csv) {
  int i, j;
  struct csv_row *row;
  struct csv_field *field_info;

  for (i = 0; i < csv->num_rows; i++) {
    row = &csv->rows[i];
    for (j = 0; j < row->num_fields; j++) {
      field_info = &row->fields[j];
      printf("%s", field_info->value);
      if (j < row->num_fields - 1) printf(",");
    }
    printf("\n");
  }
}

int main(void) {
  struct csv_file csv;
  FILE *fp;

  fp = fopen("example.csv", "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  csv_read(fp, &csv);
  fclose(fp);

  csv_print(&csv);

  return 0;
}