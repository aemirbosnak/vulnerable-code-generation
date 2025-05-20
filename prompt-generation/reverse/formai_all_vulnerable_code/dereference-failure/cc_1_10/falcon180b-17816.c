//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 100

typedef struct {
    char *data;
    int len;
} String;

typedef struct {
    String **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv(FILE *fp) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->fields = malloc(MAX_FIELDS * sizeof(String *));
    row->num_fields = 0;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            String *field = malloc(sizeof(String));
            field->data = malloc(strlen(token) + 1);
            strcpy(field->data, token);
            field->len = strlen(token);
            row->fields[row->num_fields++] = field;

            token = strtok(NULL, ",");
        }
    }

    return row;
}

void print_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]->data);
    }
    printf("\n");
}

void free_row(CSVRow *row) {
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
        printf("Error opening file.\n");
        return 1;
    }

    CSVRow *row = read_csv(fp);
    if (row == NULL) {
        printf("Error reading CSV file.\n");
        return 1;
    }

    print_row(row);

    free_row(row);
    fclose(fp);

    return 0;
}