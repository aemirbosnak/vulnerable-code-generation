//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char delimiter;
    int num_rows;
    int num_cols;
    char **data;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->delimiter = ',';
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = NULL;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        csv->num_rows++;
        int col_count = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            col_count++;
            token = strtok(NULL, ",");
        }
        if (col_count > csv->num_cols) {
            csv->num_cols = col_count;
        }
    }

    csv->data = malloc(csv->num_rows * sizeof(char *));
    for (int i = 0; i < csv->num_rows; i++) {
        csv->data[i] = malloc(csv->num_cols * MAX_CELL_SIZE);
    }

    rewind(fp);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s", csv->data[i][j]);
            if (j < csv->num_cols - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        return 1;
    }

    CSV *csv = csv_open(argv[1]);
    csv->delimiter = argv[2][0];

    csv_print(csv);

    csv_close(csv);

    return 0;
}