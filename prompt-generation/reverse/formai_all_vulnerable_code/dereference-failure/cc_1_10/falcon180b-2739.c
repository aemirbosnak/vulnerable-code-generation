//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_CELL_SIZE 1024

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_open(const char *filename) {
    FILE *fp;
    char line[MAX_CELL_SIZE];
    csv_t *csv;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    csv = malloc(sizeof(csv_t));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;

        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }

        if (cols > csv->cols) {
            csv->cols = cols;
        }

        csv->rows++;
    }

    rewind(fp);
    csv->data = malloc(csv->rows * sizeof(char *));

    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(csv->cols * MAX_CELL_SIZE);
    }

    fseek(fp, 0, SEEK_SET);

    return csv;
}

void csv_close(csv_t *csv) {
    int i;

    for (i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }

    free(csv->data);
    free(csv);
}

int csv_get_row_count(csv_t *csv) {
    return csv->rows;
}

int csv_get_col_count(csv_t *csv) {
    return csv->cols;
}

char *csv_get_cell(csv_t *csv, int row, int col) {
    if (row >= csv->rows || col >= csv->cols) {
        return NULL;
    }

    return csv->data[row][col];
}

int main() {
    csv_t *csv;
    int rows, cols;
    char **data;

    csv = csv_open("example.csv");

    rows = csv_get_row_count(csv);
    cols = csv_get_col_count(csv);

    printf("Rows: %d\n", rows);
    printf("Cols: %d\n", cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char *cell = csv_get_cell(csv, i, j);
            printf("%s ", cell);
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}