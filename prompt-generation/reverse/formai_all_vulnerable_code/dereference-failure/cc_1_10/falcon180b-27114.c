//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char line[1024];
    int rows = 0;
    int cols = 0;

    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(rows * sizeof(char*));
    csv->rows = rows;
    csv->cols = cols;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        rows++;
    }

    rewind(fp);
    csv->data = realloc(csv->data, rows * sizeof(char*));

    for (int i = 0; i < rows; i++) {
        csv->data[i] = malloc(cols * sizeof(char));
        fgets(line, sizeof(line), fp);
        char *token = strtok(line, ",");
        int j = 0;
        while (token!= NULL) {
            strcpy(csv->data[i] + j, token);
            j += strlen(token) + 1;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}