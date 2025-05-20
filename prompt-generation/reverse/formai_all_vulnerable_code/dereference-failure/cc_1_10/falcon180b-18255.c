//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

// Struct to store CSV data
typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// Function to create a new CSV object
CSV *csv_create() {
    CSV *csv = (CSV*) malloc(sizeof(CSV));
    csv->data = (char**) malloc(MAX_ROWS * sizeof(char*));
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

// Function to destroy a CSV object
void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

// Function to read CSV data from a file
CSV *csv_read(FILE *fp) {
    CSV *csv = csv_create();
    char line[4096];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            csv->cols++;
            csv->data = (char**) realloc(csv->data, csv->rows * sizeof(char*));
            csv->data[csv->rows] = (char*) malloc(strlen(token) + 1);
            strcpy(csv->data[csv->rows], token);
            token = strtok(NULL, ",");
            csv->rows++;
        }
    }
    return csv;
}

// Function to print CSV data
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
        printf("Error: Could not open file.\n");
        return 1;
    }
    CSV *csv = csv_read(fp);
    fclose(fp);
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}