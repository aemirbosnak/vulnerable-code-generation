//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum line length
#define MAX_LINE_LENGTH 1024

// Maximum number of columns
#define MAX_NUM_COLUMNS 10

// Structure to store a CSV record
struct csv_record {
    char *data[MAX_NUM_COLUMNS];
    int num_columns;
};

// Function to read a CSV file
struct csv_record *read_csv(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Allocate memory for the CSV record
    struct csv_record *record = malloc(sizeof(struct csv_record));
    if (record == NULL) {
        fprintf(stderr, "Error allocating memory for CSV record\n");
        fclose(fp);
        return NULL;
    }

    // Read the first line of the file
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        fprintf(stderr, "Error reading first line of file\n");
        fclose(fp);
        free(record);
        return NULL;
    }

    // Split the first line into columns
    char *column;
    int num_columns = 0;
    column = strtok(line, ",");
    while (column != NULL) {
        record->data[num_columns] = strdup(column);
        num_columns++;
        column = strtok(NULL, ",");
    }

    // Read the remaining lines of the file
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Split the line into columns
        column = strtok(line, ",");
        int i = 0;
        while (column != NULL) {
            record->data[i] = strdup(column);
            i++;
            column = strtok(NULL, ",");
        }

        // Increment the number of columns
        record->num_columns++;
    }

    // Close the file
    fclose(fp);

    return record;
}

// Function to print a CSV record
void print_csv_record(struct csv_record *record) {
    for (int i = 0; i < record->num_columns; i++) {
        printf("%s", record->data[i]);
        if (i < record->num_columns - 1) {
            printf(",");
        }
    }
    printf("\n");
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the CSV file
    struct csv_record *record = read_csv(argv[1]);
    if (record == NULL) {
        return 1;
    }

    // Print the CSV record
    print_csv_record(record);

    // Free the memory allocated for the CSV record
    for (int i = 0; i < record->num_columns; i++) {
        free(record->data[i]);
    }
    free(record);

    return 0;
}