//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
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
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    char *token;
    int i = 0;

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        int cols = 0;
        token = strtok(line, ",");

        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }

        if (cols > csv->cols) {
            csv->cols = cols;
        }

        csv->data = realloc(csv->data, sizeof(char *) * csv->rows * csv->cols);

        for (int j = 0; j < csv->cols; j++) {
            csv->data[i * csv->cols + j] = malloc(MAX_CELL_SIZE);
            strcpy(csv->data[i * csv->cols + j], token);
            token = strtok(NULL, ",");
        }

        i++;
    }

    csv->rows = i;

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i * csv->cols + j]);
        }
    }

    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");

    CSV *csv = csv_create(fp);
    csv_print(csv);

    csv_destroy(csv);

    fclose(fp);

    return 0;
}