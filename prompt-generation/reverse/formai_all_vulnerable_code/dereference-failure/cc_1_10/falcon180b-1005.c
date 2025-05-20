//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rows;
    int cols;
    char **data;
} csv_t;

csv_t *csv_open(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    csv_t *csv = (csv_t *) malloc(sizeof(csv_t));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        csv->rows++;
        int cols = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        if (cols > csv->cols) {
            csv->cols = cols;
        }
    }

    csv->data = (char **) malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = (char *) malloc(csv->cols * sizeof(char));
    }

    rewind(file);
    return csv;
}

void csv_close(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

char *csv_get(csv_t *csv, int row, int col) {
    if (row >= csv->rows || col >= csv->cols) {
        return NULL;
    }

    return csv->data[row][col];
}

int main() {
    csv_t *csv = csv_open("example.csv");

    if (csv == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            char *value = csv_get(csv, i, j);
            if (value!= NULL) {
                printf("%s ", value);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }

    csv_close(csv);
    return 0;
}