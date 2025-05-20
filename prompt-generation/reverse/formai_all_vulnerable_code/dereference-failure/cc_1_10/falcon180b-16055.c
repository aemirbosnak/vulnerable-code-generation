//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define DELIM ","

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSVData;

CSVData *csv_read(FILE *fp) {
    CSVData *csv = malloc(sizeof(CSVData));
    char line[MAX_LINE_SIZE];
    char *token;
    int row = 0, col = 0;

    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        row++;
        csv->num_rows++;
        csv->data = realloc(csv->data, sizeof(char *) * row);
        csv->data[row-1] = strdup(line);

        token = strtok(line, DELIM);
        while (token!= NULL) {
            col++;
            csv->num_cols = col > csv->num_cols? col : csv->num_cols;
            token = strtok(NULL, DELIM);
        }
    }

    csv->data = realloc(csv->data, sizeof(char *) * row);
    csv->num_cols = col;

    return csv;
}

void csv_print(CSVData *csv) {
    int i, j;

    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_free(CSVData *csv) {
    int i;

    for (i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp;
    CSVData *csv;

    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    csv = csv_read(fp);
    csv_print(csv);
    csv_free(csv);

    fclose(fp);
    return 0;
}