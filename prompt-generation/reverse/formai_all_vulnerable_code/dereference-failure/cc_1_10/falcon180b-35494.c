//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_columns = 0;

    char line[MAX_LINE_SIZE];
    char *token = strtok(line, DELIMITER);
    int num_columns_so_far = 0;

    while (token!= NULL) {
        if (num_columns_so_far == MAX_COLUMNS) {
            printf("Error: Too many columns in file %s\n", filename);
            exit(1);
        }

        csv->data = realloc(csv->data, sizeof(char *) * (csv->num_columns + 1));
        csv->data[csv->num_columns] = strdup(token);
        csv->num_columns++;

        num_columns_so_far++;
        token = strtok(NULL, DELIMITER);
    }

    csv->num_rows = num_columns_so_far;

    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_columns; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_num_rows(CSV *csv) {
    return csv->num_rows;
}

int csv_num_columns(CSV *csv) {
    return csv->num_columns;
}

char **csv_get_data(CSV *csv) {
    return csv->data;
}

int main() {
    CSV *csv = csv_open("example.csv");

    int num_rows = csv_num_rows(csv);
    int num_columns = csv_num_columns(csv);

    char **data = csv_get_data(csv);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            printf("%s ", data[j]);
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}