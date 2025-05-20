//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000

struct field {
  char *name;
  char *value;
  struct field *next;
};

struct field *create_field(char *name, char *value) {
  struct field *field = malloc(sizeof(struct field));
  field->name = strdup(name);
  field->value = strdup(value);
  field->next = NULL;
  return field;
}

void delete_field(struct field *field) {
  free(field->name);
  free(field->value);
  free(field);
}

struct field *read_csv_file(FILE *file) {
  char line[MAX_LINE_LENGTH];
  char *token;
  struct field *fields = NULL;

  while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
    token = strtok(line, ",");
    while (token!= NULL) {
      struct field *field = create_field(token, "");
      field->next = fields;
      fields = field;
      token = strtok(NULL, ",");
    }
  }

  return fields;
}

void print_fields(struct field *fields) {
  while (fields!= NULL) {
    printf("%s: %s\n", fields->name, fields->value);
    fields = fields->next;
  }
}

int main() {
  FILE *file;
  char filename[MAX_LINE_LENGTH];
  printf("Enter the CSV file name: ");
  scanf("%s", filename);

  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  struct field *fields = read_csv_file(file);
  if (fields == NULL) {
    printf("Error reading file.\n");
    return 1;
  }

  print_fields(fields);

  delete_field(fields);
  fclose(file);

  return 0;
}