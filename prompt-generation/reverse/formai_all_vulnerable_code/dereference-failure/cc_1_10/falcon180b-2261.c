//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold CSV data
typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// Function to create a new CSV object
CSV *csv_create() {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

// Function to destroy a CSV object
void csv_destroy(CSV *csv) {
    int i;
    for(i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

// Function to read a CSV file and populate a CSV object
CSV *csv_read_file(const char *filename) {
    FILE *fp;
    char line[1024];
    char delimiter = ',';
    CSV *csv = csv_create();

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read header line
    fgets(line, sizeof(line), fp);
    csv->cols = 1;
    char *token = strtok(line, ",");
    while(token!= NULL) {
        csv->cols++;
        token = strtok(NULL, ",");
    }
    csv->data = (char **)malloc(sizeof(char *) * csv->cols);

    // Read data lines
    int row = 0;
    while(fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, delimiter);
        int col = 0;
        while(token!= NULL) {
            csv->data[col] = token;
            col++;
            token = strtok(NULL, delimiter);
        }
        csv->rows++;
        row++;
    }

    fclose(fp);

    return csv;
}

// Function to print a CSV object
void csv_print(CSV *csv) {
    int i, j;
    for(i = 0; i < csv->rows; i++) {
        for(j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    CSV *csv = csv_read_file("data.csv");
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}