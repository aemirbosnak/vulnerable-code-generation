//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// Recursive function to read CSV file and fill the 2D array
void readCSV(FILE *fp, int row, int col, CSV *csv) {
    char ch;
    char *token = NULL;
    size_t len = 0;

    // Allocate memory for current row
    csv->data[row] = (char **)malloc((col+1) * sizeof(char *));

    // Read each value in the row
    while ((ch = fgetc(fp))!= ',') {
        if (ch == '\n') {
            csv->rows++;
            csv->cols = col;
            return;
        }
        if (token == NULL) {
            token = malloc(len+2);
            len = 0;
        } else {
            token = realloc(token, len+2);
        }
        token[len++] = ch;
    }

    // Add null terminator and store the token
    token[len] = '\0';
    csv->data[row][col] = token;

    // Read next row
    readCSV(fp, row+1, 0, csv);
}

int main() {
    FILE *fp;
    char filename[100];
    CSV csv;

    // Open CSV file
    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Initialize CSV structure
    csv.data = NULL;
    csv.rows = 0;
    csv.cols = 0;

    // Read CSV file
    readCSV(fp, 0, 0, &csv);

    // Print CSV data
    printf("CSV Data:\n");
    for (int i=0; i<csv.rows; i++) {
        for (int j=0; j<csv.cols; j++) {
            printf("%s\t", csv.data[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i=0; i<csv.rows; i++) {
        for (int j=0; j<csv.cols; j++) {
            free(csv.data[i][j]);
        }
        free(csv.data[i]);
    }
    free(csv.data);

    return 0;
}