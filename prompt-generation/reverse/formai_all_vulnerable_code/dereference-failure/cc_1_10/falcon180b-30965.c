//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    CSV *csv = (CSV*)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        if (cols > csv->cols) {
            csv->cols = cols;
        }
        csv->rows++;
    }

    csv->data = (char**)malloc(csv->rows * sizeof(char*));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = (char*)malloc(csv->cols * sizeof(char));
    }

    rewind(file);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_int(CSV *csv, int row, int col) {
    return atoi(csv->data[row][col]);
}

char *csv_get_string(CSV *csv, int row, int col) {
    return csv->data[row][col];
}

int main() {
    CSV *csv = csv_open("example.csv");

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}