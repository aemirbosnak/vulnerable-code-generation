//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
/*
 * Example C Program: CSV Reader
 *
 * This program demonstrates how to read a CSV file and store its data in a data structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 10

// Define a structure to store the data of each CSV line
typedef struct {
    char *data[MAX_COLUMNS];
} csv_line_t;

// Define a function to read a CSV file and store its data in a data structure
void read_csv_file(const char *filename, csv_line_t **lines, int *num_lines) {
    // Open the CSV file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read each line of the file and store it in a data structure
    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Ignore empty lines and lines that start with "#"
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }

        // Allocate memory for a new line
        csv_line_t *line_data = (csv_line_t *)malloc(sizeof(csv_line_t));
        if (line_data == NULL) {
            printf("Error allocating memory for line data\n");
            return;
        }

        // Split the line into columns
        char *column = strtok(line, ",");
        int column_num = 0;
        while (column != NULL) {
            // Ignore empty columns
            if (strlen(column) == 0) {
                column = strtok(NULL, ",");
                continue;
            }

            // Store the column data in the data structure
            line_data->data[column_num] = strdup(column);
            column = strtok(NULL, ",");
            column_num++;
        }

        // Add the line to the data structure
        lines[line_num] = line_data;
        line_num++;
    }

    // Close the file
    fclose(file);

    // Return the number of lines read
    *num_lines = line_num;
}

// Define a function to print the data in a data structure
void print_csv_data(csv_line_t *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        csv_line_t *line = lines + i;
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (line->data[j] != NULL) {
                printf("%s, ", line->data[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    // Read the CSV file and store its data in a data structure
    csv_line_t *lines = NULL;
    int num_lines = 0;
    read_csv_file("data.csv", &lines, &num_lines);

    // Print the data in the data structure
    print_csv_data(lines, num_lines);

    // Free the memory allocated for the data structure
    for (int i = 0; i < num_lines; i++) {
        csv_line_t *line = lines + i;
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (line->data[j] != NULL) {
                free(line->data[j]);
            }
        }
        free(line);
    }
    free(lines);

    return 0;
}