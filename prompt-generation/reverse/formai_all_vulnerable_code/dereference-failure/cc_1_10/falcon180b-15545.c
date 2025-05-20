//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
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

    csv->data = (char **)malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = (char *)malloc(csv->cols * sizeof(char));
    }

    rewind(fp);
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_rows(CSV *csv) {
    return csv->rows;
}

int csv_get_cols(CSV *csv) {
    return csv->cols;
}

char *csv_get_cell(CSV *csv, int row, int col) {
    return csv->data[row][col];
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_create(fp);

    for (int i = 0; i < csv_get_rows(csv); i++) {
        for (int j = 0; j < csv_get_cols(csv); j++) {
            printf("%s ", csv_get_cell(csv, i, j));
        }
        printf("\n");
    }

    csv_destroy(csv);
    fclose(fp);

    return 0;
}