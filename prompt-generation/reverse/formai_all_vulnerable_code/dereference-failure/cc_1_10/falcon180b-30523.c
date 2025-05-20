//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_CSV_COLUMNS 100
#define MAX_CSV_ROWS 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_create(void) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_CSV_ROWS * sizeof(char *));
    csv->num_rows = 0;
    csv->num_cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_add_row(CSV *csv, char *row) {
    int num_cols = 0;
    char *token = strtok(row, ",");
    while (token!= NULL) {
        csv->data[csv->num_rows] = strdup(token);
        num_cols++;
        csv->num_cols = (csv->num_cols > num_cols)? csv->num_cols : num_cols;
        token = strtok(NULL, ",");
    }
    csv->num_rows++;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
}

CSV *csv_read_file(FILE *fp) {
    CSV *csv = csv_create();
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        csv_add_row(csv, line);
    }
    return csv;
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    CSV *csv = csv_read_file(fp);
    csv_print(csv);
    csv_destroy(csv);
    fclose(fp);
    return 0;
}