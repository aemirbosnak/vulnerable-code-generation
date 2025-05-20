//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1024

int main(int argc, char *argv[]) {
    FILE *file_ptr;
    char buffer[MAX_STR_LEN];
    char *string_ptr;
    char *delim_ptr;
    char *key_ptr;
    char *value_ptr;
    const char *metadata_keys[] = {"title", "artist", "album", "genre", "year"};
    char *metadata_values[sizeof(metadata_keys)/sizeof(metadata_keys[0])];

    // Check the command line arguments
    if (argc != 2) {
        printf("Usage: metadata_extractor file_path\n");
        return 1;
    }

    // Open the file for reading
    file_ptr = fopen(argv[1], "r");
    if (file_ptr == NULL) {
        printf("Error: could not open the file %s\n", argv[1]);
        return 1;
    }

    // Read the file line by line
    while (fgets(buffer, MAX_STR_LEN, file_ptr) != NULL) {
        // Remove trailing newline characters
        if (buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }

        // Look for metadata tags
        string_ptr = buffer;
        while ((string_ptr = strstr(string_ptr, "<meta")) != NULL) {
            delim_ptr = strchr(string_ptr, '>');
            if (delim_ptr == NULL) {
                break;
            }
            *delim_ptr = '\0';

            // Extract the metadata
            key_ptr = strstr(string_ptr, "name=");
            if (key_ptr == NULL) {
                break;
            }
            key_ptr += strlen("name=");
            if (key_ptr[0] == '"' || key_ptr[0] == '\'') {
                key_ptr++;
            }
            value_ptr = strchr(key_ptr, '\0');
            if (value_ptr - key_ptr >= MAX_STR_LEN) {
                break;
            }
            *value_ptr = '\0';
            metadata_values[sizeof(metadata_keys)/sizeof(metadata_keys[0])] = NULL;
            for (int i = 0; i < sizeof(metadata_keys)/sizeof(metadata_keys[0]); i++) {
                if (strcmp(metadata_keys[i], key_ptr) == 0) {
                    metadata_values[i] = (char*) malloc(MAX_STR_LEN * sizeof(char));
                    strncpy(metadata_values[i], value_ptr + 1, MAX_STR_LEN);
                    break;
                }
            }

            // Restore the tag
            *delim_ptr = '>';
            string_ptr = delim_ptr + 1;
        }
    }

    // Print the extracted metadata
    printf("Metadata:\n");
    for (int i = 0; i < sizeof(metadata_keys)/sizeof(metadata_keys[0]); i++) {
        if (metadata_values[i] != NULL) {
            printf("%s: %s\n", metadata_keys[i], metadata_values[i]);
            free(metadata_values[i]);
        }
    }

    // Close the file
    fclose(file_ptr);
    return 0;
}