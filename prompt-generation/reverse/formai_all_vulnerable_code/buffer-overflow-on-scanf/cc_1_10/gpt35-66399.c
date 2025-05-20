//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_LINE_LENGTH 1024
#define MAX_COLUMN_LENGTH 128
#define MAX_NUM_COLUMNS 16

int main() {
    printf("Welcome to the Cyberpunk CSV Reader\n");
    
    // Prompt user for CSV file
    char filename[MAX_COLUMN_LENGTH];
    printf("Enter path to CSV file: ");
    scanf("%s", filename);
    
    // Open the file
    FILE* csv_file = fopen(filename, "r");
    if (!csv_file) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    
    // Allocate memory to store column names
    char* column_names[MAX_NUM_COLUMNS];
    for (int i = 0; i < MAX_NUM_COLUMNS; i++) {
        column_names[i] = malloc(MAX_COLUMN_LENGTH);
    }
    
    // Read the first line to get column names
    char csv_line[MAX_CSV_LINE_LENGTH];
    fgets(csv_line, MAX_CSV_LINE_LENGTH, csv_file);
    int num_columns = 0;
    char* token = strtok(csv_line, ",");
    while (token != NULL) {
        strcpy(column_names[num_columns], token);
        num_columns++;
        token = strtok(NULL, ",");
    }
    
    // Allocate memory to store column values
    char* column_values[MAX_NUM_COLUMNS];
    for (int i = 0; i < MAX_NUM_COLUMNS; i++) {
        column_values[i] = malloc(MAX_COLUMN_LENGTH);
    }
    
    // Read and print the rest of the lines
    while (fgets(csv_line, MAX_CSV_LINE_LENGTH, csv_file)) {
        char* token = strtok(csv_line, ",");
        int i = 0;
        while (token != NULL) {
            strcpy(column_values[i], token);
            i++;
            token = strtok(NULL, ",");
        }
        
        // Print the values
        printf("=====\n");
        for (int j = 0; j < num_columns; j++) {
            printf("%s: %s\n", column_names[j], column_values[j]);
        }
    }
    
    // Free allocated memory
    for (int i = 0; i < MAX_NUM_COLUMNS; i++) {
        free(column_names[i]);
        free(column_values[i]);
    }
    
    fclose(csv_file);
    return 0;
}