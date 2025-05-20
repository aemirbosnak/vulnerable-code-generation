//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_ROWS 1000
#define MAX_CSV_COLS 1000
#define MAX_CSV_CELL_SIZE 1024

typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_create(void) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->rows = (char **) malloc(MAX_CSV_ROWS * sizeof(char *));
    csv->num_rows = 0;
    csv->num_cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->rows[i]);
    }
    free(csv->rows);
    free(csv);
}

int csv_read(CSV *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return -1;
    }

    char line[MAX_CSV_CELL_SIZE];
    while (fgets(line, MAX_CSV_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col_idx = 0;
        while (token!= NULL) {
            if (csv->num_cols <= col_idx) {
                csv->num_cols++;
            }
            csv->rows[csv->num_rows] = (char *) realloc(csv->rows[csv->num_rows], csv->num_cols * MAX_CSV_CELL_SIZE);
            strcpy(csv->rows[csv->num_rows] + csv->num_cols * MAX_CSV_CELL_SIZE - strlen(token) - 1, token);
            col_idx++;
            token = strtok(NULL, ",");
        }
        csv->num_rows++;
    }

    fclose(fp);
    return 0;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->rows[i] + j * MAX_CSV_CELL_SIZE);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_create();
    csv_read(csv, "example.csv");
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}