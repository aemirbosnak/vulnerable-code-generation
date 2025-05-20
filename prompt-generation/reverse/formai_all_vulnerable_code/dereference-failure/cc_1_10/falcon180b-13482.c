//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num_fields;
    char delimiter;
    char **fields;
} CSVRow;

CSVRow *read_csv(FILE *fp) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;
    row->delimiter = ',';
    row->fields = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, row->delimiter);
        while (token!= NULL) {
            row->num_fields++;
            row->fields = realloc(row->fields, sizeof(char *) * row->num_fields);
            row->fields[row->num_fields - 1] = strdup(token);
            token = strtok(NULL, row->delimiter);
        }
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s", row->fields[i]);
        if (i < row->num_fields - 1) {
            printf(", ");
        }
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
        printf("Error: could not open file.\n");
        return 1;
    }

    CSVRow *row = read_csv(fp);

    printf("CSV Data:\n");
    while (row!= NULL) {
        print_csv_row(row);
        row = read_csv(fp);
    }

    fclose(fp);
    free_csv_row(row);
    return 0;
}