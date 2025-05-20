//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10000
#define MAX_COLS 10000
#define MAX_CHARS 10000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(int rows, int cols) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = (char **) malloc(rows * sizeof(char *));
    csv->rows = rows;
    csv->cols = cols;
    for (int i = 0; i < rows; i++) {
        csv->data[i] = (char *) malloc(cols * sizeof(char));
    }
    return csv;
}

int csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
    return 0;
}

int csv_read(CSV *csv, const char *file_path) {
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", file_path);
        return -1;
    }
    char line[MAX_CHARS];
    int row = 0;
    while (fgets(line, MAX_CHARS, fp)!= NULL) {
        int col = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            strcpy(csv->data[row][col], token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }
    fclose(fp);
    return 0;
}

int csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Please provide a CSV file path\n");
        return -1;
    }
    CSV *csv = csv_create(MAX_ROWS, MAX_COLS);
    csv_read(csv, argv[1]);
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}