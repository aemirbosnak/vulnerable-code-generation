//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 1000
#define MAX_FIELDS_PER_LINE 100

int main() {
    char filepath[100];
    char *token, *line;
    int row_count = 0;
    int field_count = 0;
    char **field_values;

    printf("Enter filepath for CSV file: ");
    scanf("%s", filepath);

    FILE *csv_file = fopen(filepath, "r");

    if (csv_file == NULL) {
        printf("Error: unable to open file '%s'\n", filepath);
        return 1;
    }

    // Allocate memory for array of field values
    field_values = (char**) malloc(sizeof(char*) * MAX_FIELDS_PER_LINE);
    for (int i = 0; i < MAX_FIELDS_PER_LINE; i++) {
        field_values[i] = (char*) malloc(sizeof(char) * MAX_CHARS_PER_LINE);
    }

    // Read each line of the CSV file
    while ((line = fgets(field_values[field_count], MAX_CHARS_PER_LINE, csv_file)) != NULL) {
        field_count = 0;

        // Tokenize the line based on commas
        while ((token = strsep(&line, ",")) != NULL) {
            if (strlen(token) > 0) {
                // Remove newline character from last field value
                if (token[strlen(token)-1] == '\n') {
                    token[strlen(token)-1] = '\0';
                }

                // Copy the field value into the field_values array
                strcpy(field_values[field_count], token);
                field_count++;
            }
        }

        // Process the field values for the current line
        if (row_count == 0) { // First row contains column headers
            // Print the column headers
            for (int i = 0; i < field_count; i++) {
                printf("%s\t", field_values[i]);
            }
            printf("\n");
        } else {
            // Print the field values for the current row
            for (int i = 0; i < field_count; i++) {
                printf("%s\t", field_values[i]);
            }
            printf("\n");
        }

        row_count++;
    }

    // Free memory for array of field values
    for (int i = 0; i < MAX_FIELDS_PER_LINE; i++) {
        free(field_values[i]);
    }
    free(field_values);

    fclose(csv_file);

    return 0;
}