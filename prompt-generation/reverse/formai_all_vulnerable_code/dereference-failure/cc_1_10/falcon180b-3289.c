//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *fp) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;
    row->fields = malloc(MAX_FIELDS * sizeof(char*));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;

        while (token!= NULL) {
            if (i >= MAX_FIELDS) {
                printf("Error: Too many fields in row.\n");
                exit(1);
            }

            row->fields[i] = malloc(strlen(token) + 1);
            strcpy(row->fields[i], token);
            token = strtok(NULL, ",");
            i++;
        }

        row->num_fields = i;
        break;
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    CSVRow *row = read_csv_file(fp);
    print_csv_row(row);

    free_csv_row(row);
    fclose(fp);

    return 0;
}