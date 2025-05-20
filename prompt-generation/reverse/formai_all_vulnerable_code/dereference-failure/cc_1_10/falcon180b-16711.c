//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CsvRow;

CsvRow *csv_read_row(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    CsvRow *row = NULL;
    int num_fields = 0;

    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        return NULL;
    }

    while (line[num_fields]!= '\n' && line[num_fields]!= '\r') {
        if (num_fields >= MAX_FIELDS) {
            fprintf(stderr, "Error: Too many fields in row.\n");
            exit(1);
        }
        char *field = strchr(line, ',');
        if (field == NULL) {
            field = strchr(line, '\n');
            field[0] = '\0';
        } else {
            *field = '\0';
        }
        row->fields[num_fields] = strdup(line);
        num_fields++;
    }

    row->num_fields = num_fields;
    return row;
}

void csv_free_row(CsvRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open data.csv.\n");
        exit(1);
    }

    CsvRow *row = csv_read_row(fp);
    while (row!= NULL) {
        for (int i = 0; i < row->num_fields; i++) {
            printf("%s\t", row->fields[i]);
        }
        printf("\n");
        csv_free_row(row);
        row = csv_read_row(fp);
    }

    fclose(fp);
    return 0;
}