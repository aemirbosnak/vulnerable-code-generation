//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS  100

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 2) {
        printf("Usage: %s [csv_file]\n", argv[0]);
        return 1;
    }

    // Try to open file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    // Allocate memory for a line
    char *line = malloc(sizeof(char) * MAX_LINE_LENGTH);

    // Read header line
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        printf("Error: could not read header line\n");
        return 1;
    }

    // Parse header line into field names
    int num_fields = 0;
    char *fields[MAX_NUM_FIELDS];
    char *field = strtok(line, ",");
    while (field != NULL && num_fields < MAX_NUM_FIELDS) {
        fields[num_fields++] = field;
        field = strtok(NULL, ",");
    }

    // Allocate memory for field values
    char ***data = malloc(sizeof(char**) * MAX_NUM_FIELDS);
    for (int i = 0; i < MAX_NUM_FIELDS; i++) {
        data[i] = malloc(sizeof(char*) * MAX_NUM_FIELDS);
    }

    // Read data lines
    int row = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Parse line into fields
        int field_index = 0;
        char *field = strtok(line, ",");
        while (field != NULL && field_index < num_fields) {
            data[field_index][row] = field;
            field_index++;
            field = strtok(NULL, ",");
        }
        row++;
    }

    // Print data
    printf("%-10s %-10s %-10s\n", fields[0], fields[1], fields[2]);
    for (int i = 0; i < row; i++) {
        printf("%-10s %-10s %-10s\n", data[0][i], data[1][i], data[2][i]);
    }

    // Deallocate memory
    for (int i = 0; i < MAX_NUM_FIELDS; i++) {
        free(data[i]);
    }
    free(data);
    free(line);

    // Close file
    fclose(fp);

    return 0;
}