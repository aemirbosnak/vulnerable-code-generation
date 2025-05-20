//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
// A surrealist CSV reader program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a CSV file and return a 2D array
char** read_csv(const char* filename, int* num_rows, int* num_cols) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Initialize the 2D array
    char** data = NULL;
    *num_rows = 0;
    *num_cols = 0;

    // Read the file line by line
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        // Ignore empty lines
        if (read == 1) {
            continue;
        }

        // Remove the trailing newline character
        line[read - 1] = '\0';

        // Split the line into columns
        char* column = strtok(line, ",");
        while (column != NULL) {
            // Add the column to the array
            data[*num_rows][*num_cols] = strdup(column);
            *num_cols += 1;

            // Move on to the next column
            column = strtok(NULL, ",");
        }

        // Add the row to the array
        data[*num_rows] = malloc(sizeof(char*) * *num_cols);
        *num_rows += 1;

        // Reset the number of columns
        *num_cols = 0;
    }

    // Close the file
    fclose(fp);

    // Return the 2D array
    return data;
}

int main() {
    // Read the CSV file
    int num_rows = 0;
    int num_cols = 0;
    char** data = read_csv("example.csv", &num_rows, &num_cols);

    // Print the 2D array
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s,", data[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < num_rows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}