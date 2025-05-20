//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;

        while (token!= NULL) {
            csv->data[csv->rows] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(csv->data[csv->rows], token);
            csv->cols++;
            csv->rows++;
            token = strtok(NULL, ",");
        }
    }

    csv->data = (char **)realloc(csv->data, csv->rows * sizeof(char *));

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    CSV *csv = csv_create(fp);
    csv_print(csv);

    csv_destroy(csv);
    fclose(fp);

    return 0;
}