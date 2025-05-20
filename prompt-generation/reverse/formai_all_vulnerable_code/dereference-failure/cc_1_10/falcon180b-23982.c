//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    int num_rows = 0;
    int num_cols = 0;

    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROWS * sizeof(char *));
    csv->num_rows = 0;
    csv->num_cols = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            num_cols++;
            token = strtok(NULL, ",");
        }
        num_rows++;
    }

    rewind(fp);
    csv->num_rows = num_rows;
    csv->num_cols = num_cols;
    csv->data = realloc(csv->data, num_rows * sizeof(char *));

    int i = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            csv->data[i] = strdup(token);
            token = strtok(NULL, ",");
            i++;
        }
    }

    fclose(fp);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            free(csv->data[i * csv->num_cols + j]);
        }
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i * csv->num_cols + j]);
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