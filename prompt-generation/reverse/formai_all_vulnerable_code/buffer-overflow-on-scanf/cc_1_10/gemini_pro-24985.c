//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Antivirus scanner function
int scan_file(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    // Read the file into memory
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(size);
    fread(buffer, size, 1, file);
    fclose(file);

    // Scan the file for viruses
    int infected = 0;
    for (int i = 0; i < size; i++) {
        if (buffer[i] == 'V') {
            infected = 1;
            break;
        }
    }

    // Free the buffer
    free(buffer);

    // Return the result
    return infected;
}

// Main function
int main() {
    // Get the filename from the user
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Scan the file
    int infected = scan_file(filename);

    // Print the result
    if (infected) {
        printf("The file %s is infected.\n", filename);
    } else {
        printf("The file %s is clean.\n", filename);
    }

    return 0;
}