//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: csvreader <filename>\n");
        return 1;
    }
    
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }
    
    char line[MAX_LINE_SIZE];
    int line_counter = 0;
    int field_count = 0;
    char** headers = NULL;
    char*** data = NULL;
    
    // Read the CSV headers and determine the number of fields
    fgets(line, MAX_LINE_SIZE, file);
    char* field = strtok(line, ",");
    while (field != NULL) {
        headers = realloc(headers, (field_count + 1) * sizeof(char*));
        headers[field_count] = malloc(strlen(field) + 1);
        strcpy(headers[field_count], field);
        field_count++;
        field = strtok(NULL, ",");
    }
    
    // Read the rest of the CSV data
    data = malloc(sizeof(char**) * MAX_LINE_SIZE);
    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        char** fields = malloc(sizeof(char*) * field_count);
        field = strtok(line, ",");
        int i = 0;
        while (field != NULL && i < field_count) {
            fields[i] = malloc(strlen(field) + 1);
            strcpy(fields[i], field);
            i++;
            field = strtok(NULL, ",");
        }
        data[line_counter] = fields;
        line_counter++;
    }
    
    // Print the data
    printf("Number of lines: %d\n", line_counter);
    printf("Number of fields: %d\n", field_count);
    printf("Headers: ");
    for (int i = 0; i < field_count; i++) {
        printf("%s ", headers[i]);
    }
    printf("\n");
    for (int i = 0; i < line_counter; i++) {
        for (int j = 0; j < field_count; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }
    
    // Free dynamically allocated memory
    for (int i = 0; i < field_count; i++) {
        free(headers[i]);
    }
    free(headers);
    for (int i = 0; i < line_counter; i++) {
        for (int j = 0; j < field_count; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
    
    return 0;
}