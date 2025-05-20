//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100
#define DELIMITER ","

typedef struct {
    char **fields;
    int field_count;
} CSVRow;

CSVRow *read_csv_file(FILE *fp) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->fields = malloc(MAX_FIELDS * sizeof(char*));
    row->field_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *delim = strchr(line, DELIMITER);
        if (delim == NULL) {
            printf("Error: Line too long\n");
            exit(1);
        }
        *delim = '\0';

        row->fields[row->field_count] = strdup(line);
        row->field_count++;
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        printf("%s%c", row->fields[i], DELIMITER);
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    CSVRow *row = read_csv_file(fp);
    print_csv_row(row);

    free_csv_row(row);
    fclose(fp);

    return 0;
}