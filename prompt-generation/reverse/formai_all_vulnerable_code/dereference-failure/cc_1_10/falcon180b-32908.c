//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store CSV data
typedef struct {
    char **data; // Pointer to 2D character array to store data
    int rows; // Number of rows in the CSV file
    int cols; // Number of columns in the CSV file
} CSV;

// Function to initialize a CSV structure
CSV *csv_init(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    // Read first line to determine number of columns
    char line[1024];
    fgets(line, sizeof(line), fp);
    char *token = strtok(line, ",");
    while (token!= NULL) {
        csv->cols++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for 2D character array to store data
    csv->data = (char **)malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = (char *)malloc(csv->cols * sizeof(char));
    }

    // Read remaining lines and store data in 2D character array
    rewind(fp);
    int row = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        for (int col = 0; col < csv->cols; col++) {
            strcpy(csv->data[row][col], token);
            token = strtok(NULL, ",");
        }
        row++;
    }

    csv->rows = row;

    return csv;
}

// Function to print CSV data
void csv_print(CSV *csv) {
    for (int row = 0; row < csv->rows; row++) {
        for (int col = 0; col < csv->cols; col++) {
            printf("%s ", csv->data[row][col]);
        }
        printf("\n");
    }
}

// Function to free memory allocated for CSV structure
void csv_free(CSV *csv) {
    for (int row = 0; row < csv->rows; row++) {
        free(csv->data[row]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_init(fp);
    csv_print(csv);
    csv_free(csv);
    fclose(fp);
    return 0;
}