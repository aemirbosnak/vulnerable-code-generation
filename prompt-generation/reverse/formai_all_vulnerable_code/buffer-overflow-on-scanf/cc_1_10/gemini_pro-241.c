//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCAN_SIZE 1024 * 1024

int main() {
    // Get the file name from the user.
    char filename[256];
    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    // Open the file.
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s.\n", filename);
        return EXIT_FAILURE;
    }

    // Get the file size.
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the file contents.
    char *file_contents = malloc(file_size);
    if (file_contents == NULL) {
        printf("Error allocating memory for file contents.\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the file contents into memory.
    fread(file_contents, file_size, 1, fp);
    fclose(fp);

    // Scan the file contents for viruses.
    int virus_found = 0;
    for (int i = 0; i < file_size; i++) {
        if (file_contents[i] == 'V') {
            virus_found = 1;
            break;
        }
    }

    // Print the results of the scan.
    if (virus_found) {
        printf("Virus found in file %s.\n", filename);
    } else {
        printf("No virus found in file %s.\n", filename);
    }

    // Free the memory allocated for the file contents.
    free(file_contents);

    return EXIT_SUCCESS;
}