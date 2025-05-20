//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NAME_MAX_LEN 100
#define METADATA_DELIM ":"
#define METADATA_MAX_LEN 100

typedef struct {
    char key[METADATA_MAX_LEN];
    char value[METADATA_MAX_LEN];
} Metadata;

int main() {
    char file_name[FILE_NAME_MAX_LEN];
    printf("Enter file name: ");
    scanf("%s", file_name);
    
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    
    char line[METADATA_MAX_LEN];
    bool found_metadata = false;
    Metadata metadata_array[METADATA_MAX_LEN];
    int metadata_count = 0;
    
    while (fgets(line, METADATA_MAX_LEN, file)) {
        // Check if line is metadata
        if (strstr(line, METADATA_DELIM) != NULL) {
            // Extract key and value
            char *key = strtok(line, METADATA_DELIM);
            char *value = strtok(NULL, METADATA_DELIM);
            if (key == NULL || value == NULL) {
                printf("Error: Invalid metadata format.\n");
                return 1;
            }
            // Store in metadata array
            Metadata metadata;
            strcpy(metadata.key, key);
            strcpy(metadata.value, value);
            metadata_array[metadata_count] = metadata;
            metadata_count++;
            found_metadata = true;
        } else if (found_metadata) {
            // Print metadata and stop scanning file
            printf("Metadata found:\n");
            for (int i = 0; i < metadata_count; i++) {
                printf("%s: %s\n", metadata_array[i].key, metadata_array[i].value);
            }
            found_metadata = false;
            break;
        }
    }
    
    if (!found_metadata) {
        printf("No metadata found.\n");
    }
    
    fclose(file);
    return 0;
}