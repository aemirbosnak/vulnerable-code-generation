//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This program will extract metadata from a file in the following format:
 * length=36,type=mp3,artist=John Doe,title=My Song,filename=my_song.mp3
 * It will print the extracted values to standard output.
 */

int main(int argc, char *argv[]) {
    // Make sure a filename was provided
    if (argc < 2) {
        printf("Please provide a filename as a command-line argument.\n");
        return 1;
    }

    // Open the file in read mode
    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Unable to open file %s.\n", argv[1]);
        return 1;
    }

    // Set up variables to hold the metadata values
    char *length = NULL;
    char *type = NULL;
    char *artist = NULL;
    char *title = NULL;
    char *filename = NULL;

    // Read each line of the file
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Strip the newline character from the end of the line
        line[strcspn(line, "\n")] = 0;

        // Split the line by comma
        char *token = strtok(line, ",");
        while (token != NULL) {
            // Get the key and value of the field
            char *equal = strchr(token, '=');
            if (equal == NULL) {
                printf("Malformed metadata field %s in file %s.\n", token, argv[1]);
                return 1;
            }
            char *key = token;
            char *value = equal + 1;
            *equal = 0; // Replace the equal sign with a null terminator to separate key and value

            // Store the value in the appropriate variable
            if (strcmp(key, "length") == 0) {
                length = value;
            } else if (strcmp(key, "type") == 0) {
                type = value;
            } else if (strcmp(key, "artist") == 0) {
                artist = value;
            } else if (strcmp(key, "title") == 0) {
                title = value;
            } else if (strcmp(key, "filename") == 0) {
                filename = value;
            } else {
                printf("Unknown metadata field %s in file %s.\n", key, argv[1]);
                return 1;
            }

            // Get the next token
            token = strtok(NULL, ",");
        }
    }

    // Close the file
    fclose(file);

    // Print the extracted metadata
    printf("Length: %s\n", length);
    printf("Type: %s\n", type);
    printf("Artist: %s\n", artist);
    printf("Title: %s\n", title);
    printf("Filename: %s\n", filename);

    return 0;
}