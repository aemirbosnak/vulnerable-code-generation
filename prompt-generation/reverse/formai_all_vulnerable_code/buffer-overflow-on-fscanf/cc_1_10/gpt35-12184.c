//FormAI DATASET v1.0 Category: Error handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define custom error enum type
typedef enum {
    NO_ERROR,
    FILE_NOT_FOUND,
    INVALID_INPUT
} error_t;

// Function to simulate file opening
int openFile(const char* filename) {
    int fileData = 0; // Simulated file data
    
    // Try to open file
    FILE* file = fopen(filename, "r");
    
    // If file not found, return error
    if (!file) {
        return FILE_NOT_FOUND;
    }
    
    // Read file data
    if (fscanf(file, "%d", &fileData) != 1) {
        // If unable to read data, return error
        return INVALID_INPUT;
    }
    
    // Close file and return data
    fclose(file);
    return fileData;
}

// Function to handle errors
void handleError(error_t error) {
    switch(error) {
        case FILE_NOT_FOUND:
            printf("Error: Could not find file!\n");
            break;
        case INVALID_INPUT:
            printf("Error: Invalid input in file!\n");
            break;
        default:
            printf("No error found.\n");
    }
}

int main() {
    // Attempt to open file
    int fileData = openFile("data.txt");
    
    // Check for errors and handle them
    if (fileData < 0) {
        handleError(fileData);
        return 1;
    }
    
    // Print file data
    printf("File data: %d\n", fileData);
    
    return 0;
}