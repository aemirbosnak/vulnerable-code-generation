//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
/*
 * csvreader.c - A portable C program for reading CSV files
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns and rows in the CSV file
#define MAX_COLUMNS 100
#define MAX_ROWS 1000

// Define the delimiter used in the CSV file
#define DELIMITER ','

// Define the structure to store the CSV data
struct csv_data {
    char** columns;
    int num_columns;
    int num_rows;
};

// Function to read a CSV file and store the data in a struct
struct csv_data read_csv(const char* filename) {
    struct csv_data data;
    data.columns = malloc(MAX_COLUMNS * sizeof(char*));
    data.num_columns = 0;
    data.num_rows = 0;

    // Open the CSV file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return data;
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, 1024, fp) == NULL) {
        printf("Error: Could not read from file %s\n", filename);
        fclose(fp);
        return data;
    }

    // Split the first line into columns
    char* column = strtok(line, DELIMITER);
    while (column != NULL) {
        data.columns[data.num_columns] = strdup(column);
        data.num_columns++;
        column = strtok(NULL, DELIMITER);
    }

    // Read the remaining lines of the file
    while (fgets(line, 1024, fp) != NULL) {
        // Split the line into columns
        column = strtok(line, DELIMITER);
        while (column != NULL) {
            data.columns[data.num_columns] = strdup(column);
            data.num_columns++;
            column = strtok(NULL, DELIMITER);
        }

        // Increment the number of rows
        data.num_rows++;
    }

    // Close the file
    fclose(fp);

    // Return the CSV data
    return data;
}

// Function to print the CSV data
void print_csv(struct csv_data data) {
    for (int i = 0; i < data.num_rows; i++) {
        for (int j = 0; j < data.num_columns; j++) {
            printf("%s ", data.columns[j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    // Check if the filename was provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the CSV file
    struct csv_data data = read_csv(argv[1]);

    // Print the CSV data
    print_csv(data);

    // Free the memory allocated for the columns
    for (int i = 0; i < data.num_columns; i++) {
        free(data.columns[i]);
    }
    free(data.columns);

    return 0;
}