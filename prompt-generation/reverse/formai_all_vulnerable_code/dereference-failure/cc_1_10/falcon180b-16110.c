//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 1000
#define MAX_ROWS 1000000
#define MAX_CELL_DATA 10000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_create(void) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    csv->num_rows = 0;
    csv->num_cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            free(csv->data[i]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_add_row(CSV *csv, char *row) {
    int len = strlen(row);
    if (len > MAX_CELL_DATA) {
        printf("Error: Cell data too large.\n");
        return;
    }
    if (csv->num_rows >= MAX_ROWS) {
        printf("Error: Too many rows.\n");
        return;
    }
    csv->data[csv->num_rows] = (char *)malloc(len + 1);
    strcpy(csv->data[csv->num_rows], row);
    csv->num_rows++;
    int num_cols = strlen(row) - strcspn(row, ",") + 1;
    if (csv->num_cols == 0) {
        csv->num_cols = num_cols;
    } else if (num_cols!= csv->num_cols) {
        printf("Error: Number of columns does not match.\n");
        return;
    }
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    CSV *csv = csv_create();
    char line[MAX_CELL_DATA];
    while (fgets(line, MAX_CELL_DATA, stdin)!= NULL) {
        csv_add_row(csv, line);
    }
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}