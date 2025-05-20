//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char source_file_name[50];
    char destination_file_name[50];

    // Prompt user for source file name
    printf("Enter the source file name: ");
    scanf("%s", source_file_name);

    // Prompt user for destination file name
    printf("Enter the destination file name: ");
    scanf("%s", destination_file_name);

    // Check if source and destination file names are valid
    if (strlen(source_file_name) == 0 || strlen(destination_file_name) == 0) {
        printf("Invalid file names. Please enter valid file names.\n");
        return 1;
    }

    // Check if source and destination file names are different
    if (strcmp(source_file_name, destination_file_name) == 0) {
        printf("Source and destination file names are the same. Please choose different file names.\n");
        return 1;
    }

    // Open source file for reading
    FILE *source_file = fopen(source_file_name, "r");
    if (source_file == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    // Open destination file for writing
    FILE *destination_file = fopen(destination_file_name, "w");
    if (destination_file == NULL) {
        printf("Error opening destination file.\n");
        fclose(source_file);
        return 1;
    }

    // Read source file line by line
    char line[100];
    while (fgets(line, sizeof(line), source_file)!= NULL) {
        // Check if the line is not empty
        if (strlen(line) > 0) {
            // Write the line to the destination file
            fprintf(destination_file, "%s\n", line);
        }
    }

    // Close source and destination files
    fclose(source_file);
    fclose(destination_file);

    printf("File synchronization completed successfully.\n");

    return 0;
}