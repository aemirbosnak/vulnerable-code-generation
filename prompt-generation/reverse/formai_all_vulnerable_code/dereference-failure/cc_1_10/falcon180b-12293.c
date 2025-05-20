//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *file) {
    CSVRow *row = NULL;
    char line[MAX_LINE_LENGTH];
    char *token;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (row == NULL) {
            row = malloc(sizeof(CSVRow));
            row->num_fields = 0;
        }

        token = strtok(line, ",");
        while (token!= NULL) {
            if (num_fields == MAX_FIELDS) {
                printf("Error: Too many fields in row.\n");
                exit(1);
            }

            row->fields[num_fields++] = strdup(token);

            token = strtok(NULL, ",");
        }
    }

    if (row!= NULL) {
        row->fields[num_fields] = NULL;
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
    FILE *file = fopen("data.csv", "r");
    CSVRow *row = read_csv_file(file);

    while (row!= NULL) {
        print_csv_row(row);
        free_csv_row(row);
        row = read_csv_file(file);
    }

    fclose(file);

    return 0;
}