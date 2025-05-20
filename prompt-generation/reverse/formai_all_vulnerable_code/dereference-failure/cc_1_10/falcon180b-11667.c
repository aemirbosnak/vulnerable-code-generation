//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_open(const char *filename) {
    csv_t *csv = malloc(sizeof(csv_t));
    csv->data = malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            csv->data[csv->rows] = malloc(MAX_CELL_SIZE);
            strcpy(csv->data[csv->rows], token);
            csv->cols++;
            csv->rows++;
            token = strtok(NULL, ",");
        }
    }

    fclose(file);

    return csv;
}

void csv_print(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_close(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    csv_t *csv = csv_open("data.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}