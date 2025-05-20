//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        if (csv->data == NULL) {
            csv->num_cols = 0;
            while (token!= NULL) {
                csv->num_cols++;
                token = strtok(NULL, ",");
            }
            csv->data = calloc(csv->num_cols, sizeof(char *));
        }
        int i;
        for (i = 0; i < csv->num_cols; i++) {
            csv->data[i] = strdup(token);
            token = strtok(NULL, ",");
        }
        csv->num_rows++;
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    int i;
    for (i = 0; i < csv->num_cols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);
    return 0;
}