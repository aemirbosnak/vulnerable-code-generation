//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(void) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_add_row(CSV *csv, char *row) {
    csv->data[csv->rows] = strdup(row);
    csv->rows++;
    int cols = 0;
    char *cell = strtok(csv->data[csv->rows - 1], ",");
    while (cell!= NULL) {
        cols++;
        cell = strtok(NULL, ",");
    }
    if (cols > csv->cols) {
        csv->cols = cols;
    }
}

int csv_get_rows(CSV *csv) {
    return csv->rows;
}

int csv_get_cols(CSV *csv) {
    return csv->cols;
}

char **csv_get_data(CSV *csv) {
    return csv->data;
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    CSV *csv = csv_create();

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        csv_add_row(csv, line);
    }

    fclose(fp);

    int rows = csv_get_rows(csv);
    int cols = csv_get_cols(csv);
    char **data = csv_get_data(csv);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", data[i]);
        }
        printf("\n");
    }

    csv_destroy(csv);

    return 0;
}