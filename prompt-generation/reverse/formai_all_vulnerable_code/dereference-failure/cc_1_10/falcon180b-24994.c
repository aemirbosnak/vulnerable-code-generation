//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold CSV data
typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// Function to read CSV file and store data in struct
CSV* read_csv(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    CSV *csv = (CSV*) malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Split line by comma
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }

        // Allocate memory for data array
        csv->cols = cols;
        csv->data = (char**) realloc(csv->data, csv->rows * csv->cols * sizeof(char*));

        // Add line to data array
        int i;
        for (i = 0; i < cols; i++) {
            csv->data[csv->rows * cols + i] = strdup(token);
            token = strtok(NULL, ",");
        }

        csv->rows++;
    }

    fclose(fp);
    return csv;
}

// Function to print CSV data
void print_csv(CSV* csv) {
    int i, j;
    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }
}

// Function to free CSV data
void free_csv(CSV* csv) {
    int i, j;
    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            free(csv->data[i * csv->cols + j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV* csv = read_csv("example.csv");
    print_csv(csv);
    free_csv(csv);
    return 0;
}