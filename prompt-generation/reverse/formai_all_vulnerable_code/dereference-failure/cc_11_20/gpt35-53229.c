//FormAI DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 20

int main(int argc, char **argv) {
	
    if (argc != 3) {
        printf("Usage: data_mining <input_file> <output_file>\n");
        return 0;
    }

    FILE *in_file = fopen(argv[1], "r");
    FILE *out_file = fopen(argv[2], "w");

    if (!in_file || !out_file) {
        printf("Error: Unable to open file.\n");
        return 0;
    }

    // Read the column headers
    char *line = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    char **header;
    header = (char**)malloc(MAX_NUM_COLUMNS * sizeof(char*));
    fgets(line, MAX_LINE_LENGTH, in_file);
    int num_columns = 0;
    char *token = strtok(line, ",");
    while (token != NULL && num_columns < MAX_NUM_COLUMNS) {
        header[num_columns] = strdup(token);
        num_columns++;
        token = strtok(NULL, ",");
    }

    // Check if there are any columns
    if (num_columns == 0) {
        printf("Error: No columns found.\n");
        return 0;
    }

    // Read data and write to output file
    while (fgets(line, MAX_LINE_LENGTH, in_file)) {
        char *data[MAX_NUM_COLUMNS];
        int index = 0;
        token = strtok(line, ",");
        while (token != NULL && index < num_columns) {
            data[index] = strdup(token);
            index++;
            token = strtok(NULL, ",");
        }

        // Check if the number of columns in the row is correct
        if (index != num_columns) {
            printf("Error: Invalid row.\n");
            return 0;
        }

        // Write the data to the output file
        for (int i = 0; i < num_columns; i++) {
            fprintf(out_file, "%s, ", header[i]);
            fprintf(out_file, "%s\n", data[i]);
        }

        // Free the memory allocated for the row data
        for (int i = 0; i < num_columns; i++) {
            free(data[i]);
        }
    }

    // Free the memory allocated for the column headers
    for (int i = 0; i < num_columns; i++) {
        free(header[i]);
    }

    fclose(in_file);
    fclose(out_file);

    return 0;
}