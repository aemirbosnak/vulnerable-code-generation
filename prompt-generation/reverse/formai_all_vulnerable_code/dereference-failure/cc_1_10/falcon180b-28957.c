//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    int rows;
    int cols;
    char **data;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    // read first line to determine number of columns
    char line[MAX_CELL_SIZE];
    fgets(line, MAX_CELL_SIZE, fp);
    int cols = 0;
    char *token = strtok(line, ",");
    while (token!= NULL) {
        cols++;
        token = strtok(NULL, ",");
    }

    // allocate memory for data
    csv->data = malloc(sizeof(char *) * cols);
    for (int i = 0; i < cols; i++) {
        csv->data[i] = malloc(MAX_CELL_SIZE);
    }

    // read remaining lines
    int rows = 0;
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        for (int i = 0; i < cols; i++) {
            strcpy(csv->data[i], token);
            token = strtok(NULL, ",");
        }
        rows++;
    }

    csv->rows = rows;
    csv->cols = cols;

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->cols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    if (csv == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    csv_print(csv);

    csv_close(csv);

    return 0;
}