//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Declare a structure to hold metadata information
struct metadata {
    char *filename;
    char *author;
    char *date_created;
    char *last_modified;
    char *description;
};

// Function to extract metadata from a file
int extract_metadata(char *filename, struct metadata *md) {
    FILE *fp;
    char buffer[1024];
    char *line;
    int line_num = 0;
    int found_filename = 0, found_author = 0, found_date_created = 0, found_last_modified = 0, found_description = 0;

    // Initialize metadata structure to hold extracted information
    md->filename = NULL;
    md->author = NULL;
    md->date_created = NULL;
    md->last_modified = NULL;
    md->description = NULL;

    // Open file in read-only mode
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file '%s': %s\n", filename, strerror(errno));
        return errno;
    }

    // Read file line by line and extract relevant information
    while ((line = fgets(buffer, sizeof(buffer), fp)) != NULL) {
        line_num++;

        // Check for filename metadata in the file
        if (!found_filename && strncasecmp(line, "// FILENAME:", 12) == 0) {
            md->filename = strdup(line + 12);
            md->filename[strcspn(md->filename, "\n")] = '\0'; // Remove newline character
            found_filename = 1;
        }

        // Check for author metadata in the file
        if (!found_author && strncasecmp(line, "// AUTHOR:", 10) == 0) {
            md->author = strdup(line + 10);
            md->author[strcspn(md->author, "\n")] = '\0'; // Remove newline character
            found_author = 1;
        }

        // Check for date created metadata in the file
        if (!found_date_created && strncasecmp(line, "// DATE CREATED:", 16) == 0) {
            md->date_created = strdup(line + 16);
            md->date_created[strcspn(md->date_created, "\n")] = '\0'; // Remove newline character
            found_date_created = 1;
        }

        // Check for last modified metadata in the file
        if (!found_last_modified && strncasecmp(line, "// LAST MODIFIED:", 17) == 0) {
            md->last_modified = strdup(line + 17);
            md->last_modified[strcspn(md->last_modified, "\n")] = '\0'; // Remove newline character
            found_last_modified = 1;
        }

        // Check for description metadata in the file
        if (!found_description && strncasecmp(line, "// DESCRIPTION:", 14) == 0) {
            md->description = strdup(line + 14);
            md->description[strcspn(md->description, "\n")] = '\0'; // Remove newline character
            found_description = 1;
        }

        // Once all metadata has been found, terminate loop early
        if (found_filename && found_author && found_date_created && found_last_modified && found_description) {
            break;
        }
    }

    // Close file handle
    fclose(fp);

    // Check if all metadata was found in the file
    if (!found_filename || !found_author || !found_date_created || !found_last_modified || !found_description) {
        printf("Error: Not all metadata was found in file '%s'!\n", filename);
        return -1;
    }

    // Print extracted metadata to console
    printf("Metadata information found for file '%s':\n", filename);
    printf("Filename: %s\n", md->filename);
    printf("Author: %s\n", md->author);
    printf("Date created: %s\n", md->date_created);
    printf("Last modified: %s\n", md->last_modified);
    printf("Description: %s\n", md->description);

    return 0;
}

int main(int argc, char **argv) {
    // Ensure filename argument is present
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Declare metadata structure and pass to extract_metadata function
    struct metadata md;
    int status = extract_metadata(argv[1], &md);
    if (status != 0) {
        printf("Error extracting metadata from file '%s'!\n", argv[1]);
        return 1;
    }

    return 0;
}