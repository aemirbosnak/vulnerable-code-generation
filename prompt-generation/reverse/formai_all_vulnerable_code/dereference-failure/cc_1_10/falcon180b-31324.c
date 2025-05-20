//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col_count = 0;
        while (token!= NULL) {
            col_count++;
            if (csv->num_cols <= 0) {
                csv->num_cols = col_count;
            }
            if (csv->data == NULL) {
                csv->data = (char **)malloc(sizeof(char *) * csv->num_cols);
            } else {
                csv->data = (char **)realloc(csv->data, sizeof(char *) * csv->num_cols);
            }
            csv->data[col_count - 1] = strdup(token);
            token = strtok(NULL, ",");
        }
        csv->num_rows++;
    }
    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_cols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    CSV *csv = csv_open(argv[1]);
    csv_print(csv);
    csv_close(csv);
    return 0;
}