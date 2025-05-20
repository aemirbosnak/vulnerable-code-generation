//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
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

CSV *csv_read(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        char **row_data = realloc(csv->data, sizeof(char *) * (row + 1));
        if (row_data == NULL) {
            free(csv->data);
            free(csv);
            return NULL;
        }
        csv->data = row_data;

        char *cell_data = strdup(line);
        row_data[row] = cell_data;

        int cell_len = strlen(cell_data);
        if (cell_len > csv->cols) {
            csv->cols = cell_len;
        }

        row++;
    }

    csv->rows = row;
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSV *csv = csv_read(fp);
    if (csv == NULL) {
        printf("Error reading file.\n");
        return 1;
    }

    csv_print(csv);

    csv_free(csv);
    fclose(fp);

    return 0;
}