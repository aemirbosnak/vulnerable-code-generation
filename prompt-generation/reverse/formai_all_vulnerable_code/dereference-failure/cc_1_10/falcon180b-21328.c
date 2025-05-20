//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_FIELD_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp;
    char line[MAX_FIELD_SIZE];
    char **header = NULL;
    int rows = 0;
    int cols = 0;
    CSV *csv = (CSV *)malloc(sizeof(CSV));

    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_FIELD_SIZE, fp)!= NULL) {
        int i = 0;
        char *token = strtok(line, ",");

        if (header == NULL) {
            header = (char **)malloc(sizeof(char *) * cols);
            while (token!= NULL) {
                header[cols - 1] = token;
                cols++;
                token = strtok(NULL, ",");
            }
            csv->cols = cols;
        } else {
            rows++;
        }
    }

    csv->data = (char **)malloc(sizeof(char *) * rows);
    rewind(fp);

    for (int i = 0; i < rows; i++) {
        csv->data[i] = (char *)malloc(sizeof(char) * MAX_FIELD_SIZE);
        fgets(csv->data[i], MAX_FIELD_SIZE, fp);
    }

    fclose(fp);

    return csv;
}

void csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    int i;

    for (i = 0; i < csv->rows; i++) {
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