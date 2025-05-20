//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 1000

// Function to read the CSV file
void readCSV(char *filename, char **data) {
    FILE *fp;
    char line[MAX_ROW_SIZE];
    int row = 0;
    int col = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_ROW_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            data[row][col++] = token;
            if (col >= MAX_COL_SIZE) {
                printf("Error: row %d exceeds the maximum column size\n", row);
                exit(1);
            }
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    fclose(fp);
}

// Function to print the CSV data
void printCSV(int numRows, int numCols, char **data) {
    int i, j;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the CSV data
void freeCSV(int numRows, int numCols, char **data) {
    int i;
    for (i = 0; i < numRows; i++) {
        free(data[i]);
    }
    free(data);
}

int main() {
    char *filename;
    char **data;
    int numRows, numCols;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Read the CSV file
    readCSV(filename, &data);
    numRows = 0;
    while (data[numRows]!= NULL) {
        numRows++;
    }
    numCols = strlen(data[0]) / strlen(",");

    // Print the CSV data
    printf("CSV Data:\n");
    printCSV(numRows, numCols, data);

    // Free the memory allocated for the CSV data
    freeCSV(numRows, numCols, data);

    return 0;
}