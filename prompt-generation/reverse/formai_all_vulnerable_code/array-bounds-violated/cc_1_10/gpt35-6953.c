//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

void print_table(char** table, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%s\t", table[i*cols+j]);
        }
        printf("\n");
    }
}

int count_rows(FILE* file) {
    int count = 0;
    char line[MAX_LINE_SIZE];
    while(fgets(line, MAX_LINE_SIZE, file) != NULL) {
        count++;
    }
    // Reset file pointer to beginning
    fseek(file, 0, SEEK_SET);
    return count;
}

int count_cols(char* line) {
    int count = 1;
    for(int i = 0; line[i] != '\0'; i++) {
        if(line[i] == ',') {
            count++;
        }
    }
    return count;
}

void free_table(char** table, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            free(table[i*cols+j]);
        }
        free(table[i]);
    }
    free(table);
}

char** read_csv(FILE* file, int* rows, int* cols) {
    char line[MAX_LINE_SIZE];
    
    // Count rows
    *rows = count_rows(file);
    if(*rows == 0) {
        return NULL;
    }
    
    // Read first line to determine number of columns
    fgets(line, MAX_LINE_SIZE, file);
    *cols = count_cols(line);
    
    // Allocate memory for table
    char** table = (char**)malloc(*rows * sizeof(char*));
    for(int i = 0; i < *rows; i++) {
        table[i] = (char*)malloc(*cols * sizeof(char));
    }
    
    // Store first line in table
    char* token = strtok(line, ",");
    int col = 0;
    while(token != NULL) {
        strcpy(table[col], token);
        col++;
        token = strtok(NULL, ",");
    }
    
    // Read the rest of the file and store in table
    int row = 1;
    while(fgets(line, MAX_LINE_SIZE, file) != NULL) {
        token = strtok(line, ",");
        col = 0;
        while(token != NULL) {
            strcpy(table[row * (*cols) + col], token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }
    
    return table;
}

int main() {
    printf("Welcome to the CSV Reader\n");
    printf("Enter the filename (including path): ");
    
    char filename[MAX_LINE_SIZE];
    fgets(filename, MAX_LINE_SIZE, stdin);
    filename[strlen(filename)-1] = '\0'; // Remove newline character
    
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("ERROR: Could not open file\n");
        return 1;
    }
    
    int rows, cols;
    char** table = read_csv(file, &rows, &cols);
    if(table == NULL) {
        printf("ERROR: Empty file\n");
        return 1;
    }
    
    fclose(file);
    
    printf("\nSuccessfully read CSV file \"%s\"\n", filename);
    printf("Rows: %d, Cols: %d\n", rows, cols);
    printf("Table:\n");
    print_table(table, rows, cols);
    
    free_table(table, rows, cols);
    
    return 0;
}