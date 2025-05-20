//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_COLUMNS 50

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: csvreader FILENAME\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int num_columns = 0;
    char *columns[MAX_NUM_COLUMNS];

    // Read the first line to get the number of columns
    if (fgets(line, MAX_LINE_LENGTH, file)) {
        char *token = strtok(line, ",");
        while (token) {
            if (num_columns >= MAX_NUM_COLUMNS) {
                fprintf(stderr, "Error: too many columns in file\n");
                return 1;
            }

            columns[num_columns++] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    // Read the rest of the file
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char *column_values[MAX_NUM_COLUMNS];
        int num_values = 0;

        char *token = strtok(line, ",");
        while (token) {
            if (num_values >= num_columns) {
                fprintf(stderr, "Error: too many values in row\n");
                return 1;
            }

            column_values[num_values++] = strdup(token);
            token = strtok(NULL, ",");
        }

        // Print the row
        for (int i = 0; i < num_columns; i++) {
            printf("%s: %s\n", columns[i], column_values[i]);
        }

        // Free memory for column values
        for (int i = 0; i < num_values; i++) {
            free(column_values[i]);
        }
    }

    // Free memory for column names
    for (int i = 0; i < num_columns; i++) {
        free(columns[i]);
    }

    fclose(file);
    return 0;
}