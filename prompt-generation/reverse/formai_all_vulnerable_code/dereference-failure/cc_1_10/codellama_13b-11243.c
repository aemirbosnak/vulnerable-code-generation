//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
/*
 * csv_reader.c
 *
 * A simple CSV reader example program in the style of Dennis Ritchie.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_LEN 128

typedef struct {
  char *data;
  size_t len;
} Field;

typedef struct {
  Field **fields;
  size_t num_fields;
} Record;

Record *read_record(FILE *fp) {
  Record *record = malloc(sizeof(Record));
  if (record == NULL) {
    return NULL;
  }

  record->fields = malloc(sizeof(Field *) * MAX_FIELD_LEN);
  if (record->fields == NULL) {
    return NULL;
  }

  char line[MAX_LINE_LEN];
  if (fgets(line, sizeof(line), fp) == NULL) {
    return NULL;
  }

  char *field = strtok(line, ",");
  size_t field_index = 0;
  while (field != NULL) {
    record->fields[field_index] = malloc(sizeof(Field));
    if (record->fields[field_index] == NULL) {
      return NULL;
    }

    record->fields[field_index]->data = strdup(field);
    record->fields[field_index]->len = strlen(field);
    field_index++;
    field = strtok(NULL, ",");
  }

  record->num_fields = field_index;
  return record;
}

void print_record(Record *record) {
  for (size_t i = 0; i < record->num_fields; i++) {
    printf("%s", record->fields[i]->data);
    if (i < record->num_fields - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error: failed to open file %s\n", argv[1]);
    return 1;
  }

  Record *record = read_record(fp);
  if (record == NULL) {
    printf("Error: failed to read record from file\n");
    return 1;
  }

  print_record(record);

  for (size_t i = 0; i < record->num_fields; i++) {
    free(record->fields[i]->data);
    free(record->fields[i]);
  }
  free(record->fields);
  free(record);

  fclose(fp);
  return 0;
}