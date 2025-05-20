//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        int cols = 0;
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, DELIMITER);
        }
        if (cols > csv->cols) {
            csv->cols = cols;
        }
        csv->rows++;
    }

    csv->data = malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(csv->cols * sizeof(char));
    }

    rewind(file);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_row_count(CSV *csv) {
    return csv->rows;
}

int csv_get_col_count(CSV *csv) {
    return csv->cols;
}

char *csv_get_value(CSV *csv, int row, int col) {
    if (row >= csv->rows || col >= csv->cols) {
        return NULL;
    }
    return csv->data[row][col];
}

int main() {
    CSV *csv = csv_open("example.csv");

    int rows = csv_get_row_count(csv);
    int cols = csv_get_col_count(csv);

    printf("CSV has %d rows and %d columns\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char *value = csv_get_value(csv, i, j);
            if (value!= NULL) {
                printf("%s ", value);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}