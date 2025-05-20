//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024 // Maximum line size for reading CSV file

// Function to read CSV file and return data as 2D array of strings
int **read_csv(FILE *fp, int *rows, int *cols) {
    char line[MAX_LINE_SIZE];
    int i = 0, j = 0;
    int **data = NULL;

    // Read first line to determine number of columns
    fgets(line, MAX_LINE_SIZE, fp);
    *cols = 0;
    while (line[j]!= '\0') {
        if (line[j] == ',') {
            (*cols)++;
        }
        j++;
    }
    rewind(fp);

    // Allocate memory for 2D array of strings
    data = (int **)malloc(*rows * sizeof(int *));
    for (i = 0; i < *rows; i++) {
        data[i] = (int *)malloc(*cols * sizeof(int));
    }

    // Read CSV file into 2D array of strings
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        j = 0;
        while (line[j]!= '\0') {
            if (line[j] == ',') {
                data[i][j] = atoi(line); // Convert string to integer
                j++;
            } else {
                data[i][j] = line[j]; // Copy string
                j++;
            }
        }
        i++;
    }

    return data;
}

// Function to display 2D array of strings
void display_data(int **data, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    FILE *fp;
    int rows, cols;
    int **data;

    // Open CSV file
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open CSV file.\n");
        exit(1);
    }

    // Read CSV file into 2D array of strings
    data = read_csv(fp, &rows, &cols);

    // Display 2D array of strings
    printf("CSV Data:\n");
    display_data(data, rows, cols);

    // Free memory allocated for 2D array of strings
    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);

    // Close CSV file
    fclose(fp);

    return 0;
}