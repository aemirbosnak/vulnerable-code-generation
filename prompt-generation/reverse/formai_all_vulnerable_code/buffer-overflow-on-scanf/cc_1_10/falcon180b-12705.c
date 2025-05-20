//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Function to extract metadata from a file
int extract_metadata(char *filename) {
    FILE *file;
    char line[100];
    int count = 0;

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file is opened successfully
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    // Loop through each line in the file
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Check if the line starts with metadata
        if (strstr(line, "metadata")!= NULL) {
            count++;
        }
    }

    // Close the file
    fclose(file);

    // Return the count of metadata lines
    return count;
}

// Function to print metadata in a formatted way
void print_metadata(char *filename, int count) {
    FILE *file;
    char line[100];
    int i = 0;

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file is opened successfully
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    // Loop through each line in the file
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Check if the line starts with metadata
        if (strstr(line, "metadata")!= NULL) {
            // Print the metadata line with formatting
            printf("%d: %s\n", i+1, line);
            i++;
        }
    }

    // Close the file
    fclose(file);
}

// Main function to take user input and call other functions
int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Extract metadata from the file
    int count = extract_metadata(filename);

    // Print the extracted metadata
    if (count > 0) {
        printf("Metadata found in the file:\n");
        print_metadata(filename, count);
    } else {
        printf("No metadata found in the file.\n");
    }

    return 0;
}