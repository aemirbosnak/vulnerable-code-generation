//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
/*
 * Building a CSV Reader example program in a single-threaded style
 *
 * This program reads a CSV file and outputs its contents to the console
 *
 * Usage: csv_reader <csv_file>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSV_DELIM ','
#define CSV_QUOTE '"'

int main(int argc, char *argv[]) {
    // Check if the file name is passed as an argument
    if (argc < 2) {
        printf("Usage: csv_reader <csv_file>\n");
        return 1;
    }

    // Open the CSV file for reading
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Read the first line of the file to get the number of columns
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, file);
    if (read == -1) {
        printf("Error reading file: %s\n", argv[1]);
        return 1;
    }

    // Parse the first line to get the number of columns
    int num_cols = 0;
    char *token = strtok(line, CSV_DELIM);
    while (token != NULL) {
        num_cols++;
        token = strtok(NULL, CSV_DELIM);
    }

    // Allocate memory for the column headers
    char **headers = malloc(num_cols * sizeof(char *));
    if (headers == NULL) {
        printf("Error allocating memory for headers\n");
        return 1;
    }

    // Parse the first line to get the column headers
    token = strtok(line, CSV_DELIM);
    for (int i = 0; i < num_cols; i++) {
        headers[i] = token;
        token = strtok(NULL, CSV_DELIM);
    }

    // Read the remaining lines of the file
    while (read != -1) {
        // Allocate memory for the current row
        char **row = malloc(num_cols * sizeof(char *));
        if (row == NULL) {
            printf("Error allocating memory for row\n");
            return 1;
        }

        // Parse the current line to get the values
        token = strtok(line, CSV_DELIM);
        for (int i = 0; i < num_cols; i++) {
            row[i] = token;
            token = strtok(NULL, CSV_DELIM);
        }

        // Print the current row
        for (int i = 0; i < num_cols; i++) {
            printf("%s%s", row[i], i < num_cols - 1 ? CSV_DELIM : "\n");
        }

        // Free the memory for the current row
        free(row);

        // Read the next line
        read = getline(&line, &len, file);
    }

    // Free the memory for the column headers
    free(headers);

    // Close the file
    fclose(file);

    return 0;
}