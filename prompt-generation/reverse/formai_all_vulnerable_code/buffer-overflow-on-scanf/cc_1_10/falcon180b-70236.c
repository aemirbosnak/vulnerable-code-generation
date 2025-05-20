//Falcon-180B DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to handle errors
void error_handler(char* message) {
    perror(message);
    exit(1);
}

// Function to check if a file exists
int file_exists(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    fclose(file);
    return 1;
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Check if file exists
    if (!file_exists(filename)) {
        error_handler("File does not exist");
    }

    // Open file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        error_handler("Failed to open file");
    }

    // Read file
    char buffer[100];
    while (fgets(buffer, 100, file)!= NULL) {
        printf("%s", buffer);
    }

    // Close file
    if (fclose(file) == EOF) {
        error_handler("Failed to close file");
    }

    return 0;
}