//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from a file
void extract_metadata(char *filename) {
    FILE *file;
    char ch;
    int count = 0;

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file is opened successfully
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Loop through the file and count the number of lines
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    // Print the number of lines in the file
    printf("Number of lines in %s: %d\n", filename, count);

    // Close the file
    fclose(file);
}

int main() {
    int num_files;
    char filename[100];

    // Prompt the user to enter the number of files
    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    // Loop through each file and extract metadata
    for (int i = 1; i <= num_files; i++) {
        printf("Enter filename %d: ", i);
        scanf("%s", filename);
        extract_metadata(filename);
    }

    return 0;
}