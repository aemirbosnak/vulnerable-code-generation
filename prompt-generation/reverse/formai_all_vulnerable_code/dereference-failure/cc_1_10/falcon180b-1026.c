//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_CSV_COLUMNS 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_parse(FILE *fp) {
    CSV *csv = NULL;
    char line[MAX_LINE_SIZE];
    int rows = 0, cols = 0;

    csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;

        while (token!= NULL) {
            if (i >= MAX_CSV_COLUMNS) {
                printf("Error: Too many columns in CSV file\n");
                exit(1);
            }

            csv->data[rows] = realloc(csv->data[rows], sizeof(char *) * (cols + 1));
            csv->data[rows][cols] = strdup(token);
            cols++;

            token = strtok(NULL, ",");
            i++;
        }

        rows++;
    }

    csv->num_rows = rows;
    csv->num_cols = cols;

    return csv;
}

void csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }

    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = NULL;
    FILE *fp = NULL;

    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open CSV file\n");
        exit(1);
    }

    csv = csv_parse(fp);

    csv_print(csv);

    csv_free(csv);

    fclose(fp);

    return 0;
}