//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to read a line from the CSV file, splitting it into fields
int readCSVLine(char *line, char ***fields) {
    int fieldCount = 0;
    char *token = strtok(line, ",");
    while (token != NULL) {
        (*fields)[fieldCount] = malloc(strlen(token) + 1);
        strcpy((*fields)[fieldCount], token);
        fieldCount++;
        token = strtok(NULL, ",");
    }
    return fieldCount;
}

// Function to free allocated memory for fields
void freeFields(char **fields, int fieldCount) {
    for (int i = 0; i < fieldCount; i++) {
        free(fields[i]);
    }
}

// Main function to read the CSV file
int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char **fields = malloc(MAX_FIELDS * sizeof(char*));
    
    // Prompt user for the filename
    char filename[256];
    printf("Enter the CSV filename to read: ");
    scanf("%s", filename);
    
    // Attempt to open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        free(fields);
        return EXIT_FAILURE;
    }

    // Read each line from the CSV
    printf("Contents of the CSV file:\n");
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character from the end of line
        line[strcspn(line, "\n")] = '\0';  
        
        // Read fields from the line
        int fieldCount = readCSVLine(line, &fields);
        for (int i = 0; i < fieldCount; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");
        
        // Free allocated memory for fields
        freeFields(fields, fieldCount);
    }
    
    // Cleanup
    fclose(file);
    free(fields);
    
    return EXIT_SUCCESS;
}