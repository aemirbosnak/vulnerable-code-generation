//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100

typedef struct {
    char **columns;
    int num_columns;
} CsvRow;

CsvRow *csv_read_file(FILE *file) {
    CsvRow *row = malloc(sizeof(CsvRow));
    row->columns = malloc(MAX_COLUMNS * sizeof(char *));
    row->num_columns = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            row->columns[row->num_columns++] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    return row;
}

void csv_print_row(CsvRow *row) {
    for (int i = 0; i < row->num_columns; i++) {
        printf("%s ", row->columns[i]);
    }
    printf("\n");
}

void csv_free_row(CsvRow *row) {
    for (int i = 0; i < row->num_columns; i++) {
        free(row->columns[i]);
    }
    free(row->columns);
    free(row);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    CsvRow *row = csv_read_file(file);
    csv_print_row(row);

    csv_free_row(row);
    fclose(file);

    return 0;
}