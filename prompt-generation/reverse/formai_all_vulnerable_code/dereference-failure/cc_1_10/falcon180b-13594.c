//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 100
#define MAX_LINE 1024

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *csv_create() {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->row = 0;
    csv->col = 0;
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    memset(csv->data, 0, MAX_ROW * sizeof(char *));
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_load(CSV *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return -1;
    }

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            int col = csv->col;
            csv->data[csv->row] = (char *)realloc(csv->data[csv->row], (col + 1) * sizeof(char));
            strcat(csv->data[csv->row], token);
            csv->col++;
            token = strtok(NULL, ",");
        }
        csv->row++;
    }

    fclose(fp);
    return 0;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_create();
    csv_load(csv, "example.csv");
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}