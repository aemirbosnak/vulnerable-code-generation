//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to extract metadata from a given file
void extract_metadata(FILE *file, char *filename) {
    char line[1024];
    char *metadata = NULL;
    size_t metadata_len = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "Title:")!= NULL) {
            metadata = strstr(line, "Title:");
            metadata += strlen("Title:");
            while (isspace(*metadata)) {
                metadata++;
            }
            metadata_len = strlen(metadata);
            break;
        }
    }

    if (metadata!= NULL) {
        printf("File: %s\n", filename);
        printf("Metadata:\nTitle: ");
        printf("%s\n", metadata);
        printf("Length: %zu\n", metadata_len);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char *filename = strrchr(argv[1], '/');
    if (filename == NULL) {
        filename = argv[1];
    } else {
        filename++;
    }

    extract_metadata(file, filename);

    fclose(file);
    return 0;
}