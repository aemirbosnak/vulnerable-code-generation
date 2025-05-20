//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

// Define the structure of a CSV file
typedef struct {
    int row;
    int col;
    char **data;
} CSV;

// Function to initialize the CSV structure
void initCSV(CSV *csv) {
    csv->row = 0;
    csv->col = 0;
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char *)malloc(MAX_COL * sizeof(char));
        memset(csv->data[i], '\0', MAX_COL);
    }
}

// Function to free the memory allocated for the CSV structure
void freeCSV(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
}

// Function to read the CSV file and store the data in the CSV structure
void readCSV(CSV *csv, FILE *fp) {
    char ch;
    int row = 0, col = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            row++;
            col = 0;
        } else if (ch == ',') {
            col++;
        } else {
            csv->data[row][col] = ch;
            col++;
        }
    }
    csv->row = row;
    csv->col = col;
}

// Function to print the CSV data in a formatted manner
void printCSV(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

// Main function to process the CSV file
int main() {
    FILE *fp;
    CSV csv;

    // Open the CSV file
    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Initialize the CSV structure
    initCSV(&csv);

    // Read the CSV data from the file
    readCSV(&csv, fp);

    // Print the CSV data
    printf("CSV Data:\n");
    printCSV(&csv);

    // Free the memory allocated for the CSV structure
    freeCSV(&csv);

    // Close the CSV file
    fclose(fp);

    return 0;
}