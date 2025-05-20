//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create() {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));
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
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    char line[MAX_CELL_SIZE];
    int row = 0;
    int col = 0;
    CSV *csv = csv_create();

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            if (col >= csv->cols) {
                csv->cols++;
            }
            csv_add_row(csv, token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }

    csv_print(csv);

    fclose(fp);
    csv_destroy(csv);

    return 0;
}