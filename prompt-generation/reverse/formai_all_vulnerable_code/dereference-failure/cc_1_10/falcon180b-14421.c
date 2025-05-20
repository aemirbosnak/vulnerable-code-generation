//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 1000
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_create(FILE *file) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_columns = 0;
    csv->data = (char **) malloc(MAX_ROWS * sizeof(char *));
    for (int i = 0; i < MAX_ROWS; i++) {
        csv->data[i] = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",");
        int column_count = 0;
        while (token!= NULL) {
            csv->data[csv->num_rows][column_count] = token;
            column_count++;
            token = strtok(NULL, ",");
        }
        csv->num_columns = column_count;
        csv->num_rows++;
    }
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

char *csv_get_value(CSV *csv, int row, int column) {
    if (row >= csv->num_rows || column >= csv->num_columns) {
        return NULL;
    }
    return csv->data[row][column];
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSV *csv = csv_create(file);
    fclose(file);

    int num_rows = csv->num_rows;
    int num_columns = csv->num_columns;

    printf("Number of rows: %d\n", num_rows);
    printf("Number of columns: %d\n", num_columns);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            char *value = csv_get_value(csv, i, j);
            printf("%s ", value);
        }
        printf("\n");
    }

    csv_destroy(csv);
    return 0;
}