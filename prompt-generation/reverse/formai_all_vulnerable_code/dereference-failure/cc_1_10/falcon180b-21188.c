//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_LINE_LEN 10000

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char *token;
    CSV *csv;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROW * sizeof(char *));
    csv->row = 0;
    csv->col = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            csv->data[csv->row][csv->col++] = token;
            if (csv->col >= MAX_COL) {
                csv->row++;
                csv->col = 0;
            }
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);

    return csv;
}

void csv_close(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv;

    csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}