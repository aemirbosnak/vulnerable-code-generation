//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
/*
 * Building a CSV Reader example program in a unmistakable style
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to read a line from the CSV file
char* read_line(FILE* file, char* line) {
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        return NULL;
    }
    return line;
}

// Function to read a field from the CSV file
char* read_field(char* line, char* field) {
    char* comma = strchr(line, ',');
    if (comma == NULL) {
        return NULL;
    }
    strncpy(field, line, comma - line);
    field[comma - line] = '\0';
    return field;
}

int main(void) {
    // Open the CSV file
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: unable to open file\n");
        return 1;
    }

    // Read the first line
    char line[MAX_LINE_SIZE];
    if (read_line(file, line) == NULL) {
        printf("Error: unable to read line\n");
        return 1;
    }

    // Read the first field
    char field[MAX_LINE_SIZE];
    if (read_field(line, field) == NULL) {
        printf("Error: unable to read field\n");
        return 1;
    }

    // Print the field
    printf("Field: %s\n", field);

    // Read the next line
    if (read_line(file, line) == NULL) {
        printf("Error: unable to read line\n");
        return 1;
    }

    // Read the next field
    if (read_field(line, field) == NULL) {
        printf("Error: unable to read field\n");
        return 1;
    }

    // Print the field
    printf("Field: %s\n", field);

    // Close the file
    fclose(file);

    return 0;
}