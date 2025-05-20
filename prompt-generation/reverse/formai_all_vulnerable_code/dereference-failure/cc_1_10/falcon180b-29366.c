//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 100

typedef struct {
    char *row[MAX_ROW_SIZE];
    int rows;
    int cols;
} CSV;

CSV *csv_init() {
    CSV *csv = (CSV*) malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;
    for (int i = 0; i < MAX_ROW_SIZE; i++) {
        csv->row[i] = NULL;
    }
    return csv;
}

void csv_add_row(CSV *csv, char *row) {
    if (csv->rows == MAX_ROW_SIZE) {
        printf("Error: Maximum number of rows reached. ");
        return;
    }
    csv->row[csv->rows] = row;
    csv->rows++;
    int cols = 0;
    char *token = strtok(row, ",");
    while (token!= NULL) {
        if (cols == MAX_COL_SIZE) {
            printf("Error: Maximum number of columns reached. ");
            return;
        }
        csv->row[csv->rows - 1][cols] = token;
        token = strtok(NULL, ",");
        cols++;
    }
    csv->cols = cols;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->row[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_init();
    char *row1 = "Name,Age,City";
    char *row2 = "John,25,New York";
    char *row3 = "Jane,30,Los Angeles";
    csv_add_row(csv, row1);
    csv_add_row(csv, row2);
    csv_add_row(csv, row3);
    csv_print(csv);
    return 0;
}