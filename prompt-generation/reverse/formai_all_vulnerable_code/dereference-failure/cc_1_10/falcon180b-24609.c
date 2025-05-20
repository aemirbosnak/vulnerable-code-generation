//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1024

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = malloc(MAX_ROWS * sizeof(char *));

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col_count = 0;

        while (token!= NULL) {
            if (col_count >= MAX_COLS) {
                fprintf(stderr, "Error: too many columns in row\n");
                exit(1);
            }

            int len = strlen(token);
            if (len >= MAX_CELL_SIZE) {
                fprintf(stderr, "Error: cell value too long in row\n");
                exit(1);
            }

            csv->data[csv->num_rows] = malloc(MAX_CELL_SIZE);
            strcpy(csv->data[csv->num_rows], token);
            csv->num_rows++;
            csv->num_cols = col_count > csv->num_cols? col_count : csv->num_cols;

            token = strtok(NULL, ",");
            col_count++;
        }
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}