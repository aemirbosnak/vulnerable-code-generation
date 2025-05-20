//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 100

typedef struct {
    char **row_data;
    int row_count;
    int col_count;
} CSVReader;

CSVReader *csv_init() {
    CSVReader *csv = (CSVReader *)malloc(sizeof(CSVReader));
    if (csv == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    csv->row_data = (char **)malloc(MAX_ROW * sizeof(char *));
    if (csv->row_data == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    csv->row_count = 0;
    csv->col_count = 0;
    return csv;
}

void csv_free(CSVReader *csv) {
    for (int i = 0; i < csv->row_count; i++) {
        free(csv->row_data[i]);
    }
    free(csv->row_data);
    free(csv);
}

void csv_add_row(CSVReader *csv, const char *row) {
    csv->row_data[csv->row_count] = strdup(row);
    csv->row_count++;
    int col_count = 0;
    char *token = strtok(row, ",");
    while (token!= NULL) {
        if (col_count >= csv->col_count) {
            csv->col_count++;
        }
        csv->row_data[csv->row_count - 1][col_count] = strdup(token);
        col_count++;
        token = strtok(NULL, ",");
    }
}

void csv_print(CSVReader *csv) {
    for (int i = 0; i < csv->row_count; i++) {
        for (int j = 0; j < csv->col_count; j++) {
            printf("%s ", csv->row_data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSVReader *csv = csv_init();
    csv_add_row(csv, "Name,Age,City");
    csv_add_row(csv, "John,25,New York");
    csv_add_row(csv, "Jane,30,Los Angeles");
    csv_print(csv);
    csv_free(csv);
    return 0;
}