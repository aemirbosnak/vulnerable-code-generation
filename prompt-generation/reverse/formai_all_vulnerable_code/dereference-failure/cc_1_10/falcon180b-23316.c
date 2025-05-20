//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100

typedef struct {
    char *data;
    int len;
} String;

typedef struct {
    String **fields;
    int num_fields;
} CSVRow;

CSVRow *csv_read_row(FILE *fp) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;
    row->fields = malloc(sizeof(String *));

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        String *field = malloc(sizeof(String));
        field->data = line;
        field->len = strlen(line);
        row->fields = realloc(row->fields, sizeof(String *) * ++row->num_fields);
        row->fields[row->num_fields - 1] = field;
    }

    return row;
}

void csv_free_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]->data);
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp = fopen("data.csv", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    CSVRow *row = csv_read_row(fp);

    printf("Number of fields: %d\n", row->num_fields);

    for (int i = 0; i < row->num_fields; i++) {
        printf("Field %d: %s\n", i + 1, row->fields[i]->data);
    }

    csv_free_row(row);
    fclose(fp);

    return 0;
}