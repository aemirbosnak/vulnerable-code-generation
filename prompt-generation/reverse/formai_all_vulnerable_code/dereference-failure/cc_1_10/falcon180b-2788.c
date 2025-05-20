//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_LINE_SIZE 1024 // Maximum size of a CSV line
#define MAX_CSV_COLUMNS 100 // Maximum number of columns in a CSV file
#define MAX_CSV_ROWS 1000 // Maximum number of rows in a CSV file

typedef struct {
    char **data; // Pointer to an array of strings representing the CSV data
    int num_rows; // Number of rows in the CSV data
    int num_cols; // Number of columns in the CSV data
} CSV;

// Function to read a CSV file and return a CSV struct
CSV *read_csv(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_CSV_LINE_SIZE];
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    // Read the first line to determine the number of columns
    if (fgets(line, MAX_CSV_LINE_SIZE, fp) == NULL) {
        printf("Error: Could not read first line of file %s\n", filename);
        exit(1);
    }
    char *token = strtok(line, ",");
    while (token!= NULL) {
        csv->num_cols++;
        token = strtok(NULL, ",");
    }
    rewind(fp);

    // Allocate memory for the CSV data
    csv->data = (char **) malloc(csv->num_cols * sizeof(char *));
    for (int i = 0; i < csv->num_cols; i++) {
        csv->data[i] = NULL;
    }

    // Read the CSV data
    while (fgets(line, MAX_CSV_LINE_SIZE, fp)!= NULL) {
        csv->num_rows++;
        char *token = strtok(line, ",");
        for (int i = 0; i < csv->num_cols; i++) {
            if (i == 0) {
                csv->data[i] = token;
            } else {
                csv->data[i] = realloc(csv->data[i], strlen(token) + 1);
                strcat(csv->data[i], token);
            }
        }
    }

    fclose(fp);
    return csv;
}

// Function to print a CSV struct
void print_csv(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[j]);
        }
        printf("\n");
    }
}

// Function to free memory allocated for a CSV struct
void free_csv(CSV *csv) {
    for (int i = 0; i < csv->num_cols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = read_csv("example.csv");
    print_csv(csv);
    free_csv(csv);
    return 0;
}