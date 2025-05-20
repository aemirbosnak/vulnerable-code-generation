//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LEN 256
#define MAX_METADATA_LEN 65536

typedef struct Metadata {
    int num_entries;
    char** keys;
    char** values;
} Metadata;

Metadata* extract_metadata(char* filename) {
    // Open file
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERROR: File does not exist.\n");
        return NULL;
    }

    // Allocate metadata structure
    Metadata* metadata = (Metadata*) malloc(sizeof(Metadata));
    metadata->num_entries = 0;

    // Allocate memory for keys and values
    metadata->keys = (char**) malloc(sizeof(char*) * MAX_METADATA_LEN);
    metadata->values = (char**) malloc(sizeof(char*) * MAX_METADATA_LEN);

    int curr_index = 0;
    int num_chars = 0;
    char curr_key[MAX_METADATA_LEN];
    char curr_value[MAX_METADATA_LEN];
    curr_key[0] = '\0';
    curr_value[0] = '\0';

    // Loop through file
    while (!feof(fp) && curr_index < MAX_METADATA_LEN) {
        char curr_char = fgetc(fp);
        if (isspace(curr_char)) { // Ignore whitespace
            continue;
        } else if (curr_char == '#') { // Comment line, ignore
            while (!feof(fp) && curr_char != '\n') {
                curr_char = fgetc(fp);
            }
            continue;
        } else if (curr_char == '=') { // Key-value separator
            if (curr_key[0] == '\0') { // Error, no key was found before separator
                printf("ERROR: No key found before separator on line %d.\n", curr_index + 1);
                free(metadata->keys);
                free(metadata->values);
                free(metadata);
                fclose(fp);
                return NULL;
            } else { // Add key-value pair to metadata
                metadata->keys[metadata->num_entries] = (char*) malloc(sizeof(char) * (strlen(curr_key) + 1));
                strcpy(metadata->keys[metadata->num_entries], curr_key);
                metadata->values[metadata->num_entries] = (char*) malloc(sizeof(char) * (strlen(curr_value) + 1));
                strcpy(metadata->values[metadata->num_entries], curr_value);
                metadata->num_entries++;
                curr_key[0] = '\0';
                curr_value[0] = '\0';
                num_chars = 0;
            }
        } else if (curr_char == '\n') { // End of line
            if (curr_key[0] != '\0' || curr_value[0] != '\0') { // Incomplete key-value pair
                printf("ERROR: Incomplete key-value pair on line %d.\n", curr_index + 1);
                free(metadata->keys);
                free(metadata->values);
                free(metadata);
                fclose(fp);
                return NULL;
            }
            curr_index++;
        } else { // Add character to key or value
            if (curr_key[0] == '\0') {
                if (isalpha(curr_char) || curr_char == '_') { // Key can only start with letter or underscore
                    curr_key[num_chars] = curr_char;
                    curr_key[num_chars+1] = '\0';
                    num_chars++;
                } else { // Invalid character in key
                    printf("ERROR: Invalid key on line %d.\n", curr_index + 1);
                    free(metadata->keys);
                    free(metadata->values);
                    free(metadata);
                    fclose(fp);
                    return NULL;
                }
            } else {
                curr_value[num_chars] = curr_char;
                curr_value[num_chars+1] = '\0';
                num_chars++;
            }
        }
    }

    fclose(fp);

    return metadata;
}

int main() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);

    Metadata* metadata = extract_metadata(filename);

    if (metadata == NULL) {
        printf("Metadata extraction failed.\n");
    } else {
        printf("Metadata extracted successfully.\n");
        printf("Number of entries: %d\n", metadata->num_entries);
        for (int i = 0; i < metadata->num_entries; i++) {
            printf("%s = %s\n", metadata->keys[i], metadata->values[i]);
        }
    }

    return 0;
}