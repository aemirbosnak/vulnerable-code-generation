//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, DELIMITER);
        int num_tokens = 0;

        while (token!= NULL) {
            num_tokens++;
            token = strtok(NULL, DELIMITER);
        }

        if (num_tokens > csv->num_cols) {
            csv->num_cols = num_tokens;
        }

        csv->num_rows++;
    }

    csv->data = (char **)malloc(csv->num_rows * sizeof(char *));
    for (int i = 0; i < csv->num_rows; i++) {
        csv->data[i] = (char *)malloc(csv->num_cols * MAX_LINE_LENGTH);
    }

    rewind(fp);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        exit(1);
    }

    char delimiter = argv[2][0];

    CSV *csv = csv_open(argv[1]);
    csv_print(csv);

    csv_close(csv);

    return 0;
}