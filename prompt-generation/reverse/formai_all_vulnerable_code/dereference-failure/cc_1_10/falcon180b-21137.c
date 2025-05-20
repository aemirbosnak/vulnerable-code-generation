//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_CELL_SIZE 1000

typedef struct {
    int rows;
    int cols;
    char **data;
} csv_t;

csv_t *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_CELL_SIZE];
    csv_t *csv = malloc(sizeof(csv_t));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = malloc(sizeof(char *) * MAX_ROWS);

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        int i, j;
        csv->rows++;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            csv->cols = csv->cols > strlen(token)? csv->cols : strlen(token);
            csv->data[csv->rows - 1] = realloc(csv->data[csv->rows - 1], csv->cols * sizeof(char *));
            csv->data[csv->rows - 1][csv->cols - strlen(token)] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return csv;
}

void csv_close(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    csv_t *csv = csv_open("example.csv");
    if (csv == NULL) {
        printf("Error opening CSV file.\n");
        return 1;
    }

    csv_print(csv);

    csv_close(csv);

    return 0;
}