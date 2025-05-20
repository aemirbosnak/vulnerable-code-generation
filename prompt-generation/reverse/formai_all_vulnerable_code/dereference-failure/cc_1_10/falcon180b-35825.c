//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_CELL_SIZE 1024

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;
    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        if (cols > csv->num_cols) {
            csv->num_cols = cols;
        }
        csv->num_rows++;
    }
    csv->data = (char **)malloc(csv->num_rows * sizeof(char *));
    for (int i = 0; i < csv->num_rows; i++) {
        csv->data[i] = (char *)malloc(csv->num_cols * MAX_CELL_SIZE);
    }
    rewind(fp);
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_num_rows(CSV *csv) {
    return csv->num_rows;
}

int csv_get_num_cols(CSV *csv) {
    return csv->num_cols;
}

char *csv_get_cell(CSV *csv, int row, int col) {
    return csv->data[row][col];
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_create(fp);
    int num_rows = csv_get_num_rows(csv);
    int num_cols = csv_get_num_cols(csv);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s ", csv_get_cell(csv, i, j));
        }
        printf("\n");
    }
    csv_destroy(csv);
    fclose(fp);
    return 0;
}