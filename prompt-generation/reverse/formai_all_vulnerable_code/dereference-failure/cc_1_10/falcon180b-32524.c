//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_DATA_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV* csv_create() {
    CSV *csv = (CSV*) malloc(sizeof(CSV));
    csv->data = (char**) malloc(MAX_ROWS * sizeof(char*));
    csv->rows = 0;
    csv->cols = 0;
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

int csv_read(CSV *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return -1;
    }

    char line[MAX_CELL_DATA_SIZE];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            csv->data[csv->rows] = (char*) malloc(strlen(token) + 1);
            strcpy(csv->data[csv->rows], token);
            csv->cols = (csv->cols > cols)? csv->cols : cols;
            token = strtok(NULL, ",");
            cols++;
        }
        csv->rows++;
    }

    fclose(fp);
    return 0;
}

int csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    CSV *csv = csv_create();
    csv_read(csv, "data.csv");
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}