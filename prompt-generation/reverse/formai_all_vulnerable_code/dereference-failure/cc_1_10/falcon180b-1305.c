//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000
#define DELIMITER ","

typedef struct {
    char *name;
    int length;
} field_t;

field_t *fields = NULL;
int num_fields = 0;

void add_field(char *name) {
    field_t *new_field = malloc(sizeof(field_t));
    new_field->name = name;
    new_field->length = strlen(name);
    fields = realloc(fields, sizeof(field_t) * ++num_fields);
    fields[num_fields - 1] = *new_field;
}

void read_csv_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            add_field(token);
            token = strtok(NULL, DELIMITER);
        }
        i++;
    }
}

void print_fields() {
    int i;

    for (i = 0; i < num_fields; i++) {
        printf("%s (%d)\n", fields[i].name, fields[i].length);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_LINE_LENGTH];

    if (argc!= 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    read_csv_file(file);
    print_fields();

    fclose(file);
    return 0;
}